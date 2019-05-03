# import os
# import cv2
# from matplotlib import pyplot as plt
# import process
# from main import get_keypoints
#
#
# face_cascade, eye_cascade, blob_detector = process.init_cv()
# frame = cv2.imread(os.path.join("img", "davi_L1.jpg"))
# prev_right_keypoints = None
# prev_right_blob_area = None
# prev_left_keypoints = None
# prev_left_blob_area = None
#
# gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
# gray = cv2.equalizeHist(gray)
# face_frame, face_frame_gray, l_est, r_est, X, Y = process.face_detector(frame, gray,
#                                                                         face_cascade)
#
# trim_size = 12  # Pixels to trim in trim_eyebrows function
#
# # Subplots
# _, axes = plt.subplots(2, 2)
# _, ax2 = plt.subplots()
#
#
# # Detect eyes if faces is not None
# if face_frame is not None:
#     leye_frame, reye_frame, leye_frame_gray, reye_frame_gray, _, _ = process.eye_detector(face_frame,
#                                                                                     face_frame_gray,
#                                                                                     l_est,
#                                                                                     r_est,
#                                                                                     eye_cascade,
#                                                                                     trim_size)
#     if reye_frame is not None:
#         right_eye_threshold = 48
#         r_keypoints, r_prev_keypoints, r_blob_area = get_keypoints(blob_detector,
#                                                                    reye_frame_gray,
#                                                                    right_eye_threshold,
#                                                                    prev_right_keypoints,
#                                                                    prev_right_blob_area)
#         if r_keypoints is not None:
#             process.blob_draw(reye_frame, r_keypoints)
#             cord_r_eye_center = (int(r_keypoints[0].pt[0]), int(r_keypoints[0].pt[1]))
#             reye_frame = cv2.drawMarker(reye_frame, cord_r_eye_center, (0, 0, 255), cv2.MARKER_CROSS, 5)
#
#         process.img_subplt(cv2.cvtColor(reye_frame, cv2.COLOR_BGR2RGB), axes[0][1], 'Right Eye')
#         process.img_subplt(reye_frame_gray, axes[1][1], 'Right Eye Grayscale')
#
#         hist_r = cv2.calcHist([reye_frame_gray], [0], None, [256], [0, 256])
#         ax2.plot(hist_r), ax2.set_title('Histogram Eye')
#
#         #reye_sobel = cv2.Sobel(reye_frame_gray, cv2.CV_64F, 1, 0, ksize=5)
#         #process.img_subplt(reye_sobel, axes[2][1], 'Right Eye Sobel')
#
#     if leye_frame is not None:
#         left_eye_threshold = 50
#         l_keypoints, l_prev_keypoints, l_blob_area = get_keypoints(blob_detector,
#                                                                    leye_frame_gray,
#                                                                    left_eye_threshold,
#                                                                    prev_left_keypoints,
#                                                                    prev_left_blob_area)
#         if l_keypoints is not None:
#             process.blob_draw(leye_frame, l_keypoints)
#             cord_l_eye_center = (int(l_keypoints[0].pt[0]), int(l_keypoints[0].pt[1]))
#             leye_frame = cv2.drawMarker(leye_frame, cord_l_eye_center, (0, 0, 255), cv2.MARKER_CROSS, 5)
#
#         process.img_subplt(cv2.cvtColor(leye_frame, cv2.COLOR_BGR2RGB), axes[0][0], 'Left Eye')
#         process.img_subplt(leye_frame_gray, axes[1][0], 'Left Eye Grayscale')
#
#         hist_l = cv2.calcHist([leye_frame_gray], [0], None, [256], [0, 256])
#         ax2.plot(hist_l)
#
#         #leye_sobel = cv2.Sobel(leye_frame_gray, cv2.CV_64F, 1, 0, ksize=5)
#         #process.img_subplt(leye_sobel, axes[2][0], 'Left Eye Sobel')
# cv2.imshow('face', frame)
# plt.show()
# cv2.waitKey(0)
# cv2.destroyAllWindows()
