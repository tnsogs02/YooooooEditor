#include "imgconv.h"


int opencv_iplimage(char* file);
//int opencv_mat(char* file);

int main()
{
	char file[50] = "test.jpg";
	opencv_iplimage(file);
}

int opencv_iplimage(char* file)
{
	IplImage* InputImage, * OutputImage;
	InputImage = cvLoadImage(file, CV_LOAD_IMAGE_COLOR);
	if (!InputImage)
	{
		printf("no file");
		return -1;
	}

	std::cout << "對比度:(建議值:-100 ~ +100，0表示不調整)";
	double contrast, brightness;
	std::cin >> contrast;
	std::cout << "亮部調整:";
	std::cin >> brightness;

	double factor = 1 + contrast / 100;

	OutputImage = cvCreateImage(CvSize(InputImage->width, InputImage->height), 8, 3);
	int r, g, b;
	//int threshold = 128;
	double aver = 0;
	for (int i = 0; i < InputImage->height; i++)
	{
		for (int j = 0; j < InputImage->width; j++)
		{
			CvScalar x = cvGet2D(InputImage, i, j);
			aver += (x.val[2] + x.val[1] + x.val[0]) / 3;
		}

	}
	aver /= InputImage->width;
	aver /= InputImage->height;



	for (int i = 0; i < OutputImage->height; i++)
	{
		for (int j = 0; j < OutputImage->width; j++)
		{
			CvScalar x = cvGet2D(InputImage, i, j);
			//r = 0.299 * x.val[2] + 0.587 * x.val[1] + 0.114 * x.val[0];
			//g = 0.299 * x.val[2] + 0.587 * x.val[1] + 0.114 * x.val[0];
			//b = 0.299 * x.val[2] + 0.587 * x.val[1] + 0.114 * x.val[0];
			r = factor * (x.val[2] - aver) + aver;
			g = factor * (x.val[1] - aver) + aver;
			b = factor * (x.val[0] - aver) + aver;

			//if (brightness > 0)
			//{
			if ((r + g + b) / 3 > aver * 1.5)
			{
				r += brightness;
				g += brightness;
				b += brightness;
			}
			//	}
					/*else if (brightness < 0)
					{
						if ((r + g + b) / 3 > aver * 1.5)
						{
							r += brightness;
							g += brightness;
							b += brightness;
						}
					}*/

			cvSet2D(OutputImage, i, j, CV_RGB(r, g, b));
		}
	}

	cvNamedWindow("Input", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Output", CV_WINDOW_AUTOSIZE);
	cvShowImage("Input", InputImage);
	cvShowImage("Output", OutputImage);
	char cc = cvWaitKey(0);
	cvReleaseImage(&InputImage);
	cvReleaseImage(&OutputImage);
	cvDestroyWindow("Input");
	cvDestroyWindow("Output");
	//cvDestroyAllWindows();
	cc = cvWaitKey(0);
	return 0;
}

/*int opencv_mat(char* file)
{
	imread
}*/