#include "Utilities.h"
#include <map>

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

struct ColourReference
{
	string name;
	Vec3f bgr;
};

const vector<ColourReference> colourReferences = {
	{"Red", Vec3f(64, 60, 227)},
	{"Blue", Vec3f(101, 37, 29)},
	{"Purple", Vec3f(83, 38, 58)},
	{"Yellow", Vec3f(34, 171, 242)},
	{"Green", Vec3f(57, 82, 64)},
	{"Orange", Vec3f(51, 106, 219)},
	{"Brown", Vec3f(43, 42, 101)}};

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
		{"Table1.jpeg", {{{309, 1092}, "Yellow Solid"}, {{429, 1212}, "Blue Solid"}, {{383, 1131}, "Red Solid"}, {{335, 1050}, "Purple Solid"}, {{285, 1211}, "Orange Solid"}, {{261, 1170}, "Green Solid"}, {{352, 1173}, "Brown Solid"}, {{331, 1132}, "Black"}, {{240, 1210}, "Yellow Striped"}, {{310, 1170}, "Blue Striped"}, {{407, 1169}, "Red Striped"}, {{281, 1135}, "Purple Striped"}, {{374, 1212}, "Orange Striped"}, {{360, 1091}, "Green Striped"}, {{331, 1213}, "Brown Striped"}, {{288, 29}, "White"}}},

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

tuple<double, double, double> computeMetrics(int TP, int FP, int FN)
{

	double precision = TP / (double)(TP + FP);

	double recall = TP / (double)(TP + FN);

	double f1_score = 2 * ((precision * recall) / (double)(precision + recall));

	return {precision, recall, f1_score};
}

string predictColour(
	const cv::Vec3f &dominantBGR,
	const std::string &ballType)
{
	if (ballType == "White")
		return "White";

	if (ballType == "Black")
		return "Black";

	if (ballType == "Unknown")
		return "Unknown";

	double minDistance = DBL_MAX;
	std::string predictedColour = "Unknown";

	for (const auto &reference : colourReferences)
	{
		double distance = cv::norm(
			dominantBGR - reference.bgr);

		if (distance < minDistance)
		{
			minDistance = distance;
			predictedColour = reference.name;
		}
	}

	return predictedColour;
}

struct RecognitionResult
{
	int correct = 0;
	int incorrect = 0;
	int notDetected = 0;
};
map<string, RecognitionResult> kmrecognitionResults;

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
	vector<Vec3f> tsCircles;
	vector<Point2f> tsDetectedCircles;
	vector<Vec3f> tsTruePositiveCircles;

	double avTP = 0;
	double avFP = 0;
	double avFN = 0;
	double avP = 0;
	double avR = 0;
	double avF1 = 0;

	// Hough Circle Transform
	for (int i = 0; i < number_of_images; i++)
	{
		Mat displayImage = pool_image[i].clone();
		Mat displayImage2 = pool_image[i].clone();
		vector<Vec3f> circles;
		cv::HoughCircles(
			bl_images[i],
			circles,
			cv::HOUGH_GRADIENT,
			1, 25, 65, 15, 20, 24);
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
				displayImage2,
				center,
				1,
				Scalar(0, 100, 100),
				3,
				LINE_AA);

			circle(
				displayImage,
				center,
				1,
				Scalar(0, 100, 100),
				3,
				LINE_AA);

			int radius = c[2];

			circle(
				displayImage2,
				center,
				radius,
				Scalar(255, 0, 255),
				3,
				LINE_AA);
		}

		imshow("Hough Transform Circles:", displayImage);
		waitKey(0);

		double TP = 0;
		double FN = 0;
		double FP = 0;

		Mat perspective_matrix = getPerspectiveTransform(source, destination);
		perspectiveTransform(detectedCenters, tfCenters, perspective_matrix);
		int tpIndex = 0;
		if (i == 0)
		{
			tsDetectedCircles = tfCenters;
			tsTruePositiveCircles.resize(circles.size());
		}
		vector<Point2f> groundTruthCenters(images[i].pool_balls.size());

		vector<bool> matched(groundTruthCenters.size(), false);

		for (int j = 0; j < images[i].pool_balls.size(); j++)
		{
			PoolBall pool_ball = images[i].pool_balls[j];
			groundTruthCenters[j] = Point2f(pool_ball.position.column, pool_ball.position.row);
		}

		Mat inverseH = perspective_matrix.inv();

		vector<Point2f> transformedGT;

		for (const auto &gt : groundTruthCenters)
		{
			transformedGT.emplace_back(gt.x, gt.y);
		}

		vector<Point2f> originalGT;

		perspectiveTransform(
			transformedGT,
			originalGT,
			inverseH);
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

				cv::circle(
					displayImage, Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)), cvRound(circles[k][2]),
					cv::Scalar(0, 255, 0), 2);

				cv::putText(
					displayImage, "TP", Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)) + cv::Point(5, -10),
					cv::FONT_HERSHEY_SIMPLEX, 0.5,
					cv::Scalar(0, 255, 0), 2);

				if (i == 0)
				{
					tsTruePositiveCircles[tpIndex] = circles[k];
					tpIndex++;
				}
			}
			else
			{
				FP++;
				cv::circle(
					displayImage, Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)), 15,
					cv::Scalar(0, 0, 255), 2);

				cv::putText(
					displayImage, "FP", Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)) + cv::Point(5, -10),
					cv::FONT_HERSHEY_SIMPLEX, 0.5,
					cv::Scalar(0, 0, 255), 2);
			}
		}
		for (int m = 0; m < matched.size(); m++)
		{
			if (!matched[m])
			{
				FN++;

				Point fnCenter(
					cvRound(originalGT[m].x),
					cvRound(originalGT[m].y));

				circle(
					displayImage, fnCenter, 22,
					cv::Scalar(255, 0, 0), 2);

				putText(
					displayImage, "FN",
					fnCenter + cv::Point(5, -10),
					cv::FONT_HERSHEY_SIMPLEX, 0.5,
					cv::Scalar(255, 0, 0), 2);
			}
		}
		if (i == 0)
		{
			tsTruePositiveCircles.resize(tpIndex);
		}

		if (i != 0)
		{
			avTP = avTP + TP;
			avFP = avFP + FP;
			avFN = avFN + FN;
		}

		cout << "True positives: " << TP << endl;
		cout << "False positives: " << FP << endl;
		cout << "False Negatives: " << FN << endl;
		tuple metrics = computeMetrics(TP, FP, FN);

		cout << "Precision: " << get<0>(metrics) << endl;
		cout << "Recall: " << get<1>(metrics) << endl;
		cout << "F1 Score: " << get<2>(metrics) << endl;
		if (i != 0)
		{
			avP = avP + get<0>(metrics);
			avR = avR + get<1>(metrics);
			avF1 = avF1 + get<2>(metrics);
		}
		imshow("Hough Transform Circles:", displayImage);
		waitKey(0);
	}

	avTP = (double)avTP / 6;
	cout << "Average number of True Positives: " << avTP << endl;
	avFP = (double)avFP / 6;
	cout << "Average number of False Positives: " << avFP << endl;
	avFN = (double)avFN / 6;
	cout << "Average number of False Negatives: " << avFN << endl;
	avP = (double)avP / 6;
	cout << "Average Precision: " << avP << endl;
	avR = (double)avR / 6;
	cout << "Average Recall: " << avR << endl;
	avF1 = (double)avF1 / 6;
	cout << "Average F1 Score: " << avF1 << endl;

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

		imshow("Ball Mask Position", debugImage);
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

		imshow("White Mask", whiteMask);

		double whitePercentage =
			100.0 * countNonZero(whiteMask) / maskPixels;

		Mat darkMask;

		inRange(
			hls_image,
			Scalar(0, 0, 0),
			Scalar(179, 65, 255),
			darkMask);

		bitwise_and(darkMask, warpedMask, darkMask);

		imshow("Dark Mask", darkMask);

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

		bitwise_and(colourMask, saturatedMask, colourMask);

		imshow("Colour Mask", colourMask);

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

			int histWidth = 720;
			int histHeight = 400;
			int binWidth = histWidth / histSize[0];

			// Black background
			Mat histImage(histHeight, histWidth,
						  CV_8UC3, Scalar(0, 0, 0));

			// Normalize histogram for display
			Mat normalizedHist;
			normalize(hueHistogram, normalizedHist,
					  0, histHeight - 20, NORM_MINMAX);

			// Draw colored bars
			for (int i = 0; i < histSize[0]; i++)
			{
				int barHeight = cvRound(normalizedHist.at<float>(i));

				// Hue at the center of this bin
				int hue = i * 5 + 2;

				// Convert HLS Hue to BGR for drawing
				Mat hlsColor(1, 1, CV_8UC3,
							 Scalar(hue, 128, 255));

				Mat bgrColor;
				cvtColor(hlsColor, bgrColor, COLOR_HLS2BGR);

				Vec3b color = bgrColor.at<Vec3b>(0, 0);

				rectangle(
					histImage,
					Point(i * binWidth, histHeight - barHeight),
					Point((i + 1) * binWidth - 1, histHeight - 1),
					Scalar(color[0], color[1], color[2]),
					FILLED);
			}

			// Highlight dominant Hue bin
			int dominantBin = maxLocation.y;
			int dominantHeight =
				cvRound(normalizedHist.at<float>(dominantBin));

			rectangle(
				histImage,
				Point(dominantBin * binWidth,
					  histHeight - dominantHeight),
				Point((dominantBin + 1) * binWidth - 1,
					  histHeight - 1),
				Scalar(255, 255, 255),
				2);

			imshow("Hue Histogram", histImage);

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

	double dhTP = 0;
	double dhFP = 0;
	double dhFN = 0;
	double dhP = 0;
	double dhR = 0;
	double dhF1 = 0;
	double dhCA = 0;
	// Check for all the other images
	Mat *tf_images = new Mat[number_of_images - 1];
	Mat *hls_images = new Mat[number_of_images - 1];
	for (int i = 1; i < number_of_images; i++)
	{

		int cTP = 0;
		int cFP = 0;
		int cFN = 0;
		int totalEvaluated = 0;
		int correctPredictions = 0;
		cout << "Image " << i << endl;
		Mat displayImage = pool_image[i].clone();
		vector<Vec3f> circles;
		cv::HoughCircles(
			bl_images[i],
			circles,
			cv::HOUGH_GRADIENT,
			1, 25, 65, 15, 20, 24);
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
				totalEvaluated++;
				matched[nearestIndex] = true;
				string trueColour = trueColours[nearestIndex];
				cout << "Detected Colour: " << colour << endl;
				cout << "True Colour: " << trueColour << endl;
				if (trueColour == colour)
				{
					cTP++;
					correctPredictions++;
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
		dhTP = dhTP + cTP;
		dhFP = dhFP + cFP;
		dhFN = dhFN + cFN;
		tuple metrics = computeMetrics(cTP, cFP, cFN);

		dhP = dhP + get<0>(metrics);
		dhR = dhR + get<1>(metrics);
		dhF1 = dhF1 + get<2>(metrics);
		cout << "Precision: " << get<0>(metrics) << endl;
		cout << "Recall: " << get<1>(metrics) << endl;
		cout << "F1 Score: " << get<2>(metrics) << endl;

		double colourAccuracy = 100 * correctPredictions / (double)totalEvaluated;
		dhCA = dhCA + colourAccuracy;

		cout << "Colour Accuracy: " << colourAccuracy << "%" << endl;
	}

	dhTP = dhTP / 6;
	cout << "Average number of True Positives: " << dhTP << endl;
	dhFP = dhFP / 6;
	cout << "Average number of False Positives: " << dhFP << endl;
	dhFN = dhFN / 6;
	cout << "Average number of False Negatives: " << dhFN << endl;

	dhP = dhP / 6;
	cout << "Average Precision: " << dhP << endl;
	dhR = dhR / 6;
	cout << "Average Recall: " << dhR << endl;
	dhF1 = dhF1 / 6;
	cout << "Average F1 Score: " << dhF1 << endl;

	dhCA = dhCA / 6;
	cout << "Overall Colour Average " << dhCA << endl;

	Mat ts_km_tf_image;

	warpPerspective(
		pool_image[0],
		ts_km_tf_image,
		perspective_matrix,
		Size(1433, 682));

	Mat hsv_image;
	cvtColor(ts_km_tf_image, hsv_image, COLOR_BGR2HSV);

	int k = 3;

	for (int i = 0; i < tsCircles.size(); i++)
	{

		Vec3f c = tsCircles[i];

		Point2f originalCentre(c[0], c[1]);
		float originalRadius = c[2];

		vector<Point2f> originalPoints = {
			originalCentre,
			Point2f(c[0] + originalRadius, c[1]),
			Point2f(c[0] - originalRadius, c[1]),
			Point2f(c[0], c[1] + originalRadius),
			Point2f(c[0], c[1] - originalRadius)};

		vector<Point2f> transformedPoints;

		perspectiveTransform(
			originalPoints,
			transformedPoints,
			perspective_matrix);

		Point2f transformedCentre = transformedPoints[0];

		Point centre(
			cvRound(transformedCentre.x),
			cvRound(transformedCentre.y));

		float radiusSum = 0.0f;

		for (int j = 1; j < transformedPoints.size(); j++)
		{
			radiusSum += norm(
				transformedPoints[j] - transformedCentre);
		}

		float transformedRadius = radiusSum / 4.0f;
		int radius = cvRound(transformedRadius * 0.9f);

		Mat mask = Mat::zeros(
			ts_km_tf_image.size(),
			CV_8UC1);

		circle(
			mask,
			centre,
			radius,
			Scalar(255),
			-1);

		vector<Vec3f> pixels;
		vector<Vec3f> colouredPixels;

		int whiteCount = 0;
		int blackCount = 0;
		int colourCount = 0;
		int totalPixels = 0;
		int saturatedCount = 0;
		Mat debugImage = ts_km_tf_image.clone();

		circle(
			debugImage,
			centre,
			radius,
			Scalar(0, 255, 255),
			2);

		imshow("Detected Circle", debugImage);
		imshow("Circle Mask", mask);
		waitKey(0);
		Rect bounds = Rect(
						  centre.x - radius,
						  centre.y - radius,
						  radius * 2 + 1,
						  radius * 2 + 1) &
					  Rect(0, 0, mask.cols, mask.rows);

		for (int y = bounds.y; y < bounds.y + bounds.height; y++)
		{
			for (int x = bounds.x; x < bounds.x + bounds.width; x++)
			{
				if (mask.at<uchar>(y, x) == 0)
					continue;

				totalPixels++;

				Vec3b bgr = ts_km_tf_image.at<Vec3b>(y, x);
				Vec3b hsv = hsv_image.at<Vec3b>(y, x);
				Vec3f pixel(
					static_cast<float>(bgr[0]), // Blue
					static_cast<float>(bgr[1]), // Green
					static_cast<float>(bgr[2])	// Red
				);

				pixels.push_back(pixel);
				int saturation = hsv[1];
				int value = hsv[2];
				if (saturation > 110 && value > 65)
				{
					saturatedCount++;
				}

				if (value < 75)
				{
					blackCount++;
				}

				else if (saturation < 110 && value > 115)
				{
					whiteCount++;
				}

				else
				{
					colourCount++;
					colouredPixels.push_back(pixel);
				}
			}
		}

		if (totalPixels == 0)
			continue;

		double saturatedPercentage =
			100.0 * saturatedCount / totalPixels;

		double whitePercentage =
			100.0 * whiteCount / totalPixels;

		double blackPercentage =
			100.0 * blackCount / totalPixels;

		double colourPercentage =
			100.0 * colourCount / totalPixels;

		Scalar meanHSV = mean(hsv_image, mask);

		double meanSaturation = meanHSV[1];
		double meanBrightness = meanHSV[2];

		string ballType = "Unknown";

		if (whitePercentage >= 80.0 &&
			meanSaturation < 90.0 &&
			meanBrightness > 135.0)
		{
			ballType = "White";
		}
		else if (blackPercentage >= 40.0 &&
				 meanBrightness < 110.0 &&
				 saturatedPercentage < 15.0)
		{
			ballType = "Black";
		}
		else if (whitePercentage >= 20.0 &&
				 colourPercentage >= 10.0)
		{
			ballType = "Striped";
		}
		else if (colourPercentage >= 50.0 ||
				 saturatedPercentage >= 15.0)
		{
			ballType = "Solid";
		}

		cout << "Circle " << i << endl;
		cout << "Ball Type: " << ballType << endl;
		cout << "White Pixels: " << whiteCount << endl;
		cout << "Black Pixels: " << blackCount << endl;
		cout << "Colour Pixels: " << colourCount << endl;
		cout << "Total Pixels: " << totalPixels << endl;

		cout << "White Percentage: "
			 << whitePercentage << "%" << endl;

		cout << "Black Percentage: "
			 << blackPercentage << "%" << endl;

		cout << "Colour Percentage: "
			 << colourPercentage << "%" << endl;

		cout << "Saturated Percentage: "
			 << saturatedPercentage << "%" << endl;

		const vector<Vec3f> &selectedPixels =
			(ballType == "Solid" || ballType == "Striped") && colouredPixels.size() >= k
				? colouredPixels
				: pixels;

		if (selectedPixels.size() < k)
			continue;

		Mat samples(
			static_cast<int>(selectedPixels.size()),
			3,
			CV_32F);

		for (int j = 0; j < samples.rows; j++)
		{
			samples.at<float>(j, 0) = selectedPixels[j][0];
			samples.at<float>(j, 1) = selectedPixels[j][1];
			samples.at<float>(j, 2) = selectedPixels[j][2];
		}

		Mat labels, centres;

		kmeans(
			samples,
			k,
			labels,
			TermCriteria(
				TermCriteria::COUNT | TermCriteria::EPS,
				100,
				0.0001),
			10,
			KMEANS_PP_CENTERS,
			centres);

		vector<int> counts(k, 0);

		for (int m = 0; m < labels.rows; m++)
		{
			int cluster = labels.at<int>(m, 0);
			counts[cluster]++;
		}

		int dominantCluster = static_cast<int>(
			max_element(counts.begin(), counts.end()) - counts.begin());

		float blue =
			centres.at<float>(dominantCluster, 0);

		float green =
			centres.at<float>(dominantCluster, 1);

		float red =
			centres.at<float>(dominantCluster, 2);

		cout << "\nCircle " << i << endl;
		cout << "Ball Type: " << ballType << endl;

		cout << "Dominant Blue: " << blue << endl;
		cout << "Dominant Green: " << green << endl;
		cout << "Dominant Red: " << red << endl;
		cout << "Mean Saturation: " << meanHSV[1] << endl;
		cout << "Mean Brightness: " << meanHSV[2] << endl;
		cout << "Black Percentage: " << blackPercentage << "%" << endl;
		cout << "White: " << whitePercentage << "%" << endl;
		cout << "Black: " << blackPercentage << "%" << endl;
		cout << "Coloured: " << colourPercentage << "%" << endl;

		cout << "------------------------" << endl;

		putText(
			ts_km_tf_image,
			ballType,
			Point(centre.x - radius, centre.y - radius - 10),
			FONT_HERSHEY_SIMPLEX,
			0.5,
			Scalar(0, 255, 255),
			2);
	}

	imshow("Classified Pool Balls", ts_km_tf_image);
	waitKey(0);

	double kmTP = 0;
	double kmFP = 0;
	double kmFN = 0;
	double kmP = 0;
	double kmR = 0;
	double kmF1 = 0;
	double kmCA = 0;

	Mat *km_tf_images = new Mat[number_of_images - 1];
	for (int i = 1; i < number_of_images; i++)
	{
		int cTP = 0;
		int cFP = 0;
		int cFN = 0;

		int totalEvaluated = 0;
		int correctPredictions = 0;

		vector<bool> matched(
			Testimages[i - 1].pool_balls.size(), false);

		Mat displayImage = pool_image[i].clone();
		vector<Vec3f> circles;
		cv::HoughCircles(
			bl_images[i],
			circles,
			cv::HOUGH_GRADIENT,
			1, 25, 65, 15, 20, 24);

		int num_circles = circles.size();
		vector<Point2f> groundTruthCenters(Testimages[i - 1].pool_balls.size());
		vector<string> trueColours(Testimages[i - 1].pool_balls.size());

		for (int j = 0; j < Testimages[i - 1].pool_balls.size(); j++)
		{
			PoolBall pool_ball = Testimages[i - 1].pool_balls[j];
			groundTruthCenters[j] = Point2f(pool_ball.position.column, pool_ball.position.row);
			trueColours[j] = pool_ball.colour.value_or("Unkown");
		}

		warpPerspective(
			pool_image[i],
			km_tf_images[i - 1],
			perspective_matrix,
			Size(1433, 682));

		Mat hsv_image;
		cvtColor(km_tf_images[i - 1], hsv_image, COLOR_BGR2HSV);

		int k = 3;

		for (int n = 0; n < circles.size(); n++)
		{

			Vec3f c = circles[n];

			Point2f originalCentre(c[0], c[1]);
			float originalRadius = c[2];
			vector<Point2f> originalPoints = {
				originalCentre,
				Point2f(c[0] + originalRadius, c[1]),
				Point2f(c[0] - originalRadius, c[1]),
				Point2f(c[0], c[1] + originalRadius),
				Point2f(c[0], c[1] - originalRadius)};

			vector<Point2f> transformedPoints;

			perspectiveTransform(
				originalPoints,
				transformedPoints,
				perspective_matrix);

			Point2f transformedCentre = transformedPoints[0];

			Point centre(
				cvRound(transformedCentre.x),
				cvRound(transformedCentre.y));

			float radiusSum = 0.0f;

			for (int j = 1; j < transformedPoints.size(); j++)
			{
				radiusSum += norm(
					transformedPoints[j] - transformedCentre);
			}

			float transformedRadius = radiusSum / 4.0f;

			int radius = cvRound(transformedRadius * 0.9f);

			Mat mask = Mat::zeros(
				km_tf_images[i - 1].size(),
				CV_8UC1);

			circle(
				mask,
				centre,
				radius,
				Scalar(255),
				-1);

			vector<Vec3f> pixels;
			vector<Vec3f> colouredPixels;

			int whiteCount = 0;
			int blackCount = 0;
			int colourCount = 0;
			int totalPixels = 0;
			int saturatedCount = 0;
			Mat debugImage = km_tf_images[i - 1].clone();

			circle(
				debugImage,
				centre,
				radius,
				Scalar(0, 255, 255),
				2);

			imshow("Detected Circle", debugImage);
			imshow("Circle Mask", mask);
			waitKey(0);
			Rect bounds = Rect(
							  centre.x - radius,
							  centre.y - radius,
							  radius * 2 + 1,
							  radius * 2 + 1) &
						  Rect(0, 0, mask.cols, mask.rows);

			for (int y = bounds.y; y < bounds.y + bounds.height; y++)
			{
				for (int x = bounds.x; x < bounds.x + bounds.width; x++)
				{
					if (mask.at<uchar>(y, x) == 0)
						continue;

					totalPixels++;

					Vec3b bgr = km_tf_images[i - 1].at<Vec3b>(y, x);
					Vec3b hsv = hsv_image.at<Vec3b>(y, x);
					Vec3f pixel(
						static_cast<float>(bgr[0]),
						static_cast<float>(bgr[1]),
						static_cast<float>(bgr[2]));

					pixels.push_back(pixel);
					int saturation = hsv[1];
					int value = hsv[2];
					if (saturation > 110 && value > 65)
					{
						saturatedCount++;
					}
					if (value < 75)
					{
						blackCount++;
					}
					else if (saturation < 110 && value > 115)
					{
						whiteCount++;
					}
					else
					{
						colourCount++;
						colouredPixels.push_back(pixel);
					}
				}
			}

			if (totalPixels == 0)
				continue;

			double saturatedPercentage =
				100.0 * saturatedCount / totalPixels;

			double whitePercentage =
				100.0 * whiteCount / totalPixels;

			double blackPercentage =
				100.0 * blackCount / totalPixels;

			double colourPercentage =
				100.0 * colourCount / totalPixels;

			Scalar meanHSV = mean(hsv_image, mask);

			double meanSaturation = meanHSV[1];
			double meanBrightness = meanHSV[2];

			string ballType = "Unknown";

			if (whitePercentage >= 80.0 &&
				meanSaturation < 90.0 &&
				meanBrightness > 135.0)
			{
				ballType = "White";
			}
			else if (blackPercentage >= 40.0 &&
					 meanBrightness < 110.0 &&
					 saturatedPercentage < 15.0)
			{
				ballType = "Black";
			}
			else if (whitePercentage >= 20.0 &&
					 colourPercentage >= 10.0)
			{
				ballType = "Striped";
			}
			else if (colourPercentage >= 50.0 ||
					 saturatedPercentage >= 15.0)
			{
				ballType = "Solid";
			}
			const vector<Vec3f> &selectedPixels =
				(ballType == "Solid" || ballType == "Striped") && colouredPixels.size() >= k
					? colouredPixels
					: pixels;

			if (selectedPixels.size() < k)
				continue;

			Mat samples(
				static_cast<int>(selectedPixels.size()),
				3,
				CV_32F);

			for (int j = 0; j < samples.rows; j++)
			{
				samples.at<float>(j, 0) = selectedPixels[j][0];
				samples.at<float>(j, 1) = selectedPixels[j][1];
				samples.at<float>(j, 2) = selectedPixels[j][2];
			}

			Mat labels, centres;

			kmeans(
				samples,
				k,
				labels,
				TermCriteria(
					TermCriteria::COUNT | TermCriteria::EPS,
					100,
					0.0001),
				10,
				KMEANS_PP_CENTERS,
				centres);

			vector<int> counts(k, 0);

			for (int m = 0; m < labels.rows; m++)
			{
				int cluster = labels.at<int>(m, 0);
				counts[cluster]++;
			}

			int dominantCluster = static_cast<int>(
				max_element(counts.begin(), counts.end()) - counts.begin());

			float blue =
				centres.at<float>(dominantCluster, 0);

			float green =
				centres.at<float>(dominantCluster, 1);

			float red =
				centres.at<float>(dominantCluster, 2);

			std::string predictedColour =
				predictColour(cv::Vec3f(blue, green, red), ballType);

			std::string predictedLabel;

			if (ballType == "White" || ballType == "Black")
			{
				predictedLabel = ballType;
			}
			else if (ballType == "Solid" || ballType == "Striped")
			{
				predictedLabel = predictedColour + " " + ballType;
			}
			else
			{
				predictedLabel = "Unknown";
			}

			double minDistance = DBL_MAX;
			int nearestIndex = -1;

			for (int m = 0; m < groundTruthCenters.size(); m++)
			{
				if (matched[m])
					continue;

				double distance =
					cv::norm(groundTruthCenters[m] - transformedCentre);

				if (distance < minDistance)
				{
					minDistance = distance;
					nearestIndex = m;
				}
			}

			if (nearestIndex != -1 && minDistance < distancelimit)
			{
				matched[nearestIndex] = true;

				const PoolBall &groundTruth =
					Testimages[i - 1].pool_balls[nearestIndex];

				string actualLabel =
					groundTruth.colour.value_or("Unknown");

				totalEvaluated++;

				cout << "Ground Truth: " << actualLabel << endl;
				cout << "Predicted: " << predictedLabel << endl;

				if (predictedLabel == actualLabel)
				{
					correctPredictions++;
					cTP++;

					cout << "Result: CORRECT" << endl;
					kmrecognitionResults[actualLabel].correct++;
				}
				else
				{
					cFP++;
					cFN++;

					cout << "Result: INCORRECT" << endl;
					kmrecognitionResults[actualLabel].incorrect++;
				}
			}
			else
			{
				cFP++;
			}

			putText(
				km_tf_images[i - 1],
				predictedLabel,
				Point(centre.x - 20, centre.y),
				FONT_HERSHEY_SIMPLEX,
				0.5,
				Scalar(0, 123, 255),
				2);
			imshow("Recognition Image", km_tf_images[i - 1]);
			waitKey(0);
		}
		for (int m = 0; m < matched.size(); m++)
		{
			if (!matched[m])
			{
				cFN++;

				string actualLabel =
					Testimages[i - 1].pool_balls[m].colour.value_or("Unknown");

				kmrecognitionResults[actualLabel].notDetected++;
			}
		}
		if (totalEvaluated > 0)
		{
			kmTP = kmTP + cTP;
			kmFP = kmFP + cFP;
			kmFN = kmFN + cFN;

			cout << "Image: " << i << endl;
			cout << "True Positives: " << cTP << endl;
			cout << "False Positives: " << cFP << endl;
			cout << "False Negatives: " << cFN << endl;
			tuple metrics = computeMetrics(cTP, cFP, cFN);
			cout << "Precision: " << get<0>(metrics) << endl;
			cout << "Recall: " << get<1>(metrics) << endl;
			cout << "F1 Score: " << get<2>(metrics) << endl;

			kmP = kmP + get<0>(metrics);
			kmR = kmR + get<1>(metrics);
			kmF1 = kmF1 + get<2>(metrics);
			cout << "Total Evaluated: " << totalEvaluated << endl;
			cout << "Correct Predictions: " << correctPredictions << endl;
			double accuracy =
				100.0 * correctPredictions / totalEvaluated;

			cout << "Colour Accuracy: " << accuracy << "%" << endl;

			kmCA = kmCA + accuracy;
		}
	}

	kmTP = kmTP / 6;
	cout << "Average number of True Positives: " << kmTP << endl;
	kmFP = kmFP / 6;
	cout << "Average number of False Positives: " << kmFP << endl;
	kmFN = kmFN / 6;
	cout << "Average number of False Negatives: " << kmFN << endl;

	kmP = kmP / 6;
	cout << "Average Precision: " << kmP << endl;
	kmR = kmR / 6;
	cout << "Average Recall: " << kmR << endl;
	kmF1 = kmF1 / 6;
	cout << "Average F1 Score: " << kmF1 << endl;

	kmCA = kmCA / 6;
	cout << "Overall Colour Average " << kmCA << endl;

	for (const auto &[ball, result] : kmrecognitionResults)
	{

		int total = result.correct + result.incorrect;
		double accuracy =
			100.0 * result.correct / total;

		cout << "Ball: " << ball << endl;
		cout << "Correct: " << result.correct << endl;
		cout << "Incorrect: " << result.incorrect << endl;
		cout << "Detected Accuracy: " << accuracy << "%" << endl;
		cout << "Not Detected: " << result.notDetected << endl;
		cout << "----------------------" << endl;
	}
}