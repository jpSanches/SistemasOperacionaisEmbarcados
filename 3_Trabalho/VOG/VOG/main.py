import os
import cv2
import process
import  numpy as np


def get_keypoints(detector, frame_gray, threshold, prev_keypoint, prev_area):
    """
    Dectect and refresh keypoints
    :param detector: blob Detector
    :param frame_gray: gray eye frame
    :param threshold: threshold for functions
    :param prev_keypoint: previous keypoints
    :param prev_area: previous blob area
    :return: detected keypoints and previous keypoints
    """
    keypoints = process.pupil_detector(frame_gray, threshold, detector, area=prev_area)

    if keypoints:
        prev_keypoint = keypoints
        prev_area = keypoints[0].size
    else:
        keypoints = prev_keypoint

    return keypoints, prev_keypoint, prev_area


def nothing(x):
    """
    Do nothing!
    """
    pass


####################################################################
face_cascade, eye_cascade, blob_detector = process.init_cv()
cap = cv2.VideoCapture(os.path.join("vid", "movie.avi")) #os.path.join("vid", "movie.avi")
cv2.namedWindow('image')

prev_right_keypoints = None
prev_right_blob_area = None
prev_left_keypoints = None
prev_left_blob_area = None

# Threshold for pupil_detector
cv2.createTrackbar('R_threshold', 'image', 0, 255, nothing)
cv2.createTrackbar('L_threshold', 'image', 0, 255, nothing)
r_th = 25
l_th = 28

trim_size = 12  # Pixels to trim in trim_eyebrows function
r_eye_cords = np.zeros(2)
l_eye_cords = np.zeros(2)
prev_r_eye_cords = np.zeros(2)
prev_l_eye_cords = np.zeros(2)
dif_l = np.zeros(2)

# Define the codec and create VideoWriter object
# fourcc = cv2.VideoWriter_fourcc(*'XVID')
# out = cv2.VideoWriter(os.path.join("vid", "out.avi"), fourcc, 20.0, (648,432)) #frame size for scale = 0.6

blank_image = np.zeros((432, 768, 3), np.uint8)
kk = 0

while True:
    ret, frame = cap.read()
    # Avoid error in EOF
    if frame is None:
        break
    # Resizing to increase performance
    scale = 0.6
    frame = cv2.resize(frame, (0, 0), fx=scale, fy=scale)

    #r_th = cv2.getTrackbarPos('R_threshold', 'image')
    #l_th = cv2.getTrackbarPos('L_threshold', 'image')

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray = cv2.equalizeHist(gray)

    face_frame, face_frame_gray, l_est, r_est, X, Y = process.face_detector(frame, gray,
                                                                            face_cascade)
    # Detect eyes if faces is not None
    if face_frame is not None:
        leye_frame, reye_frame, leye_frame_gray, reye_frame_gray, X_eye, Y_eye = process.eye_detector(face_frame,
                                                                                        face_frame_gray,
                                                                                        l_est,
                                                                                        r_est,
                                                                                        eye_cascade,
                                                                                        trim_size)

        if reye_frame is not None:
            right_eye_threshold = r_th

            size_right_eye = (X_eye[1][1], Y_eye[1][1])
            cord_right_eye = (X_eye[1][0], Y_eye[1][0])

            r_keypoints, r_prev_keypoints, r_blob_area = get_keypoints(blob_detector,
                                                                       reye_frame_gray,
                                                                       right_eye_threshold,
                                                                       prev_right_keypoints,
                                                                       prev_right_blob_area)
            if r_keypoints is not None:
                process.blob_draw(reye_frame, r_keypoints)
                cord_r_eye_center = (int(r_keypoints[0].pt[0]), int(r_keypoints[0].pt[1]))
                reye_frame = cv2.drawMarker(reye_frame, cord_r_eye_center, (0, 0, 255), cv2.MARKER_CROSS, 2)

                prev_r_eye_cords[0] = r_eye_cords[0]; prev_r_eye_cords[1] = r_eye_cords[1]
                r_eye_cords[0] = X[0] + cord_right_eye[0] + r_keypoints[0].pt[0]
                r_eye_cords[1] = Y[0] + cord_right_eye[1] + r_keypoints[0].pt[1] + trim_size

        if leye_frame is not None:
            left_eye_threshold = l_th

            size_left_eye = (X_eye[0][1], Y_eye[0][1])
            cord_left_eye = (X_eye[0][0], Y_eye[0][0])

            l_keypoints, l_prev_keypoints, l_blob_area = get_keypoints(blob_detector,
                                                                       leye_frame_gray,
                                                                       left_eye_threshold,
                                                                       prev_left_keypoints,
                                                                       prev_left_blob_area)
            if l_keypoints is not None:
                process.blob_draw(leye_frame, l_keypoints)
                cord_l_eye_center = (int(l_keypoints[0].pt[0]), int(l_keypoints[0].pt[1]))
                leye_frame = cv2.drawMarker(leye_frame, cord_l_eye_center, (0, 0, 255), cv2.MARKER_CROSS, 2)

                prev_l_eye_cords[0] = l_eye_cords[0]; prev_l_eye_cords[1] = l_eye_cords[1]
                l_eye_cords[0] = X[0] + cord_left_eye[0] + l_keypoints[0].pt[0]
                l_eye_cords[1] = Y[0] + cord_left_eye[1] + l_keypoints[0].pt[1] + trim_size

                alpha = 0.92
                beta = 0.92
                dif_l[0] = 10*(l_eye_cords[0] -alpha * prev_l_eye_cords[0])
                dif_l[1] = 10*(l_eye_cords[1] -beta * prev_l_eye_cords[1])
                print('%.2f %.2f' % (dif_l[0], dif_l[1]))
                blank_image = cv2.drawMarker(blank_image, (int(dif_l[0]+200), int(dif_l[1]+200)), (0, 0, 255), cv2.MARKER_CROSS, 2)

    cv2.imshow('image', frame)
    cv2.imshow('test', blank_image)
    if kk == 15:
        kk = 0
        blank_image = np.zeros((432, 768, 3), np.uint8)

    kk = kk + 1
    # out.write(frame) # Record frame to video
    if cv2.waitKey(1) == 13:  # 13 is the Enter Key
        break

cap.release()
cv2.destroyAllWindows()
###################################################################
