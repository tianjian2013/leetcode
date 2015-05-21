#include "globe.h"

int main()
{
	int index=0;
	
	// Open the video file
cv::VideoCapture capture("D:\\f\\resp.avi");
// check if video successfully opened
if (!capture.isOpened())
return 1;

bool stop(false);
cv::Mat frame; // current video frame
cv::namedWindow("Extracted Frame");
// Delay between each frame in ms
// corresponds to video frame rate
int delay= 50;
// for all frames in video
while (!stop) {
// read next frame if any
if (!capture.read(frame))
break;
cv::imshow("Extracted Frame",frame);
string str;
stringstream ss;
ss<<index++;
ss>>str;
imwrite("D:\\f\\res\\"+str+".jpg",frame);
// introduce a delay
// or press key to stop
if (cv::waitKey(delay)>=0)
stop= true;
}
// Close the video file.
// Not required since called by destructor
capture.release();
}