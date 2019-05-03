import os
import numpy as np
import cv2
from matplotlib import pyplot as plt

def init_cv():
    """
    Load CV tools
    :return: Face haarcascade, Eye haarcascade and Blob Detector
    """
    face_classifier = cv2.CascadeClassifier(os.path.join("haarcascades",
                                                         "haarcascade_frontalface_default.xml"))
    eye_classifier = cv2.CascadeClassifier(os.path.join("haarcascades", "haarcascade_eye.xml"))
    blob_detector_params = cv2.SimpleBlobDetector_Params()
    blob_detector_params.filterByArea = True
    blob_detector_params.maxArea = 1400
    blob_detector = cv2.SimpleBlobDetector_create(blob_detector_params)
    return face_classifier, eye_classifier, blob_detector


def face_detector(img, img_gray, cascade):
    """
    Detects all faces, selects the biggest.
    :param img: colored img frame
    :param img_gray: gray img frame
    :param cascade: Haar cascade
    :return: Face frame, Gray frame, Estimated left and right eye coords and X,Y of face
    """
    faces = cascade.detectMultiScale(img_gray, scaleFactor=1.3, minNeighbors=4, minSize=(30, 30),
                                     flags=cv2.CASCADE_SCALE_IMAGE)
    if len(faces) > 1:
        biggest = (0, 0, 0, 0)
        for i in faces:
            if i[3] > biggest[3]: # Compare w in faces
                biggest = i
        biggest = np.array([i], np.int32)
    elif len(faces) == 1: # 1 face in the frame
        biggest = faces
    else: # No faces in the frame
        return None, None, None, None, None, None

    for (x, y, w, h) in biggest:
        frame = img[y:y + h, x:x + w]
        frame_gray = img_gray[y:y + h, x:x + w]
        l_est = (int(w * 0.1), int(w * 0.45))
        r_est = (int(w * 0.55), int(w * 0.9))
        X = [x, w]
        Y = [y, h]

    return frame, frame_gray, l_est, r_est, X, Y


def eye_detector(img, img_gray, l_est, r_est, cascade, trim_size):
    """
    Detects eyes in faces
    :param img: image frame
    :param img_gray: gray image frame
    :param l_est: left eye estimated pos
    :param r_est: right eye estimated pos
    :param cascade: Haarcascade
    :param trim_size: Pixels to trim in trim_eyebrows function
    :return: Left eye frame, Right eye frame, Left eye gray frame, Right eye gray frame, X and Y coords
    """
    left_eye = left_eye_gray = right_eye = right_eye_gray = x_left = x_right = y_left = y_right = None
    eyes = cascade.detectMultiScale(img_gray, 1.3, 5)

    if eyes is None or len(eyes) == 0:
        pass
    else:
        for (x, y, w, h) in eyes:
            eye_center = int(float(x) + (float(w) / 2))
            if eye_center > l_est[0] and eye_center < l_est[1]:
                left_eye = img[y:y + h, x:x + w]
                left_eye_gray = img_gray[y:y + h, x:x + w]
                x_left = [x, w]
                y_left = [y, h-trim_size]
                left_eye, left_eye_gray = trim_eyebrows(left_eye, left_eye_gray, trim_size)
            elif eye_center > r_est[0] and eye_center < r_est[1]:
                right_eye = img[y:y + h, x:x + w]
                right_eye_gray = img_gray[y:y + h, x:x + w]
                right_eye, right_eye_gray = trim_eyebrows(right_eye, right_eye_gray, trim_size)
                x_right = [x, w]
                y_right = [y, h-trim_size]
            else:
                pass
    X = [x_left, x_right]
    Y = [y_left, y_right]
    return left_eye, right_eye, left_eye_gray, right_eye_gray, X, Y


def pupil_detector(img, threshold, detector, area=None):
    """
    Process eye to detect pupil using blob detector
    :param img: eye frame
    :param threshold: threshold value to functions
    :param detector: blob detector
    :param area: previous keypoints
    """
    _, ax = plt.subplots(1, 5)
    img = cv2.GaussianBlur(img, (5,5), 0)
    img_subplt(img, ax[0], 'Original & Blur')
    _, img = cv2.threshold(img, threshold, 255, cv2.THRESH_BINARY)
    img_subplt(img, ax[1], 'Binary')
    img = cv2.erode(img, None, iterations=3)
    img_subplt(img, ax[2], 'Erode')
    img = cv2.dilate(img, None, iterations=4)
    img_subplt(img, ax[3], 'Dilate')
    img = cv2.medianBlur(img, 5)
    img = cv2.erode(img, None, iterations=1)
    img_subplt(img, ax[4], 'Blur & Erode')
    
    keypoints = detector.detect(img)
    if keypoints and area and len(keypoints) > 1:
        i = 1000
        for keypoint in keypoints: # discard weird blobs
            if abs(keypoint.size - area) < i:
                answer = keypoint
                i = abs(keypoint.size - area)
        keypoints = np.array(answer)

    return keypoints


def trim_eyebrows(img, img_gray, pixels=12):
    """
    Trim eyebrows in eye frame
    :param img: Eye frame
    :param img_gray: Eye gray frame
    :param pixels: Pixels to trim
    :return: Colored eye frame, Gray eye frame
    """
    height, width = img.shape[:2]
    img = img[pixels:height, 0:width]
    img_gray = img_gray[pixels:height, 0:width]
    return img, img_gray


def blob_draw(img, keypoints):
    """
    Draws Blobs based on keypoints
    :param img: image frame
    :param keypoints: keypoints from blob detector
    :return: None
    """
    cv2.drawKeypoints(img, keypoints, img, (0, 0, 255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)


def img_subplt(img, axe, title):
    """
    Plot images in subplot with ease. Avoid verbose lines!
    :param img: Image to show
    :param axe: Axe used in subplot
    :param title: Title of the Axe
    """
    if img.shape.__len__ == 3:
        axe.imshow(img)
    else:
        axe.imshow(img, cmap='gray')
    axe.set_title(title)
    pass
