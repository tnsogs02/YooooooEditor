#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<libraw.h>
using namespace std;
using namespace cv;
void auto_adjust(Mat& image) {
	double R=0, G=0, B = 0;
	vector<Mat>imageRGB;
	split(image, imageRGB);
	B = mean(imageRGB[0])[0];
	G = mean(imageRGB[1])[0];
	R = mean(imageRGB[2])[0];
	double KR, KG, KB;
	KR = (R + B + G) / (3*	R);
	KG = (R + B + G) / (3 * G);
	KB = (R + B + G) / (3 * B);
	imageRGB[0] *= KB;
	imageRGB[1] *= KG;
	imageRGB[2] *= KR;
	merge(imageRGB, image);
}
void adjust(Mat& image, int temperature) {
	/*色溫調整，temperature在0~10000*/
	double R = 0,B = 0;
	vector<Mat>imageRGB;
	split(image, imageRGB);
	B = mean(imageRGB[0])[0]+1;
	R = mean(imageRGB[2])[0]+1;
	double R_B = R / B;
	/*R/B/256乘10000+5000為色溫*/
	double a = R_B / 256 * 10000 + 5000;
	if (R>128) {
		imageRGB[2] /= R_B * ((double)(temperature/a));
	}
	else {
		imageRGB[0] /= R_B * ((double)(temperature/a));
	}
	merge(imageRGB, image);
}
void average(Mat& image) {
	/*曝光調整，須將圖片轉灰階*/
	cvtColor(image, image, CV_BGR2GRAY);
	equalizeHist(image, image);
}
int main() {
	Mat image= imread("C:\\Users\\hambe\\OneDrive\\桌面\\梗圖\\sanae.tiff", 1);
	adjust(image, 10000);
	Mat origin = image;
	imshow("original", origin);
	imshow("change", image);
	int c = waitKey(10000000);
}
//IplImage* Image1 = cvLoadImage("C:\\Users\\hambe\\OneDrive\\桌面\\梗圖\\sanae.tiff", 1); // 1 color ,others single
//cvNamedWindow("Picture", 1);// 將視窗命名為"Picture"，其中 1 代表 自動調整式窗大小
//cvResizeWindow("Picture",250,400); //cvNamedWindow 的 flag必須為0 ;
//cvShowImage("Picture", Image1); // 顯示圖片
//cvDestroyWindow("Picture"); // 關閉式窗
//cvReleaseImage(&Image1); //釋放影像記憶體
