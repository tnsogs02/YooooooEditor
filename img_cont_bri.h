#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void adjust_contrast(cv::Mat image, int contrast);//contrast: prefer 0 ~ 100
void adjust_brightness(cv::Mat image, int brightness, double arguments);
//brightness: prefer -50 ~ +50 ; arguments: default 1.2