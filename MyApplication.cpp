#include "Utilities.h"

struct Coordinate
{
	int row;
	int column;
};

struct PoolBall
{
	Coordinate position;
	std::optional<std::string> colour;
}

struct ImageInfo
{
	string filename;
	vector<Coordinate> pool_balls;
};

vector<ImageInfo> images = {
	{"AllBalls.jpeg", {{{253, 908}, "yellow solid"}, {{250, 959}, "blue solid"}, {{255, 1013}, "red solid"}, {{256, 1072}, "purple solid"}, {{254, 1132}, "orange solid"}, {{262, 1184}, "green solid"}, {{256, 1244}, "burgandy solid"}, {{253, 1307}, "grey solid"}, {{329, 901}, "yellow stripe"}, {{330, 961}, "blue stripe"}, {{334, 1130}, "red stripe"}, {{335, 1013}, "purple stripe"}, {{336, 1067}, "orange stripe"}, {{342, 1245}, "green stripe"}, {{345, 1187}, "burgandy stripe"}, {{293, 797}, "white"}}},

	{"Table1.jpeg", {{{309, 1092}, std::nullopt}, {{429, 1212}, std::nullopt}, {{353, 1174}, std::nullopt}, {{335, 1050}, std::nullopt}, {{285, 1211}, std::nullopt}, {{261, 1170}, std::nullopt}, {{352, 1173}, std::nullopt}, {{331, 1132}, std::nullopt}, {{240, 1210}, std::nullopt}, {{310, 1170}, std::nullopt}, {{407, 1169}, std::nullopt}, {{281, 1135}, std::nullopt}, {{374, 1212}, std::nullopt}, {{360, 1091}, std::nullopt}, {{331, 1213}, std::nullopt}, {{288, 29}, std::nullopt}}},

	{"Table2.jpeg", {{{282, 1103}, std::nullopt}, {{620, 1224}, std::nullopt}, {{391, 1121}, std::nullopt}, {{310, 1305}, std::nullopt}, {{315, 1046}, std::nullopt}, {{202, 621}, std::nullopt}, {{361, 1173}, std::nullopt}, {{331, 1132}, std::nullopt}, {{177, 725}, std::nullopt}, {{185, 1269}, std::nullopt}, {{665, 798}, std::nullopt}, {{296, 438}, std::nullopt}, {{53, 1235}, std::nullopt}, {{362, 1090}, std::nullopt}, {{399, 1205}, std::nullopt}, {{507, 1169}, std::nullopt}}},

	{"Table3.jpeg", {{{23, 908}, std::nullopt}, {{616, 1224}, std::nullopt}, {{447, 1199}, std::nullopt}, {{336, 29}, std::nullopt}, {{305, 1406}, std::nullopt}, {{210, 621}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{177, 725}, std::nullopt}, {{171, 1270}, std::nullopt}, {{665, 798}, std::nullopt}, {{249, 351}, std::nullopt}, {{53, 1233}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{434, 29}, std::nullopt}}},

	{"Table4.jpeg", {{{23, 908}, std::nullopt}, {{546, 1407}, std::nullopt}, {{444, 1204}, std::nullopt}, {{305, 1406}, std::nullopt}, {{210, 621}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{181, 724}, std::nullopt}, {{171, 1270}, std::nullopt}, {{665, 798}, std::nullopt}, {{249, 351}, std::nullopt}, {{58, 1231}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{88, 1392}, std::nullopt}}},

	{"Table5.jpeg", {{{535, 23}, std::nullopt}, {{546, 1407}, std::nullopt}, {{444, 1204}, std::nullopt}, {{305, 1406}, std::nullopt}, {{131, 25}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{538, 72}, std::nullopt}, {{171, 1270}, std::nullopt}, {{665, 798}, std::nullopt}, {{249, 351}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{608, 26}, std::nullopt}}},

	{"Table6.jpeg", {{{535, 23}, std::nullopt}, {{477, 1364}, std::nullopt}, {{444, 1204}, std::nullopt}, {{305, 1406}, std::nullopt}, {{131, 25}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{538, 72}, std::nullopt}, {{171, 1270}, std::nullopt}, {{249, 351}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{629, 947}, std::nullopt}}}};

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

	// Points for transforming the images
	Point2f source[4] = {
		Point2f(337, 35),
		Point2f(38, 472),
		Point2f(1570, 21),
		Point2f(1888, 451)};

	Point2f destination[4] = {
		Point2f(0, 0),
		Point2f(0, 682),
		Point2f(1433, 0),
		Point2f(1433, 682)};

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

	int distancelimit = 23;

	// Hough Circle Transform
	for (int i = 0; i < number_of_images; i++)
	{
		vector<Vec3f> circles;
		cv::HoughCircles(
			bl_images[i],
			circles,
			cv::HOUGH_GRADIENT,
			1, 35, 85, 15, 19, 25);

		vector<Point2f> detectedCenters(circles.size());
		vector<Point2f> tfCenters(circles.size());

		for (int j = 0; j < circles.size(); j++)
		{
			Vec3f c = circles[j];
			Point center(c[0], c[1]);
			detectedCenters[j] = Point2f(c[0], c[1]);

			circle(
				pool_image[i],
				center,
				1,
				Scalar(0, 100, 100),
				3,
				LINE_AA);

			int radius = c[2];

			circle(
				pool_image[i],
				center,
				radius,
				Scalar(255, 0, 255),
				3,
				LINE_AA);
		}

		double TP = 0;
		double FN = 0;
		double FP = 0;

		Mat perspective_matrix = getPerspectiveTransform(source, destination);
		perspectiveTransform(detectedCenters, tfCenters, perspective_matrix);

		vector<Point2f> groundTruthCenters(images[i].pool_balls.size());

		vector<bool> matched(groundTruthCenters.size(), false);

		for (int j = 0; j < images[i].pool_balls.size(); j++)
		{
			Coordinate pool_ball = images[i].pool_balls[j];
			groundTruthCenters[j] = Point2f(pool_ball.column, pool_ball.row);
		}
		for (int k = 0; k < tfCenters.size(); k++)
		{
			Point2f dc = tfCenters[k];

			double minDistance = 10000000000.0;
			int nearestIndex = -1;

			for (int m = 0; m < groundTruthCenters.size(); m++)
			{
				if (matched[m])
					continue;

				Point2f tfc = groundTruthCenters[m];

				double pointdistance = cv::norm(tfc - dc);

				if (pointdistance < minDistance)
				{
					minDistance = pointdistance;
					nearestIndex = m;
				}
			}

			if (nearestIndex != -1 && minDistance < distancelimit)
			{
				matched[nearestIndex] = true;
				TP++;
			}
		}

		int dclen = detectedCenters.size();
		int gtlen = groundTruthCenters.size();
		FP = dclen - TP;
		FN = gtlen - TP;

		int num_circles = circles.size();

		cout << "True positives: " << TP << endl;
		cout << "False positives: " << FP << endl;
		cout << "False Negatives: " << FN << endl;
		imshow("Hough Transform Circles:", pool_image[i]);
		waitKey(0);
	}
}