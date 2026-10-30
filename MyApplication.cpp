#include "Utilities.h"

void MyApplication()
{
	char *file_location = "Media/Pool/";
	char *pool_files[] = {
		"AllBalls.jpeg",
		"Table1.jpeg",
		"Table2.jpeg",
		"Table3.jpeg",
		"Table4.jpeg",
		"Table5.jpeg",
		"Table6.jpeg"};

	// Load images
	int number_of_images = sizeof(pool_files) / sizeof(pool_files[0]);
	Mat *pool_image = new Mat[number_of_images];
	// Mat* new_pool_image = new Mat[number_of_images];
	for (int file_no = 0; (file_no < number_of_images); file_no++)
	{
		cout << pool_files[file_no] << endl;
		string filename(file_location);
		filename.append(pool_files[file_no]);
		pool_image[file_no] = imread(filename, -1);

		if (pool_image[file_no].empty())
		{
			cout << "Could not open " << pool_image[file_no] << endl;
		}
		imshow(pool_files[file_no], pool_image[file_no]);

		char pause = cv::waitKey(); // This introduces a delay between frame.  The length of the delay/number can be reduced.
	}

	// First Idea : Hough Circle Transform
	// First: Greyscale the images
	Mat *gs_images = new Mat[number_of_images];
	for (int i = 0; i < number_of_images; i++)
	{
		cvtColor(pool_image[i], gs_images[i], cv::COLOR_BGR2GRAY);
		imshow("Greyscale", gs_images[i]);
		waitKey(0);
	}

	// Next: Smooth the balls using Gaussian blur
	Mat *bl_images = new Mat[number_of_images];
	for (int i = 0; i < number_of_images; i++)
	{
		GaussianBlur(gs_images[i], bl_images[i], Size(5, 5), 1);
		imshow("Blurred images", bl_images[i]);
		waitKey(0);
	}
}