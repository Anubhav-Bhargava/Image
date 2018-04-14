//g++ main.cpp `pkg-config opencv --cflags --libs` 

#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

const int scale =30,quality=90;


Mat elaProcessImage(Mat img){
	//Set up the parameters for JPEG compression

	vector<int> params;
	params.push_back(CV_IMWRITE_JPEG_QUALITY);
	params.push_back(quality);
	imwrite("temp.jpeg", img, params);

	//Load the compressed image
	Mat compressed_img=imread("temp.jpeg");


	//Calculate absolute difference between the original & Compressed image

	//Mat output_img = Mat::zeros(img.size(), CV_8UC3);
	Mat orig_img_channels[3],comp_img_channels[3], diff_img[3];
	
	split(img,orig_img_channels);
	split(compressed_img,comp_img_channels);

	absdiff(orig_img_channels[0], comp_img_channels[0], diff_img[0]);
	absdiff(orig_img_channels[1], comp_img_channels[0], diff_img[1]);
	absdiff(orig_img_channels[2], comp_img_channels[0], diff_img[2]);

	//Merging back the image into a 3 channel RGB image

	vector<Mat> merge_img;
	merge_img.push_back(diff_img[0]);
	merge_img.push_back(diff_img[1]);
	merge_img.push_back(diff_img[2]);

	Mat output_img = Mat::zeros(img.size(), CV_8UC3);
	
	merge(merge_img,output_img);

	//Scale up the output_img matrix to show the highlight the dieffernces

	for (int row=0; row<img.rows; row++){

		//A pointer used to scale up unsigned char values
		 uchar* ptr = output_img.ptr<uchar>(row);
		 for (int column=0; column<img.cols; column++){

		 	ptr[0]*=scale;
		 	ptr[1]*=scale;
		 	ptr[2]*=scale;

		 	//To point to the next channel
		 	ptr +=3;

		 }
	}

	return output_img;
}



int main ()
{

	//Load Image
    Mat img = imread("image.jpg") ;
    //Perform ELA on the loaded image
    Mat prcessedImage = elaProcessImage(img);
    //Save Image
    imwrite("processed_image.jpg",prcessedImage);
    return EXIT_SUCCESS;
}
