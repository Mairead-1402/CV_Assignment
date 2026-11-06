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
};

struct ImageInfo
{
	string filename;
	vector<PoolBall> pool_balls;
};

vector<ImageInfo>
	images = {
		{"AllBalls.jpeg", {{{253, 908}, "Yellow Solid"}, {{250, 959}, "Blue Solid"}, {{255, 1013}, "Red Solid"}, {{256, 1072}, "Purple Solid"}, {{254, 1132}, "Orange Solid"}, {{262, 1184}, "Green Solid"}, {{256, 1244}, "Brown Solid"}, {{253, 1307}, "Black"}, {{329, 901}, "Yellow Stripe"}, {{330, 961}, "Blue Stripe"}, {{335, 1013}, "Red Stripe"}, {{336, 1067}, "Purple Stripe"}, {{334, 1130}, "Orange Stripe"}, {{345, 1187}, "Green Stripe"}, {{342, 1245}, "Brown Stripe"}, {{293, 797}, "White"}}},

		{"Table1.jpeg", {{{309, 1092}, std::nullopt}, {{429, 1212}, std::nullopt}, {{383, 1131}, std::nullopt}, {{335, 1050}, std::nullopt}, {{285, 1211}, std::nullopt}, {{261, 1170}, std::nullopt}, {{352, 1173}, std::nullopt}, {{331, 1132}, std::nullopt}, {{240, 1210}, std::nullopt}, {{310, 1170}, std::nullopt}, {{407, 1169}, std::nullopt}, {{281, 1135}, std::nullopt}, {{374, 1212}, std::nullopt}, {{360, 1091}, std::nullopt}, {{331, 1213}, std::nullopt}, {{288, 29}, std::nullopt}}},

		{"Table2.jpeg", {{{282, 1103}, std::nullopt}, {{620, 1224}, std::nullopt}, {{391, 1121}, std::nullopt}, {{310, 1046}, std::nullopt}, {{310, 1305}, std::nullopt}, {{202, 621}, std::nullopt}, {{361, 1173}, std::nullopt}, {{331, 1132}, std::nullopt}, {{177, 725}, std::nullopt}, {{185, 1269}, std::nullopt}, {{665, 798}, std::nullopt}, {{296, 438}, std::nullopt}, {{53, 1235}, std::nullopt}, {{362, 1090}, std::nullopt}, {{399, 1205}, std::nullopt}, {{507, 1169}, std::nullopt}}},

		{"Table3.jpeg", {{{23, 908}, std::nullopt}, {{616, 1224}, std::nullopt}, {{447, 1199}, std::nullopt}, {{336, 29}, std::nullopt}, {{305, 1406}, std::nullopt}, {{210, 621}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{177, 725}, std::nullopt}, {{171, 1270}, std::nullopt}, {{665, 798}, std::nullopt}, {{249, 351}, std::nullopt}, {{53, 1233}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{434, 29}, std::nullopt}}},

		{"Table4.jpeg", {{{23, 908}, std::nullopt}, {{546, 1407}, std::nullopt}, {{444, 1204}, std::nullopt}, {{305, 1406}, std::nullopt}, {{210, 621}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{181, 724}, std::nullopt}, {{171, 1270}, std::nullopt}, {{665, 798}, std::nullopt}, {{249, 351}, std::nullopt}, {{58, 1231}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{88, 1392}, std::nullopt}}},

		{"Table5.jpeg", {{{535, 23}, std::nullopt}, {{546, 1407}, std::nullopt}, {{444, 1204}, std::nullopt}, {{305, 1406}, std::nullopt}, {{131, 25}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{538, 72}, std::nullopt}, {{171, 1270}, std::nullopt}, {{665, 798}, std::nullopt}, {{249, 351}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{608, 26}, std::nullopt}}},

		{"Table6.jpeg", {{{535, 23}, std::nullopt}, {{477, 1364}, std::nullopt}, {{444, 1204}, std::nullopt}, {{305, 1406}, std::nullopt}, {{131, 25}, std::nullopt}, {{260, 1294}, std::nullopt}, {{226, 1252}, std::nullopt}, {{538, 72}, std::nullopt}, {{171, 1270}, std::nullopt}, {{249, 351}, std::nullopt}, {{169, 901}, std::nullopt}, {{399, 1201}, std::nullopt}, {{629, 947}, std::nullopt}}}};

vector<ImageInfo>
	Testimages = {
		{"Table1.jpeg", {{{309, 1092}, "Yellow Solid"}, {{429, 1212}, "Blue Solid"}, {{383, 1131}, "Red Solid"}, {{335, 1050}, "Purple Solid"}, {{285, 1211}, "Orange Solid"}, {{261, 1170}, "Green Solid"}, {{352, 1173}, "Brown Solid"}, {{331, 1132}, "Black"}, {{240, 1210}, "Yellow Striped"}, {{310, 1170}, "Blue Striped"}, {{407, 1169}, "Red Striped"}, {{281, 1135}, "Purple Striped"}, {{374, 1212}, "Orange Striped"}, {{360, 1091}, "Green Striped"}, {{342, 1245}, "Brown Striped"}, {{288, 29}, "White"}}},

		{"Table2.jpeg", {{{282, 1103}, "Yellow Solid"}, {{620, 1224}, "Blue Solid"}, {{391, 1121}, "Red Solid"}, {{315, 1046}, "Purple Solid"}, {{310, 1305}, "Orange Solid"}, {{202, 621}, "Green Solid"}, {{361, 1173}, "Brown Solid"}, {{331, 1132}, "Black"}, {{177, 725}, "Yellow Striped"}, {{185, 1269}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{296, 438}, "Purple Striped"}, {{53, 1235}, "Orange Striped"}, {{362, 1090}, "Green Striped"}, {{399, 1205}, "Brown Striped"}, {{507, 1169}, "White"}}},

		{"Table3.jpeg", {{{23, 908}, "Yellow Solid"}, {{616, 1224}, "Blue Solid"}, {{447, 1199}, "Red Solid"}, {{336, 29}, "Purple Solid"}, {{305, 1406}, "Orange Solid"}, {{210, 621}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{177, 725}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{249, 351}, "Purple Striped"}, {{53, 1233}, "Orange Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{434, 29}, "White"}}},

		{"Table4.jpeg", {{{23, 908}, "Yellow Solid"}, {{546, 1407}, "Blue Solid"}, {{444, 1204}, "Red Solid"}, {{305, 1406}, "Orange Solid"}, {{210, 621}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{181, 724}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{249, 351}, "Purple Striped"}, {{58, 1231}, "Orange Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{88, 1392}, "White"}}},

		{"Table5.jpeg", {{{535, 23}, "Yellow Solid"}, {{546, 1407}, "Blue Solid"}, {{444, 1204}, "Red Solid"}, {{305, 1406}, "Orange Solid"}, {{131, 25}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{538, 72}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{249, 351}, "Purple Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{608, 26}, "White"}}},

		{"Table6.jpeg", {{{535, 23}, "Yellow Solid"}, {{477, 1364}, "Blue Solid"}, {{444, 1204}, "Red Solid"}, {{305, 1406}, "Orange Solid"}, {{131, 25}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{538, 72}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{249, 351}, "Purple Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{629, 947}, "White"}}}};

string classifyColour(double hue, double lightness)
{
	if (hue > 175 or hue < 5)
	{
		if (lightness < 100)
		{
			return "Brown";
		}
		else
		{
			return "Red";
		}
	}
	else if (hue >= 5 and hue < 15)
	{
		return "Orange";
	}
	else if (hue >= 15 and hue < 40)
	{
		return "Yellow";
	}
	else if (hue >= 40 and hue <= 90)
	{
		return "Green";
	}
	else if (hue > 90 and hue <= 125)
	{
		return "Blue";
	}
	else if (hue > 125 and hue <= 140)
	{
		return "Purple";
	}
	else
	{
		return "Colour Unknown";
	}
}

tuple<double, double, double, double> computeMetrics(int TP, int FP, int FN)
{
	double accuracy = TP / (double)(TP + FP + FN);

	double precision = TP / (double)(TP + FP);

	double recall = TP / (double)(TP + FN);

	double f1_score = 2 * ((precision * recall) / (double)(precision + recall));

	return {accuracy, precision, recall, f1_score};
}
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
		/* imshow("Greyscale", gs_images[i]);
		waitKey(0); */
	}

	// Next: Smooth the balls using Gaussian blur
	Mat *bl_images = new Mat[number_of_images];
	for (int i = 0; i < number_of_images; i++)
	{
		GaussianBlur(gs_images[i], bl_images[i], Size(5, 5), 1);
		/* imshow("Blurred images", bl_images[i]);
		waitKey(0); */
	}

	int distancelimit = 23;
	vector<Vec3f> tsCircles;
	vector<Point2f> tsDetectedCircles;
	vector<Vec3f> tsTruePositiveCircles;

	// Hough Circle Transform
	for (int i = 0; i < number_of_images; i++)
	{
		Mat displayImage = pool_image[i].clone();
		vector<Vec3f> circles;
		cv::HoughCircles(
			bl_images[i],
			circles,
			cv::HOUGH_GRADIENT,
			1, 35, 85, 15, 20, 24);
		if (i == 0)
		{
			tsCircles = circles;
		}
		vector<Point2f> detectedCenters(circles.size());
		vector<Point2f> tfCenters(circles.size());

		for (int j = 0; j < circles.size(); j++)
		{
			Vec3f c = circles[j];
			Point center(c[0], c[1]);
			detectedCenters[j] = Point2f(c[0], c[1]);

			circle(
				displayImage,
				center,
				1,
				Scalar(0, 100, 100),
				3,
				LINE_AA);

			int radius = c[2];

			circle(
				displayImage,
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

		if (i == 0)
		{
			tsDetectedCircles = tfCenters;
			tsTruePositiveCircles.resize(circles.size());
			int tpIndex = 0;
		}
		vector<Point2f> groundTruthCenters(images[i].pool_balls.size());

		vector<bool> matched(groundTruthCenters.size(), false);

		for (int j = 0; j < images[i].pool_balls.size(); j++)
		{
			PoolBall pool_ball = images[i].pool_balls[j];
			groundTruthCenters[j] = Point2f(pool_ball.position.column, pool_ball.position.row);
		}
		int tpIndex = 0;
		for (int k = 0; k < tfCenters.size(); k++)
		{
			Point2f dc = tfCenters[k];

			double minDistance = 10000000000.0;
			int nearestIndex = -1;

			for (int m = 0; m < groundTruthCenters.size(); m++)
			{
				if (matched[m])
				{
					continue;
				}

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

				if (i == 0)
				{
					tsTruePositiveCircles[tpIndex] = circles[k];
					tpIndex++;
				}
			}
		}
		if (i == 0)
		{
			tsTruePositiveCircles.resize(tpIndex);
		}

		int dclen = detectedCenters.size();
		int gtlen = groundTruthCenters.size();
		FP = dclen - TP;
		FN = gtlen - TP;

		int num_circles = circles.size();

		cout << "True positives: " << TP << endl;
		cout << "False positives: " << FP << endl;
		cout << "False Negatives: " << FN << endl;
		tuple metrics = computeMetrics(TP, FP, FN);

		cout << "Accuracy: " << get<0>(metrics) << endl;
		cout << "Precision: " << get<1>(metrics) << endl;
		cout << "Recall: " << get<2>(metrics) << endl;
		cout << "F1 Score: " << get<3>(metrics) << endl;
		imshow("Hough Transform Circles:", displayImage);
		waitKey(0);
	}

	// Recognising the balls
	// Use HLS to extract features from the AllBalls image then use it to classify other balls.
	//
	Mat training_perspective;
	Mat perspective_matrix = getPerspectiveTransform(source, destination);
	warpPerspective(pool_image[0], training_perspective, perspective_matrix, Size(1433, 682));

	// Tranform image into HLS
	Mat hls_image;
	cvtColor(training_perspective, hls_image, COLOR_BGR2HLS);
	imshow("HLS Training Image", hls_image);
	int num_circles = tsTruePositiveCircles.size();

	for (int i = 0; i < num_circles; i++)
	{
		Vec3f c = tsTruePositiveCircles[i];
		Point2f center(c[0], c[1]);

		vector<Point2f> src_points = {center};
		vector<Point2f> dst_points;

		perspectiveTransform(src_points, dst_points, perspective_matrix);

		Point2f tcenter = dst_points[0];

		int radius = (c[2] * 1);

		Mat mask = Mat::zeros(pool_image[0].size(), CV_8UC1);

		circle(mask, center, radius, Scalar(255), -1);

		Mat warpedMask;

		warpPerspective(
			mask,
			warpedMask,
			perspective_matrix,
			hls_image.size(),
			INTER_NEAREST);

		Mat debugImage = training_perspective.clone();

		vector<vector<Point>> contours;

		findContours(
			warpedMask.clone(),
			contours,
			RETR_EXTERNAL,
			CHAIN_APPROX_SIMPLE);

		drawContours(
			debugImage,
			contours,
			-1,
			Scalar(0, 0, 255),
			2);

		imshow("Ball 0 Mask Position", debugImage);
		waitKey(0);
		int maskPixels = countNonZero(warpedMask);

		if (maskPixels == 0)
			continue;

		Mat whiteMask;

		inRange(
			hls_image,
			Scalar(0, 190, 0),
			Scalar(179, 255, 180),
			whiteMask);

		bitwise_and(whiteMask, warpedMask, whiteMask);
		Mat nonWhiteMask;
		bitwise_not(whiteMask, nonWhiteMask);

		double whitePercentage =
			100.0 * countNonZero(whiteMask) / maskPixels;

		Mat darkMask;

		inRange(
			hls_image,
			Scalar(0, 0, 0),
			Scalar(179, 65, 255),
			darkMask);

		bitwise_and(darkMask, warpedMask, darkMask);

		double darkPercentage =
			100.0 * countNonZero(darkMask) / maskPixels;

		Mat colourMask;

		bitwise_and(warpedMask, nonWhiteMask, colourMask);

		Mat saturatedMask;

		inRange(
			hls_image,
			Scalar(0, 40, 80),
			Scalar(179, 220, 255),
			saturatedMask);

		bitwise_and(colourMask, warpedMask, colourMask);
		bitwise_and(colourMask, saturatedMask, colourMask);

		double colouredPercentage = 100.0 * countNonZero(colourMask) / maskPixels;

		cout << "Coloured Percentage: " << colouredPercentage << endl;

		double hue;
		double lightness;

		int validPixels = countNonZero(colourMask);
		if (validPixels > 0)
		{
			int channels[] = {0};
			int histSize[] = {36};

			float hueRange[] = {0, 180};
			const float *ranges[] = {hueRange};

			Mat hueHistogram;

			calcHist(
				&hls_image,
				1,
				channels,
				colourMask,
				hueHistogram,
				1,
				histSize,
				ranges);

			double maxValue = 0;
			Point maxLocation;

			minMaxLoc(
				hueHistogram,
				nullptr,
				&maxValue,
				nullptr,
				&maxLocation);

			int dominantHue = maxLocation.y * 5 + 2;

			hue = dominantHue;

			Scalar meanHLS = mean(hls_image, colourMask);

			lightness = meanHLS[1];

			cout << "Ball " << i << endl;
			cout << "White: " << whitePercentage << endl;
			cout << "Dark: " << darkPercentage << endl;
			cout << "Hue: " << dominantHue << endl;

			cout << "Mean Hue: " << meanHLS[0] << endl;
			cout << "Mean Lightness: " << meanHLS[1] << endl;
			cout << "Mean Saturation: " << meanHLS[2] << endl;
		}
		else
		{
			/* cout << "No valid coloured pixels found\n"
				 << endl; */
		}

		if (whitePercentage >= 60)
		{
			cout << "White" << endl;
		}
		else if (whitePercentage < 20 and darkPercentage >= 70)
		{
			cout << "Black" << endl;
		}
		else if (whitePercentage > 15 and whitePercentage < 60)
		{
			string colour = classifyColour(hue, lightness);
			cout << colour << " Striped" << endl;
		}
		else
		{
			string colour = classifyColour(hue, lightness);
			cout << colour << " Solid" << endl;
		}
	}

	// Check for all the other images
	Mat *tf_images = new Mat[number_of_images - 1];
	Mat *hls_images = new Mat[number_of_images - 1];
	for (int i = 1; i < number_of_images; i++)
	{

		int cTP = 0;
		int cFP = 0;
		int cFN = 0;

		cout << "Image " << i << endl;
		Mat displayImage = pool_image[i].clone();
		vector<Vec3f> circles;
		cv::HoughCircles(
			bl_images[i],
			circles,
			cv::HOUGH_GRADIENT,
			1, 35, 85, 15, 19, 26);
		vector<Point2f> detectedCenters(circles.size());
		vector<Point2f> tfCenters(circles.size());

		for (int j = 0; j < circles.size(); j++)
		{
			Vec3f c = circles[j];
			Point center(c[0], c[1]);
			detectedCenters[j] = Point2f(c[0], c[1]);
			vector<Point2f> tfCenters;
			circle(
				displayImage,
				center,
				1,
				Scalar(0, 100, 100),
				3,
				LINE_AA);

			int radius = c[2];

			circle(
				displayImage,
				center,
				radius,
				Scalar(255, 0, 255),
				3,
				LINE_AA);
		}
		perspectiveTransform(
			detectedCenters,
			tfCenters,
			perspective_matrix);
		warpPerspective(pool_image[i], tf_images[i - 1], perspective_matrix, Size(1433, 682));
		cvtColor(tf_images[i - 1], hls_images[i - 1], COLOR_BGR2HLS);

		imshow("TF Image ", tf_images[i - 1]);
		waitKey(0);
		Mat &currentHLS = hls_images[i - 1];
		int num_circles = circles.size();
		vector<Point2f> groundTruthCenters(Testimages[i - 1].pool_balls.size());
		vector<string> trueColours(Testimages[i - 1].pool_balls.size());

		vector<bool> matched(groundTruthCenters.size(), false);

		for (int j = 0; j < Testimages[i - 1].pool_balls.size(); j++)
		{
			PoolBall pool_ball = Testimages[i - 1].pool_balls[j];
			groundTruthCenters[j] = Point2f(pool_ball.position.column, pool_ball.position.row);
			trueColours[j] = pool_ball.colour.value_or("Unkown");
		}
		for (int k = 0; k < num_circles; k++)
		{
			Vec3f c = circles[k];
			Point2f center(c[0], c[1]);

			vector<Point2f> src_points = {center};
			vector<Point2f> dst_points;

			perspectiveTransform(src_points, dst_points, perspective_matrix);

			Point2f tcenter = dst_points[0];

			int radius = (c[2] * 1);

			Mat mask = Mat::zeros(pool_image[i].size(), CV_8UC1);

			circle(mask, center, radius, Scalar(255), -1);

			Mat result;
			bitwise_and(pool_image[i], pool_image[i], result, mask);

			imshow("Result", result);
			waitKey(0);
			Mat warpedMask;

			warpPerspective(
				mask,
				warpedMask,
				perspective_matrix,
				currentHLS.size(),
				INTER_NEAREST);

			Mat maskedTFImage;

			bitwise_and(
				tf_images[i - 1],
				tf_images[i - 1],
				maskedTFImage,
				warpedMask);

			imshow("Warped Mask", warpedMask);
			imshow("Masked Transformed Image", maskedTFImage);
			waitKey(0);

			int maskPixels = countNonZero(warpedMask);

			if (maskPixels == 0)
				continue;

			Mat whiteMask;

			inRange(
				currentHLS,
				Scalar(0, 160, 0),
				Scalar(179, 255, 80),
				whiteMask);

			bitwise_and(whiteMask, warpedMask, whiteMask);
			Mat nonWhiteMask;
			bitwise_not(whiteMask, nonWhiteMask);

			double whitePercentage =
				100.0 * countNonZero(whiteMask) / maskPixels;

			Mat darkMask;

			inRange(
				currentHLS,
				Scalar(0, 0, 0),
				Scalar(179, 65, 255),
				darkMask);

			bitwise_and(darkMask, warpedMask, darkMask);

			double darkPercentage =
				100.0 * countNonZero(darkMask) / maskPixels;

			Mat colourMask;

			bitwise_and(warpedMask, nonWhiteMask, colourMask);

			Mat saturatedMask;

			inRange(
				currentHLS,
				Scalar(0, 40, 80),
				Scalar(179, 220, 255),
				saturatedMask);

			bitwise_and(colourMask, warpedMask, colourMask);
			bitwise_and(colourMask, saturatedMask, colourMask);

			double colouredPercentage = 100.0 * countNonZero(colourMask) / maskPixels;

			/* cout << "Coloured Percentage: " << colouredPercentage << endl; */

			double hue;
			double lightness;

			string colour;
			int validPixels = countNonZero(colourMask);
			if (validPixels > 0)
			{
				int channels[] = {0};
				int histSize[] = {36};

				float hueRange[] = {0, 180};
				const float *ranges[] = {hueRange};

				Mat hueHistogram;

				calcHist(
					&currentHLS,
					1,
					channels,
					colourMask,
					hueHistogram,
					1,
					histSize,
					ranges);

				double maxValue = 0;
				Point maxLocation;

				minMaxLoc(
					hueHistogram,
					nullptr,
					&maxValue,
					nullptr,
					&maxLocation);

				int dominantHue = maxLocation.y * 5 + 2;

				hue = dominantHue;

				Scalar meanHLS = mean(currentHLS, colourMask);

				lightness = meanHLS[1];

				/* 	cout << "Ball " << k << endl;
					cout << "White: " << whitePercentage << endl;
					cout << "Dark: " << darkPercentage << endl;
					cout << "Hue: " << dominantHue << endl;

					cout << "Mean Hue: " << meanHLS[0] << endl;
					cout << "Mean Lightness: " << meanHLS[1] << endl;
					cout << "Mean Saturation: " << meanHLS[2] << endl; */
			}
			else
			{
				/* cout << "No valid coloured pixels found\n"
				<< endl; */
				cFP++;
				continue;
			}

			if (whitePercentage >= 60)
			{
				colour = "White";
			}
			else if (whitePercentage < 20 and darkPercentage >= 70)
			{
				colour = "Black";
			}
			else if (whitePercentage >= 15 and whitePercentage < 60)
			{
				colour = classifyColour(hue, lightness) + " Striped";
			}
			else
			{
				colour = classifyColour(hue, lightness) + " Solid";
			}

			int tpIndex = 0;

			Point2f dc = tfCenters[k];

			double minDistance = 10000000000.0;
			int nearestIndex = -1;

			for (int m = 0; m < groundTruthCenters.size(); m++)
			{
				if (matched[m])
				{
					continue;
				}

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
				string trueColour = trueColours[nearestIndex];
				cout << "Detected Colour: " << colour << endl;
				cout << "True Colour: " << trueColour << endl;
				if (trueColour == colour)
				{
					cTP++;
				}
				else
				{
					cFP++;
					cFN++;
				}
			}
			else
			{
				cFP++;
			}
		}
		for (int m = 0; m < matched.size(); m++)
		{
			if (!matched[m])
			{
				cFN++;
			}
		}
		cout << "Image " << i << endl;
		cout << "True positives: " << cTP << endl;
		cout << "False positives: " << cFP << endl;
		cout << "False Negatives: " << cFN << endl;

		tuple metrics = computeMetrics(cTP, cFP, cFN);

		cout << "Accuracy: " << get<0>(metrics) << endl;
		cout << "Precision: " << get<1>(metrics) << endl;
		cout << "Recall: " << get<2>(metrics) << endl;
		cout << "F1 Score: " << get<3>(metrics) << endl;
	}
}