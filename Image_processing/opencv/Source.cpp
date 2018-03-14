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
	cout << "type "<<img.type() << endl;
	cout << "size "<<img.size() << endl;
	cout << "channels "<<img.channels() << endl;
	cout << "depth "<<img.depth() << endl<<endl;
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

	_gamma_transform(img,"0.5", 1, 0.5);
	_gamma_transform(img,"0.9", 1, 0.9);

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
	cin>>x1>>y1>>x2>>y2;

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

	cout<<"Enter the value of sigma: ";
	float sigma;
	cin>>sigma;

	// Calculating kernel and padding size
	int kernel_size = ceil(sigma * 5);
	if(kernel_size % 2 == 0 ){
		kernel_size = kernel_size + 1;
	}

	int padding_size = kernel_size/2;
	cout<<kernel_size<< " "<<padding_size<<endl;
	
	// Creating destination image
	Mat des;
	des.create( (row - padding_size*2), (col - padding_size*2), CV_8U);
	image_info(des);

	// Creating kernel
	Mat kernel;
	kernel.create(kernel_size, kernel_size, CV_32FC1);
	image_info(kernel);


	// Calculating kernel
	for(int i=-padding_size; i<=padding_size; i++)
	{
		for(int j=-padding_size; j<=padding_size; j++){
			float val = exp( -(pow(i, 2) + pow(j, 2)) / 2 * (pow(sigma, 2)) );
			kernel.at<float>(i+padding_size, j+padding_size) = val;
			//cout<<val<<endl;
		}
	}

	// printing kernel for test
	cout<<"kernel before normalization"<<endl;
	for(int i=-padding_size; i<=padding_size; i++)
	{
		for(int j=-padding_size; j<=padding_size; j++){
			cout<<kernel.at<float>(i+padding_size, j+padding_size)<<" ";

		}
		cout<<endl;
	}


	// Normalize the kernel
	float norm = kernel.at<float>(0, 0);
	float total = 0;
	for(int i=-padding_size; i<=padding_size; i++)
	{
		for(int j=-padding_size; j<=padding_size; j++){
			float val = ceil(kernel.at<float>(i+padding_size, j+padding_size) / norm);
			kernel.at<float>(i+padding_size, j+padding_size) = val;
			total += val;
		}
		cout<<endl;
	}

	cout<<"Normalization factor : "<<total<<endl;



	// printing kernel for test
	cout<<"kernel after normalization"<<endl;
	for(int i=-padding_size; i<=padding_size; i++)
	{
		for(int j=-padding_size; j<=padding_size; j++){
			cout<<kernel.at<float>(i+padding_size, j+padding_size)<<" ";

		}
		cout<<endl;
	}


	// Convolutional operation
	for(int i=0; i<row- 2 * padding_size; i++){
		for(int j=0; j<col - 2*padding_size; j++){
			//position of image to start kernel calculation

			float ans=0;
			for(int a=0; a<kernel_size; a++){
				for(int b=0; b<kernel_size; b++){
					ans += img.at<uchar>(i+a, j+b) * kernel.at<float>(a, b);
				}
			}

			ans = (uchar)(ans / total);
			des.at<uchar>(i,j) = ans;


		} 
	}

	imshow("gausaian filtered", des);

	Mat ocvGblur;
	GaussianBlur(img,ocvGblur,Size(7,7),1.4,1.4);
	imshow("OCV_G_Blur",ocvGblur);


	
}


void sharpen()
{
	Mat lena, inp, dest, kernel;
	lena = imread("lena.jpg");
	//image_info(lena);

	int row, col,padding_size;
	float sigma=float(1.4),total=0;
	//cout << "Enter the value of sigma: ";
	//cin >> sigma;

	row = lena.size[0];
	col = lena.size[1];

	cvtColor(lena, inp, CV_BGR2GRAY);
	imshow("Gray", inp);
	waitKey(0);

	int kernel_size = int(ceil(sigma * 5));
	if (kernel_size % 2 == 0) {
		kernel_size++;
	}
	padding_size = kernel_size / 2;

	//cout << kernel_size << endl;

	//Creating Kernel 
	kernel.create(kernel_size, kernel_size, CV_32FC1);
	for (int i = -padding_size; i <= padding_size; i++) {
		for (int j = -padding_size; j <= padding_size; j++) {
			float val = float(exp((pow(i, 2) + pow(j, 2)) / (2 * pow(sigma, 2))));
			kernel.at<float>(i + padding_size, j + padding_size)=val;
			total += val;
		}
	}
	//convolution over the loop 
	dest.create(row,col,CV_8U);

	for (int i = padding_size; i < row - 2 * padding_size; i++) {
		for (int j = padding_size; j < col - 2 * padding_size; j++) {
			float sum = 0.0;
			for (int a = 0; a < kernel_size; a++) {
				for (int b = 0; b < kernel_size; b++) {
					sum += inp.at<uchar>(i + a, j + b)*kernel.at<float>(a, b);
				}
			}
			dest.at<uchar>(i, j) = int(ceil(sum / total));
		}
	}

	imshow("Out", dest);
	waitKey(0);
	//highboost filtering and unsharp masking
	image_info(dest);
	Mat mask;
	mask.create(row, col, CV_8UC1);

	mask = inp - dest;

	imshow("Mask", mask);
	waitKey(0);

	float k = 1;
	Mat g = inp + (k*mask);

	imshow("Unsharp", g);
	waitKey(0);

}


void erosion()
{
	Mat img = imread("star.tif");
	cvtColor(img, img, CV_RGB2GRAY);
	int kernel_size = 15;

	copyMakeBorder(img, img, kernel_size/2,kernel_size/2,kernel_size/2,kernel_size/2,0,0);
	//imshow("Star", img);

	Mat des = img.clone();
	image_info(des);

	int row = des.size[0];
	int col = des.size[1];
	cout<<"Row "<<row<<" Col "<<col<<endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			des.at<uchar>(i, j) = 255;
		}
	}
	imshow("Src", img);

	

	Mat kernel;
	kernel.create(kernel_size, kernel_size, CV_8U);
	for(int i=0; i<kernel_size; i++){
		for(int j=0; j<kernel_size; j++){
			kernel.at<uchar>(i, j) = 255;
		}
	}

	des.convertTo(des, CV_8U);
	cout<<(des.type())<<endl;

	for (int i = 0; i < row-kernel_size-1; i++) {
		for (int j = 0; j < col-kernel_size-1; j++) {
			
			bool matched = true;

			for(int x=0; x<kernel_size; x++){
				for(int y=0; y<kernel_size; y++){
					if(img.at<uchar>(i+x,j+y) != kernel.at<uchar>(x, y)){
						matched = false;
					}
				}
			}

			if(matched){
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 255;
			} else {
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 0;
			}
		}
	}

	imshow("Final image", des);
}


void edge_detector(){
	Mat img = imread("man.tif");
	cvtColor(img, img, CV_RGB2GRAY);
	int kernel_size = 3;

	copyMakeBorder(img, img, kernel_size/2,kernel_size/2,kernel_size/2,kernel_size/2,0,0);
	//imshow("Star", img);

	Mat des = img.clone();
	image_info(des);

	int row = des.size[0];
	int col = des.size[1];
	cout<<"Row "<<row<<" Col "<<col<<endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			des.at<uchar>(i, j) = 255;
		}
	}
	imshow("Src", img);

	

	Mat kernel;
	kernel.create(kernel_size, kernel_size, CV_8U);
	for(int i=0; i<kernel_size; i++){
		for(int j=0; j<kernel_size; j++){
			kernel.at<uchar>(i, j) = 255;
		}
	}

	des.convertTo(des, CV_8U);
	cout<<(des.type())<<endl;

	for (int i = 0; i < row-kernel_size-1; i++) {
		for (int j = 0; j < col-kernel_size-1; j++) {
			
			bool matched = true;

			for(int x=0; x<kernel_size; x++){
				for(int y=0; y<kernel_size; y++){
					if(img.at<uchar>(i+x,j+y) != kernel.at<uchar>(x, y)){
						matched = false;
					}
				}
			}

			if(matched){
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 255;
			} else {
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 0;
			}
		}
	}

	imshow("Final image", des);

	Mat edge = img - des;
	imshow("Edge", edge);
}

void dilation(){
	Mat img = imread("finger_print.tif");
	cvtColor(img, img, CV_RGB2GRAY);
	int kernel_size = 3;

	copyMakeBorder(img, img, kernel_size/2,kernel_size/2,kernel_size/2,kernel_size/2,0,0);
	//imshow("Star", img);

	Mat des = img.clone();
	image_info(des);

	int row = des.size[0];
	int col = des.size[1];
	cout<<"Row "<<row<<" Col "<<col<<endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			des.at<uchar>(i, j) = 255;
		}
	}
	imshow("Src", img);

	

	Mat kernel;
	kernel.create(kernel_size, kernel_size, CV_8U);
	for(int i=0; i<kernel_size; i++){
		for(int j=0; j<kernel_size; j++){
			kernel.at<uchar>(i, j) = 255;
		}
	}

	des.convertTo(des, CV_8U);
	cout<<(des.type())<<endl;

	for (int i = 0; i < row-kernel_size-1; i++) {
		for (int j = 0; j < col-kernel_size-1; j++) {
			
			bool matched = false;

			for(int x=0; x<kernel_size; x++){
				for(int y=0; y<kernel_size; y++){
					if(img.at<uchar>(i+x,j+y) == kernel.at<uchar>(x, y)){
						matched = true;
					}
				}
			}

			if(matched){
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 255;
			} else {
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 0;
			}

		}
	}

	imshow("Final image", des);
}


void finger_print(){
	Mat img = imread("finger_print.tif");
	cvtColor(img, img, CV_RGB2GRAY);
	int kernel_size = 3;

	copyMakeBorder(img, img, kernel_size/2,kernel_size/2,kernel_size/2,kernel_size/2,0,0);
	//imshow("Star", img);

	Mat des = img.clone();
	image_info(des);

	int row = des.size[0];
	int col = des.size[1];
	cout<<"Row "<<row<<" Col "<<col<<endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			des.at<uchar>(i, j) = 255;
		}
	}
	imshow("Src", img);

	

	Mat kernel;
	kernel.create(kernel_size, kernel_size, CV_8U);
	for(int i=0; i<kernel_size; i++){
		for(int j=0; j<kernel_size; j++){
			kernel.at<uchar>(i, j) = 255;
		}
	}

	des.convertTo(des, CV_8U);
	cout<<(des.type())<<endl;

	for (int i = 0; i < row-kernel_size-1; i++) {
		for (int j = 0; j < col-kernel_size-1; j++) {
			
			bool matched = true;

			for(int x=0; x<kernel_size; x++){
				for(int y=0; y<kernel_size; y++){
					if(img.at<uchar>(i+x,j+y) != kernel.at<uchar>(x, y)){
						matched = false;
					}
				}
			}

			if(matched){
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 255;
			} else {
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 0;
			}
		}
	}

	imshow("corotion image", des);
	img = des;
	//imshow("new src", img);

	des = img.clone();
	//imshow("new des", des);

	for (int i = 0; i < row-kernel_size-1; i++) {
		for (int j = 0; j < col-kernel_size-1; j++) {
			
			bool matched = false;

			for(int x=0; x<kernel_size; x++){
				for(int y=0; y<kernel_size; y++){
					if(img.at<uchar>(i+x,j+y) == kernel.at<uchar>(x, y)){
						matched = true;
					}
				}
			}

			if(matched){
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 255;
			} else {
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 0;
			}

		}
	}
	imshow("Final image Step 1", des);

	img = des;
	des = img.clone();

	for (int i = 0; i < row-kernel_size-1; i++) {
		for (int j = 0; j < col-kernel_size-1; j++) {
			
			bool matched = true;

			for(int x=0; x<kernel_size; x++){
				for(int y=0; y<kernel_size; y++){
					if(img.at<uchar>(i+x,j+y) != kernel.at<uchar>(x, y)){
						matched = false;
					}
				}
			}

			if(matched){
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 255;
			} else {
				des.at<uchar>(i+kernel_size/2, j+kernel_size/2) = 0;
			}
		}
	}

	imshow("Final image Step 2", des);
}


void show_hist(Mat img, String id)
{
	
	//image_info(img);
	//cvtColor(img, img, CV_BGR2GRAY);
	/*imshow("lena", img);*/

	int row = img.size[0];
	int col = img.size[1];

	//Declearing local variables
	int intensity_count[256]; 
	Mat freq = Mat::zeros(1,256,CV_32SC1);
	int *pt_freq=freq.ptr<int>(0);

	float normalized_intensity[256];
	float cumulative_prob[256];

	for(int i=0; i<256; i++){
		intensity_count[i] = 0;
	}

	/*for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			int intensity = img.at<uchar>(i, j);
			intensity_count[intensity] += 1;
			pt_freq[intensity]++;
		}
	}*/

	
	for(int i=0; i<row; i++){
		uchar *pt = img.ptr<uchar>(i);
		for(int j=0; j<col; j++){
			int intensity = pt[j]; //img.at<uchar>(i, j);
			intensity_count[intensity] += 1;
			pt_freq[intensity]++;
		}
	}


	float max_intensity = 0.0;
	int mn = row*col;

	freq /= mn;


	for(int i=0; i<256; i++){
		normalized_intensity[i] = (float)intensity_count[i]/mn;
		if (normalized_intensity[i] > max_intensity){
			max_intensity = normalized_intensity[i];
		}
	}

	
	cumulative_prob[0] = normalized_intensity[0];
	for(int i=1; i<256; i++){
		cumulative_prob[i] = cumulative_prob[i-1] + normalized_intensity[i];
		//cout<<cumulative_prob[i]<<endl;
	}

	Mat hist;
	hist.create(300, 256, CV_8UC1);
	hist.setTo(256);
	

	for(int j=0; j<256; j++){
		int height = 300 * normalized_intensity[j] / max_intensity;
		for(int i=300-1; i>(300-height); i--){
			hist.at<uchar>(i, j) = 0;
		}
	}

	imshow("hist"+id, hist);
}

void show_hist_mat(Mat img, String id)
{
	int row = img.size[0];
	int col = img.size[1];

	//Declearing local variables
	int intensity_count[256]; 
	Mat freq = Mat::zeros(1,256,CV_32SC1);
	int *pt_freq=freq.ptr<int>(0);

	float normalized_intensity[256];
	float cumulative_prob[256];

	
	for(int i=0; i<row; i++){
		uchar *pt = img.ptr<uchar>(i);
		for(int j=0; j<col; j++){
			int intensity = pt[j]; //img.at<uchar>(i, j);
			pt_freq[intensity]++;
		}
	}


	float max_intensity = 0.0;
	int mn = row*col;

	Mat normalized_freq;
	freq.convertTo(normalized_freq, CV_32FC1);
	normalized_freq /= mn;

	float *pt_normalized_freq = normalized_freq.ptr<float>(0);



	for(int i=0; i<256; i++){
		if (pt_normalized_freq[i] > max_intensity){
			max_intensity = pt_normalized_freq[i];
		}
	}

	
	cumulative_prob[0] = pt_normalized_freq[0];
	for(int i=1; i<256; i++){
		cumulative_prob[i] = cumulative_prob[i-1] + pt_normalized_freq[i];
		//cout<<cumulative_prob[i]<<endl;
	}

	Mat hist;
	hist.create(300, 256, CV_8UC1);
	hist.setTo(256);
	

	for(int j=0; j<256; j++){
		int height = 300 * pt_normalized_freq[j] / max_intensity;
		for(int i=300-1; i>(300-height); i--){
			hist.at<uchar>(i, j) = 0;
		}
	}

	imshow("hist"+id, hist);
}


void histogram_equalization(){
	Mat img = imread("Fig0310.tif");
	show_hist_mat(img, "0");

	image_info(img);
	cvtColor(img, img, CV_BGR2GRAY);
	imshow("original image", img);

	int row = img.size[0];
	int col = img.size[1];

	//Declearing local variables
	int intensity_count[256];  
	float normalized_intensity[256];
	float cumulative_prob[256];

	for(int i=0; i<256; i++){
		intensity_count[i] = 0;
	}

	for(int i=0; i<row; i++){
		uchar *pt = img.ptr<uchar>(i);
		for(int j=0; j<col; j++){
			int intensity = pt[j];//img.at<uchar>(i, j);
			intensity_count[intensity] += 1;
			//pt_freq[intensity]++;
		}
	}

	float max_intensity = 0.0;
	int mn = row*col;

	for(int i=0; i<256; i++){
		normalized_intensity[i] = (float)intensity_count[i]/mn;
		if (normalized_intensity[i] > max_intensity){
			max_intensity = normalized_intensity[i];
		}
	}

	
	cumulative_prob[0] = normalized_intensity[0];
	for(int i=1; i<256; i++){
		cumulative_prob[i] = cumulative_prob[i-1] + normalized_intensity[i];
		//cout<<cumulative_prob[i]<<endl;
	}

	int transformed_intensity[256];
	for(int i=0; i<256; i++){
		transformed_intensity[i] = 255 * cumulative_prob[i];
		cout<<transformed_intensity[i]<<endl;
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			int intensity = img.at<uchar>(i, j);
			img.at<uchar>(i, j) = transformed_intensity[intensity];
		}
	}

	imshow("tranformaed image", img);
	show_hist(img, "1");
}


int main(int argc, char** argv)
{
	
	//load_and_show_image();
	//im_show();
	//simpleTransform();
	//image_info();
	//gamma_transform();
	//intensity_slicing();
	//spatial_filtering();
	//sharpen();
	//erosion();
	//edge_detector();
	//dilation();
	//finger_print();
	histogram_equalization();


	waitKey(0);
	getchar();
	return 0;
}