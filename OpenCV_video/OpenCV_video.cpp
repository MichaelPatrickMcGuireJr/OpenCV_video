/*
 *   Author:  Michael McGuire
 *  Purpose:  using OpenCV to capture a video stream and display it on screen
 * Language:  c++
 */

// headers
#include <iostream>
#include "opencv2/opencv.hpp"

// enabling the code to implicitly call the std and cv namespaces
using namespace std;
using namespace cv;

int main() {

	// creating video capture object from default video device 0
	VideoCapture cap(0);

	// Check if camera opened successfully
	if (!cap.isOpened()) 
	{
		// print error message if issue openning video stream
		cout << "Error opening video stream or file" << endl;
		// end main
		return -1;
	}

	
	while (1) 
	{
		// creating a from object from OpenCV
		Mat frame;
		// place image from capture on frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.empty())
		{
			break;
		}

		// Display window frame on conole with OpenCV imshow method
		imshow("Frame", frame);

		// the waitkey function is waiting 25ms for a keypress, if pressed it stores the character otherwise it passes a -1
		char c = (char)waitKey(25);
		// if the esc key is pressed
		if (c == 27)
		{
			// escape while loop
			break;
		}

	}

	// release video capture object 
	cap.release();

	// destroy all frames from memory
	destroyAllWindows();

	// end main
	return 0;
}





/*   DISPLAY IMAGE
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	String imageName("C:\\Users\\DataManagement\\Documents\\practice-visual_studio\\opencv-4.1.2\\opencv.png"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}
	Mat image;
	image = imread(samples::findFile(imageName), IMREAD_COLOR); // Read the file
	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image);                // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
*/