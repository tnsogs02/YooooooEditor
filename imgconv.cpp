#include"imgconv"

using namespace cv;
using namespace std;

Mat Colorfulness(Mat img, int i) {
    float j = i / 100;
    float max = 0;
    Mat fimg;
    img.convertTo(fimg, 21, 1.0 / 255.0, 0);
    Mat imgHSV;
    cvtColor(fimg, imgHSV, COLOR_RGB2HSV);
    for (int r = 0; r < imgHSV.rows; r++) {
        cv::Vec3f* ptr = imgHSV.ptr<cv::Vec3f>(r);
        for (int c = 0; c < imgHSV.cols; c++) {
            ptr[c][1] += j;
        }
    }
    cvtColor(imgHSV, fimg, COLOR_HSV2RGB);

    return fimg;
}