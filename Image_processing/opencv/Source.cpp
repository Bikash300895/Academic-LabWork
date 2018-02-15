#include <opencv2\opencv.hpp>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

Mat src, dst;

void load_and_show_image()
{
	src = imread("lena.jpg");

	imshow("lena", src);
	waitKey(0);

	Mat grayLena;
	cvtColor(src, grayLena, CV_BGR2GRAY);

	imshow("lenaGray", grayLena);

	waitKey(0);
}

void im_show() {
	Mat img = imread("lena.jpg");
	if (img.empty()) return;

	//namedWindow("example1", WINDOW_AUTOSIZE);
	imshow("example1", img);
	waitKey(0);

	//destroyWindow("example1");

}

void simpleTransform()
{
	Mat img = imread("lena.jpg");

	imshow("lena", img);

	Mat out;
	GaussianBlur(img, out, Size(5, 5), 3, 3);

	imshow("out", out);
}


void image_info(Mat img)
{
	//Mat img = imread("lena.jpg");
	cout << "total " << img.total() << endl;
	cout << "type " << img.type() << endl;
	cout << "size " << img.size() << endl;
	cout << "channels " << img.channels() << endl;
	cout << "depth " << img.depth() << endl << endl;
}

void _gamma_transform(Mat img, String name, double c, double gamma)
{
	Mat gm = img.clone();
	int row = gm.size[0];
	int col = gm.size[1];

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			/*if (gamma < 1) {
			gm.at<uchar>(i, j) = uchar(c * pow(gm.at<uchar>(i, j), gamma));
			}
			else {
			gm.at<uchar>(i, j) = uchar((c * pow(gm.at<uchar>(i, j), gamma))/pow(255, gamma-1));
			}*/

			gm.at<uchar>(i, j) = uchar((c * pow(gm.at<uchar>(i, j), gamma)) / pow(255, gamma - 1));

		}
	}

	imshow(name, gm);
	waitKey(0);
}

void gamma_transform()
{
	Mat img = imread("lena.jpg");
	image_info(img);
	imshow("lena", img);

	cvtColor(img, img, CV_BGR2GRAY);
	imshow("gray original", img);

	// Values of c and gamma
	double c = 1;
	double gamma = 0.5;

	_gamma_transform(img, "0.5", 1, 0.5);
	_gamma_transform(img, "0.9", 1, 0.9);

	/*_gamma_transform(img, "10, 0.5", 10, 0.5);
	_gamma_transform(img, "10 0.9", 10, 0.9);*/

	_gamma_transform(img, "1 2.0", 1, 2.0);
	_gamma_transform(img, "1 10.0", 1, 10.0);


}

void intensity_slicing() {
	Mat img = imread("lena.jpg");
	image_info(img);
	cvtColor(img, img, CV_BGR2GRAY);

	imshow("lena", img);

	Mat des = img.clone();
	int x1 = 90, y1 = 70, x2 = 200, y2 = 220;
	cin >> x1 >> y1 >> x2 >> y2;

	int row = img.size[0];
	int col = img.size[1];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			double slope = (double)y1 / x1;
			double slope1 = (double)(y2 - y1) / (x2 - x1);
			double slope2 = (double)(255 - y2) / (255 - x2);

			if (img.at<uchar>(i, j) <= x1) {
				des.at<uchar>(i, j) = (uchar)(slope * (double)img.at<uchar>(i, j));
			}
			else if (img.at<uchar>(i, j) <= x2) {
				des.at<uchar>(i, j) = (uchar)(slope1 * (double)img.at<uchar>(i, j));
			}
			else {
				des.at<uchar>(i, j) = (uchar)(slope2 * (double)img.at<uchar>(i, j));
			}
		}
	}

	imshow("intensity shifted image", des);

}


void spatial_filtering()
{
	Mat img = imread("lena.jpg");
	image_info(img);
	cvtColor(img, img, CV_BGR2GRAY);

	imshow("lena", img);

	int row = img.size[0];
	int col = img.size[1];

	cout << "Enter the value of sigma: ";
	float sigma;
	cin >> sigma;

	// Calculating kernel and padding size
	int kernel_size = ceil(sigma * 5);
	if (kernel_size % 2 == 0) {
		kernel_size = kernel_size + 1;
	}

	int padding_size = kernel_size / 2;
	cout << kernel_size << " " << padding_size << endl;

	// Creating destination image
	Mat des;
	des.create((row - padding_size * 2), (col - padding_size * 2), CV_8U);
	image_info(des);

	// Creating kernel
	Mat kernel;
	kernel.create(kernel_size, kernel_size, CV_32FC1);
	image_info(kernel);

	float total = 0;
	// Calculating kernel
	for (int i = -padding_size; i <= padding_size; i++)
	{
		for (int j = -padding_size; j <= padding_size; j++) {
			float val = exp(-(pow(i, 2) + pow(j, 2)) / 2 * (pow(sigma, 2)));
			kernel.at<float>(i + padding_size, j + padding_size) = val;
			total += val;
			//cout<<val<<endl;
		}
	}

	// printing kernel for test
	cout << "kernel before normalization" << endl;
	for (int i = -padding_size; i <= padding_size; i++)
	{
		for (int j = -padding_size; j <= padding_size; j++) {
			cout << kernel.at<float>(i + padding_size, j + padding_size) << " ";

		}
		cout << endl;
	}


	// Normalize the kernel
	//float norm = kernel.at<float>(0, 0);
	//float total = 0;
	//for (int i = -padding_size; i <= padding_size; i++)
	//{
	//	for (int j = -padding_size; j <= padding_size; j++) {
	//		float val = ceil(kernel.at<float>(i + padding_size, j + padding_size) / norm);
	//		kernel.at<float>(i + padding_size, j + padding_size) = val;
	//		total += val;
	//	}
	//	cout << endl;
	//}

	//cout << "Normalization factor : " << total << endl;



	//// printing kernel for test
	//cout << "kernel after normalization" << endl;
	//for (int i = -padding_size; i <= padding_size; i++)
	//{
	//	for (int j = -padding_size; j <= padding_size; j++) {
	//		cout << kernel.at<float>(i + padding_size, j + padding_size) << " ";

	//	}
	//	cout << endl;
	//}


	// Convolutional operation
	for (int i = 0; i<row - 2 * padding_size; i++) {
		for (int j = 0; j<col - 2 * padding_size; j++) {
			//position of image to start kernel calculation

			float ans = 0;
			for (int a = 0; a<kernel_size; a++) {
				for (int b = 0; b<kernel_size; b++) {
					ans += img.at<uchar>(i + a, j + b) * kernel.at<float>(a, b);
				}
			}

			ans = (uchar)(ans / total);
			des.at<uchar>(i, j) = ans;


		}
	}

	imshow("gausaian filtered", des);

	// Test with build in functinos
	Mat ocvGblur;
	GaussianBlur(img, ocvGblur, Size(7, 7), 1.4, 1.4);
	imshow("OCV_G_Blur", ocvGblur);


}



int main(int argc, char** argv)
{

	//load_and_show_image();
	//im_show();
	//simpleTransform();
	//image_info();
	//gamma_transform();
	//intensity_slicing();
	spatial_filtering();


	waitKey(0);
	getchar();
	return 0;
}