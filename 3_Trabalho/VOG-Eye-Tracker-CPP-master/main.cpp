#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Function Headers **/
void init_cv();
void get_keypoints(Mat eye_ROI, double thresh, vector<KeyPoint>& keypoints, vector<KeyPoint>& prev_keypoint, float& prev_area);
void mouse_move(int dir);
int face_detector(Mat& frame_gray, Mat& face_ROI, Rect& face_coords, Point& lest, Point& rest);
int eye_detector(Mat face_ROI, Mat& l_eye, Mat& r_eye, Rect& l_eye_coords, Rect& r_eye_coords, Point lest, Point rest, int trim_size);
int pupil_detector(Mat eye_ROI, double thresh, float area, vector<KeyPoint>& pupil_keypoint);
Point stabilize_eye_centers(vector<Point>& eye_points, int win_size);

/** Global Variables **/
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
SimpleBlobDetector::Params params;
Ptr<SimpleBlobDetector> detector;

/** @function main **/
int main(int argc, char** argv)
{
    init_cv(); // Load CV tools
    
    VideoCapture capture;
    capture.open(0 + CAP_ANY);
    if(!capture.isOpened())
    {
        cerr << "(!) Error opening video\n";
        exit(-1);
    }

    Mat frame, frame_gray, face_ROI, face_ROI_color, l_eye, r_eye, crop_left_eye, crop_right_eye;
    Point lest, rest, eye_scenter, prev_center, diff_center, min_coords(100,0), max_coords;
    Rect l_eye_coords, r_eye_coords, face_coords;
    vector<KeyPoint> l_eye_keypoints, r_eye_keypoints, r_eye_prev_keypoints, l_eye_prev_keypoints;
    vector<Point> eye_points;
    double t = 0;
    float r_prev_area = 0;
    float l_prev_area = 0;
    int trim_size = 10;
    int e_detect, f_detect;
    int l_thresh = 23;
    int r_thresh = 25;
    
    namedWindow("MAIN WINDOW", 1);
    createTrackbar("L threshold", "MAIN WINDOW", &l_thresh, 255);
    createTrackbar("Dir threshold", "MAIN WINDOW", &r_thresh, 50);

    while(capture.read(frame))
    {
        t = (double)getTickCount();
        if (frame.empty())
        {
            cerr << "(!) No captured frame";
            exit(1);
        }
        // Resizing to increase performance
        double scale = 0.85;
        resize(frame, frame, Size(), scale, scale, INTER_AREA);
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        // Detect faces
        f_detect = face_detector(frame_gray, face_ROI, face_coords, lest, rest);
        if (f_detect != -1)
        {
            face_ROI_color = frame(face_coords);
            rectangle(frame, face_coords.tl(), face_coords.br(), cv::Scalar(255, 0, 0), 2);

            e_detect = eye_detector(face_ROI, l_eye, r_eye, l_eye_coords, r_eye_coords, lest, rest, trim_size);
            if (e_detect != -1)
            {
                //Get Keypoints for right eye
                //get_keypoints(r_eye, (double) r_thresh, r_eye_keypoints, r_eye_prev_keypoints, r_prev_area);
                //if (!r_eye_keypoints.empty())
                //{
                    //crop_right_eye = frame(face_coords);
                    //crop_right_eye = crop_right_eye(r_eye_coords);
                    //drawKeypoints(crop_right_eye, r_eye_keypoints, crop_right_eye, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
                    //drawKeypoints(r_eye, r_eye_keypoints, r_eye, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

                    //imshow("R eye", r_eye);
                //}

                // Get Keypoints for left eye
                get_keypoints(l_eye, (double) l_thresh, l_eye_keypoints, l_eye_prev_keypoints, l_prev_area);
                if (!l_eye_keypoints.empty())
                {
                    crop_left_eye = frame(face_coords);
                    crop_left_eye = crop_left_eye(l_eye_coords);
                    drawKeypoints(crop_left_eye, l_eye_keypoints, crop_left_eye, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
                    drawKeypoints(l_eye, l_eye_keypoints, l_eye, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

                    Point center(l_eye_keypoints[0].pt.x, l_eye_keypoints[0].pt.y);
                    eye_points.push_back(center);
                    eye_scenter = stabilize_eye_centers(eye_points, 5); // 5 last samples to stabilize
                    cv::circle(l_eye, eye_scenter, 10, Scalar(255, 255, 255), 1);
                    cv::circle(crop_left_eye, eye_scenter, 10, Scalar(255, 255, 255), 1);

                    if (eye_points.size() > 1)
                    {
                        diff_center.x = (eye_scenter.x - prev_center.x) * 20;
                        diff_center.y = (eye_scenter.y - prev_center.y) * -30;
                        cout << "   x: " + to_string(eye_scenter.x) + "\n";
                    }
                    prev_center = eye_scenter;

                    //Update min and max coords for X
                    int max_error_coord = 5;
                    if (eye_scenter.x <= min_coords.x && (min_coords.x + max_error_coord) > eye_scenter.x)
                        min_coords.x = eye_scenter.x;
                    if (eye_scenter.x >= max_coords.x && eye_scenter.x < min_coords.x + 2*max_error_coord)
                        max_coords.x = eye_scenter.x;
                    
                    //if (eye_scenter.x >= cvRound((min_coords.x + max_coords.x)/2))
                    if (eye_scenter.x >= r_thresh + 3)
                    {
                        cv::circle(face_ROI_color, Point(20,20), 10, Scalar(0, 0, 255), FILLED);
                        cout << "SIDE1 min:" + to_string(min_coords.x) + " max:" + to_string(max_coords.x) + " me: " + to_string((min_coords.x + max_coords.x)/2);
                        mouse_move(1);
                    }
                    if(eye_scenter.x < r_thresh  - 3)
                    {
                        cv::circle(face_ROI_color, Point(20,20), 10, Scalar(0, 255, 255), FILLED);
                        cout << "SIDE2 min:" + to_string(min_coords.x) + " max:" + to_string(max_coords.x) + " me: " + to_string((min_coords.x + max_coords.x)/2);
                        mouse_move(0);
                    }

                    //imshow("L eye", l_eye);
                }
            }

        }        
        imshow("MAIN WINDOW", frame);
        t = (double)getTickCount() - t;
        // printf("detection time = %g ms\n", t*1000/getTickFrequency());

        if (waitKey(1) == 13) // 13 is the Enter Key
            break;
    }
    
    capture.release();
    return  0;
}

void init_cv()
{
    // Cascade Classifiers //
    String face_cascade_name = "/home/pi/VOG-Eye-Tracker-CPP/haarcascades/haarcascade_frontalface_default.xml";
    String eyes_cascadade_name = "/home/pi/VOG-Eye-Tracker-CPP/haarcascades/haarcascade_eye.xml";
    if (!face_cascade.load(face_cascade_name) || !eyes_cascade.load(eyes_cascadade_name))
    {
        cerr << "(!) Error loading cascade classifiers\n";
        exit(-1);
    }
    //Blob Detector //
    // Filter by Area.
    params.filterByArea = true;
    params.minArea = 40;

    detector = SimpleBlobDetector::create(params); //PS (smart pointer) detector->detect( im, keypoints);
}

int face_detector(Mat& frame_gray, Mat& face_ROI, Rect& face_coords, Point& lest, Point& rest)
{
    vector<Rect> faces;
    face_cascade.detectMultiScale(frame_gray, faces, 1.3, 4, CASCADE_SCALE_IMAGE | CASCADE_FIND_BIGGEST_OBJECT, Size(30,30));
    if(faces.empty()) // No faces in the frame
        return -1;
    
    // Find biggest face
    int biggest = 0;
    for(size_t i = 0; i < faces.size(); i++)
        if (faces[i].width >= faces[biggest].width)
            biggest = (int) i;

    // Extract ROI and face points
    face_ROI = frame_gray(faces[biggest]);
    face_coords = faces[biggest];
    int w = faces[biggest].width;
    lest.x = cvRound((w * 0.1));
    lest.y = cvRound((w * 0.45));
    rest.x = cvRound((w * 0.55));
    rest.y = cvRound((w * 0.9));

    return 0;
}

int eye_detector(Mat face_ROI, Mat& l_eye, Mat& r_eye, Rect& l_eye_coords, Rect& r_eye_coords, Point lest, Point rest, int trim_size)
{
    vector<Rect> eyes;
    eyes_cascade.detectMultiScale(face_ROI, eyes);
    if (eyes.empty())
        return -1;

    for(size_t j = 0; j < eyes.size(); j++)
    {
        int eye_center = cvRound(eyes[j].x + eyes[j].width/2);
        if (eye_center > lest.x && eye_center < lest.y)
        {
            eyes[j].y += trim_size; // Trims eyebrows
            l_eye = face_ROI(eyes[j]);
            equalizeHist(l_eye, l_eye);
            l_eye_coords = eyes[j];
        } 
        else if (eye_center > rest.x && eye_center < rest.y)
        {
            eyes[j].y += trim_size; // Trims eyebrows
            r_eye = face_ROI(eyes[j]);
            equalizeHist(r_eye, r_eye);
            r_eye_coords = eyes[j];
        }
        else
            return -1;
    }
    return 0;
}

int pupil_detector(Mat eye_ROI, double thresh, float area, vector<KeyPoint>& pupil_keypoint)
{
    Mat eye_img;
    GaussianBlur(eye_ROI, eye_img, Size(5,5), 0);
    threshold(eye_img, eye_img, thresh, 255, THRESH_BINARY);
    erode(eye_img, eye_img, Mat(), Point(-1,-1), 3);
    dilate(eye_img, eye_img, Mat(), Point(-1,-1), 4);
    medianBlur(eye_img, eye_img, 5);
    erode(eye_img, eye_img, Mat(), Point(-1,-1), 1);
    //imshow("Pupil ROI", eye_img); // imshow for testing

    vector<KeyPoint> keypoints;
    detector->detect(eye_img, keypoints);
    if (keypoints.empty()) 
    {
        // cerr << "NO BLOBS\n";
        return -1;
    }

    float i = 1000;
    for(size_t j = 0; j < keypoints.size(); j++)
    {
        if (abs(keypoints[j].size - area) < i)
        {
            pupil_keypoint.insert(pupil_keypoint.end(), keypoints[j]);
            i = abs(keypoints[j].size - area);
        }
    }

    return 0;
}

void get_keypoints(Mat eye_ROI, double thresh, vector<KeyPoint>& keypoints, vector<KeyPoint>& prev_keypoint, float& prev_area)
{
    vector<KeyPoint> dec_keypoints;
    int p_detect = pupil_detector(eye_ROI, thresh, prev_area, dec_keypoints);

    if (p_detect == 0)
    {
        prev_keypoint = dec_keypoints;
        prev_area = dec_keypoints[0].size;
    } 
    else // No keypoints detected
    {
        keypoints = prev_keypoint;
    }
}

Point stabilize_eye_centers(vector<Point>& eye_points, int win_size)
{
    float sum_X = 0;
    float sum_Y = 0;
    int counter = 0;

    for (int i = max(0, (int) (eye_points.size() - win_size)); i < eye_points.size(); i++)
    {
        sum_X += eye_points[i].x;
        sum_Y += eye_points[i].y;
        ++counter;
    }
    if (counter > 0)
    {
        sum_X /= counter;
        sum_Y /= counter;
    }
    return Point(sum_X, sum_Y);
}

void mouse_move(int dir)
{
    static int idx_tab = 0;
    static int idx = 0;
    int posx_tv[] = {419, 348, 613, 334, 484, 625, 337, 480, 624, 335, 480, 631, 837, 838, 1072, 1083, 962, 960, 857, 712, 1042};
    int posy_tv[] = {113, 231, 238, 504, 497, 508, 600, 598, 591, 679, 684, 681, 212, 339, 230, 340, 533, 694, 601, 114, 114};
    int posx_ar[] = {712, 358, 724, 717, 453, 988, 1078, 1078, 1042, 419};
    int posy_ar[] = {114, 281, 513, 642, 570, 571, 239, 325, 114, 113};
    int posx_msg[] = {1042, 1070, 419, 712};
    int posy_msg[] = {114, 619, 113, 114};

    // dir 1 => eye to the right => move
    // dir 0 => eye to the left => click
    switch (idx_tab) 
    {
        case 0: // tv
            if (dir == 1) 
            {
                idx++;
                //move
                string str = "xdotool mousemove " + to_string(posx_tv[idx]) + " " + to_string(posy_tv[idx]);
                system(str.c_str());
            }
            else
            {
                //click
                string str = "xdotool click 1";
                system(str.c_str());
                if (idx == 19) 
                {
                    idx_tab = 1;
                    idx = 1;
                    string str = "xdotool mousemove " + to_string(posx_ar[idx]) + " " + to_string(posy_ar[idx]);
                    system(str.c_str());
                }
                if (idx == 20) 
                {
                    idx_tab = 2;
                    idx = 1;
                    string str = "xdotool mousemove " + to_string(posx_msg[idx]) + " " + to_string(posy_msg[idx]);
                    system(str.c_str());
                }
            }
        break;
        case 1: // ar
            if (dir == 1) 
            {
                idx++;
                //move
                string str = "xdotool mousemove " + to_string(posx_ar[idx]) + " " + to_string(posy_ar[idx]);
                system(str.c_str());
            }
            else
            {
                //click
                string str = "xdotool click 1";
                system(str.c_str());            
                if (idx == 8) 
                {
                    idx_tab = 2;
                    idx = 1;
                    string str = "xdotool mousemove " + to_string(posx_msg[idx]) + " " + to_string(posy_msg[idx]);
                    system(str.c_str());                    
                }
                if (idx == 9) 
                {
                    idx_tab = 0;
                    idx = 1;
                    string str = "xdotool mousemove " + to_string(posx_tv[idx]) + " " + to_string(posy_tv[idx]);
                    system(str.c_str());
                }
            }
        break;
        case 2: // msg
            if (dir == 1) 
            {
                idx++;
                //move
                string str = "xdotool mousemove " + to_string(posx_msg[idx]) + " " + to_string(posy_msg[idx]);
                system(str.c_str());
            }
            else
            {
                //click
                string str = "xdotool click 1";
                system(str.c_str());                
                if (idx == 2) 
                {
                    idx_tab = 0;
                    idx = 1;
                    string str = "xdotool mousemove " + to_string(posx_tv[idx]) + " " + to_string(posy_tv[idx]);
                    system(str.c_str());                    
                }
                if (idx == 3) 
                {
                    idx_tab = 1;
                    idx = 1;
                    string str = "xdotool mousemove " + to_string(posx_ar[idx]) + " " + to_string(posy_ar[idx]);
                    system(str.c_str());
                }
            }
        default:
        break;
    }
}
