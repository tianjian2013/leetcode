#include <opencv2/opencv.hpp>
using namespace cv;
void main()
{
	Mat img=imread("1.jpg");
    Mat gray1;
	cvtColor( img, gray1, CV_RGB2GRAY );
	medianBlur(gray1, gray1, 7);
	Mat edges;
    const int LAPLACIAN_FILTER_SIZE = 5;
    Laplacian(gray1, edges, CV_8U, LAPLACIAN_FILTER_SIZE);
    Mat mask;
   const int EDGES_THRESHOLD = 80;
   threshold(edges, mask, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);
    //IplImage pImg= IplImage(mask); 
   imwrite("2.jpg",mask);
}