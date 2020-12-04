#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::Mat adjust_contrast(cv::Mat image, int contrast);//contrast: prefer 0 ~ 100
cv::Mat adjust_brightness(cv::Mat image, int brightness);
cv::Mat adjust_brightness(cv::Mat image, int brightness, double arguments);
//brightness: prefer -50 ~ +50 ; arguments: default 1.2