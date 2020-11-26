#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void adjust_contrast(cv::Mat image, int contrast);
void adjust_brightness(cv::Mat image, int brightness, double arguments);