#include "Utilities.h"
#include <map>

// Coordinate data structure to save the centre points of the pool balls
struct Coordinate
{
	int row;
	int column;
};

// Poolball data structure to save the pool ball positions and colours
struct PoolBall
{
	Coordinate position;
	string colour;
};

// ImageInfo data structure to save the pool balls in each image
struct ImageInfo
{
	string filename;
	vector<PoolBall> pool_balls;
};

// Colour Reference data structure to save the colours from the k-means clustering and its name
struct ColourReference
{
	string name;
	Vec3f bgr;
};

// Vector to store the k-means colour references
vector<ColourReference> colourReferences;

// Vector to store all the images names, pool ball coordinates and colours

vector<ImageInfo> images = {
	{"AllBalls.jpeg", {{{253, 908}, "Yellow Solid"}, {{250, 959}, "Blue Solid"}, {{255, 1013}, "Red Solid"}, {{256, 1072}, "Purple Solid"}, {{254, 1132}, "Orange Solid"}, {{262, 1184}, "Green Solid"}, {{256, 1244}, "Brown Solid"}, {{253, 1307}, "Black"}, {{329, 901}, "Yellow Striped"}, {{330, 961}, "Blue Striped"}, {{335, 1013}, "Red Striped"}, {{336, 1067}, "Purple Striped"}, {{334, 1130}, "Orange Striped"}, {{345, 1187}, "Green Striped"}, {{342, 1245}, "Brown Striped"}, {{293, 797}, "White"}}},

	{"Table1.jpeg", {{{309, 1092}, ""}, {{429, 1212}, ""}, {{383, 1131}, ""}, {{335, 1050}, ""}, {{285, 1211}, ""}, {{261, 1170}, ""}, {{352, 1173}, ""}, {{331, 1132}, ""}, {{240, 1210}, ""}, {{310, 1170}, ""}, {{407, 1169}, ""}, {{281, 1135}, ""}, {{374, 1212}, ""}, {{360, 1091}, ""}, {{331, 1213}, ""}, {{288, 29}, ""}}},

	{"Table2.jpeg", {{{282, 1103}, ""}, {{620, 1224}, ""}, {{391, 1121}, ""}, {{315, 1046}, ""}, {{310, 1305}, ""}, {{202, 621}, ""}, {{361, 1173}, ""}, {{331, 1132}, ""}, {{177, 725}, ""}, {{185, 1269}, ""}, {{665, 798}, ""}, {{296, 438}, ""}, {{53, 1235}, ""}, {{362, 1090}, ""}, {{399, 1205}, ""}, {{507, 1169}, ""}}},

	{"Table3.jpeg", {{{23, 908}, ""}, {{616, 1224}, ""}, {{447, 1199}, ""}, {{336, 29}, ""}, {{305, 1406}, ""}, {{210, 621}, ""}, {{260, 1294}, ""}, {{226, 1252}, ""}, {{177, 725}, ""}, {{171, 1270}, ""}, {{665, 798}, ""}, {{249, 351}, ""}, {{53, 1233}, ""}, {{169, 901}, ""}, {{399, 1201}, ""}, {{434, 29}, ""}}},

	{"Table4.jpeg", {{{23, 908}, ""}, {{546, 1407}, ""}, {{444, 1204}, ""}, {{305, 1406}, ""}, {{210, 621}, ""}, {{260, 1294}, ""}, {{226, 1252}, ""}, {{181, 724}, ""}, {{171, 1270}, ""}, {{665, 798}, ""}, {{249, 351}, ""}, {{58, 1231}, ""}, {{169, 901}, ""}, {{399, 1201}, ""}, {{88, 1392}, ""}}},

	{"Table5.jpeg", {{{535, 23}, ""}, {{546, 1407}, ""}, {{444, 1204}, ""}, {{305, 1406}, ""}, {{131, 25}, ""}, {{260, 1294}, ""}, {{226, 1252}, ""}, {{538, 72}, ""}, {{171, 1270}, ""}, {{665, 798}, ""}, {{249, 351}, ""}, {{169, 901}, ""}, {{399, 1201}, ""}, {{608, 26}, ""}}},

	{"Table6.jpeg", {{{535, 23}, ""}, {{477, 1364}, ""}, {{444, 1204}, ""}, {{305, 1406}, ""}, {{131, 25}, ""}, {{260, 1294}, ""}, {{226, 1252}, ""}, {{538, 72}, ""}, {{171, 1270}, ""}, {{249, 351}, ""}, {{169, 901}, ""}, {{399, 1201}, ""}, {{629, 947}, ""}}}};

// Vector to store the images and their pool ball information for testing the ball recognition
vector<ImageInfo>
	Testimages = {
		{"Table1.jpeg", {{{309, 1092}, "Yellow Solid"}, {{429, 1212}, "Blue Solid"}, {{383, 1131}, "Red Solid"}, {{335, 1050}, "Purple Solid"}, {{285, 1211}, "Orange Solid"}, {{261, 1170}, "Green Solid"}, {{352, 1173}, "Brown Solid"}, {{331, 1132}, "Black"}, {{240, 1210}, "Yellow Striped"}, {{310, 1170}, "Blue Striped"}, {{407, 1169}, "Red Striped"}, {{281, 1135}, "Purple Striped"}, {{374, 1212}, "Orange Striped"}, {{360, 1091}, "Green Striped"}, {{331, 1213}, "Brown Striped"}, {{288, 29}, "White"}}},

		{"Table2.jpeg", {{{282, 1103}, "Yellow Solid"}, {{620, 1224}, "Blue Solid"}, {{391, 1121}, "Red Solid"}, {{315, 1046}, "Purple Solid"}, {{310, 1305}, "Orange Solid"}, {{202, 621}, "Green Solid"}, {{361, 1173}, "Brown Solid"}, {{331, 1132}, "Black"}, {{177, 725}, "Yellow Striped"}, {{185, 1269}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{296, 438}, "Purple Striped"}, {{53, 1235}, "Orange Striped"}, {{362, 1090}, "Green Striped"}, {{399, 1205}, "Brown Striped"}, {{507, 1169}, "White"}}},

		{"Table3.jpeg", {{{23, 908}, "Yellow Solid"}, {{616, 1224}, "Blue Solid"}, {{447, 1199}, "Red Solid"}, {{336, 29}, "Purple Solid"}, {{305, 1406}, "Orange Solid"}, {{210, 621}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{177, 725}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{249, 351}, "Purple Striped"}, {{53, 1233}, "Orange Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{434, 29}, "White"}}},

		{"Table4.jpeg", {{{23, 908}, "Yellow Solid"}, {{546, 1407}, "Blue Solid"}, {{444, 1204}, "Red Solid"}, {{305, 1406}, "Orange Solid"}, {{210, 621}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{181, 724}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{249, 351}, "Purple Striped"}, {{58, 1231}, "Orange Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{88, 1392}, "White"}}},

		{"Table5.jpeg", {{{535, 23}, "Yellow Solid"}, {{546, 1407}, "Blue Solid"}, {{444, 1204}, "Red Solid"}, {{305, 1406}, "Orange Solid"}, {{131, 25}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{538, 72}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{665, 798}, "Red Striped"}, {{249, 351}, "Purple Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{608, 26}, "White"}}},

		{"Table6.jpeg", {{{535, 23}, "Yellow Solid"}, {{477, 1364}, "Blue Solid"}, {{444, 1204}, "Red Solid"}, {{305, 1406}, "Orange Solid"}, {{131, 25}, "Green Solid"}, {{260, 1294}, "Brown Solid"}, {{226, 1252}, "Black"}, {{538, 72}, "Yellow Striped"}, {{171, 1270}, "Blue Striped"}, {{249, 351}, "Purple Striped"}, {{169, 901}, "Green Striped"}, {{399, 1201}, "Brown Striped"}, {{629, 947}, "White"}}}};

// Vector of ball labels for confusion matrix
vector<string> ballLabels = {
	"White",
	"Yellow Solid",
	"Blue Solid",
	"Red Solid",
	"Purple Solid",
	"Orange Solid",
	"Green Solid",
	"Brown Solid",
	"Black",
	"Yellow Striped",
	"Blue Striped",
	"Red Striped",
	"Purple Striped",
	"Orange Striped",
	"Green Striped",
	"Brown Striped"};
// Helper function to compute precision, recall and F1 score
tuple<double, double, double> computeMetrics(int TP, int FP, int FN)
{

	double precision = TP / (double)(TP + FP);

	double recall = TP / (double)(TP + FN);

	double f1_score = 2 * ((precision * recall) / (double)(precision + recall));

	return {precision, recall, f1_score};
}

// Helper function to label the colour of the ball from K-means clustering
string predictColour(
	const Vec3f &dominantBGR,
	const string &ballType)
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

// Helper function to get the number of the ball after it has been recognised
int getBallNumber(const string &label)
{
	if (label == "White")
		return 0;
	if (label == "Black")
		return 8;
	if (label == "Unknown")
		return -1;

	map<string, int> colourNumbers = {
		{"Yellow", 1},
		{"Blue", 2},
		{"Red", 3},
		{"Purple", 4},
		{"Orange", 5},
		{"Green", 6},
		{"Brown", 7}};

	string colour = label.substr(0, label.find(' '));

	if (colourNumbers.find(colour) == colourNumbers.end())
		return -1;

	int number = colourNumbers[colour];

	if (label.find("Striped") != string::npos)
		number += 8;

	return number;
}
// Helper function to calculate metrics from a confusion matrix for each ball's recognition
void calculateConfusionMetrics(
	const map<string, map<string, int>> &confusionMatrix,
	const vector<string> &ballLabels)
{
	int total = 0;

	for (const auto &row : confusionMatrix)
	{
		for (const auto &column : row.second)
		{
			total += column.second;
		}
	}

	for (const auto &ball : ballLabels)
	{
		int TP = 0;
		int FP = 0;
		int FN = 0;

		// True positives
		auto row = confusionMatrix.find(ball);

		if (row != confusionMatrix.end())
		{
			auto cell = row->second.find(ball);

			if (cell != row->second.end())
				TP = cell->second;
		}

		// False positives and false negatives
		for (const auto &actual : confusionMatrix)
		{
			for (const auto &predicted : actual.second)
			{
				if (actual.first != ball &&
					predicted.first == ball)
				{
					FP += predicted.second;
				}

				if (actual.first == ball &&
					predicted.first != ball)
				{
					FN += predicted.second;
				}
			}
		}

		int TN = total - TP - FP - FN;

		// Formulas to calculate accuracy, precision, recall, specificity and F1 score

		double accuracy = (total > 0)
							  ? (double)(TP + TN) / total
							  : 0.0;

		double precision = (TP + FP > 0)
							   ? (double)TP / (TP + FP)
							   : 0.0;

		double recall = (TP + FN > 0)
							? (double)TP / (TP + FN)
							: 0.0;

		double specificity = (TN + FP > 0)
								 ? (double)TN / (TN + FP)
								 : 0.0;

		double f1 = (precision + recall > 0)
						? 2.0 * precision * recall / (precision + recall)
						: 0.0;

		cout << "\nBall: " << ball << endl;
		cout << "TP: " << TP << endl;
		cout << "FP: " << FP << endl;
		cout << "FN: " << FN << endl;
		cout << "TN: " << TN << endl;

		cout << "Accuracy: " << accuracy * 100 << "%" << endl;
		cout << "Precision: " << precision * 100 << "%" << endl;
		cout << "Recall: " << recall * 100 << "%" << endl;
		cout << "Specificity: " << specificity * 100 << "%" << endl;
		cout << "F1 Score: " << f1 * 100 << "%\n"
			 << endl;
	}
}

// Helper function to compute overall evaluation metrics
void computeFinalMetrics(
	const map<string, map<string, int>> &confusionMatrix,
	int unmatchedFalsePositives)
{
	int TP = 0;
	int incorrect = 0;
	int missed = 0;

	for (const auto &actual : confusionMatrix)
	{
		for (const auto &predicted : actual.second)
		{
			int count = predicted.second;

			if (predicted.first == "Not Detected")
			{
				missed += count;
			}
			else if (actual.first == predicted.first)
			{
				TP += count;
			}
			else
			{
				incorrect += count;
			}
		}
	}

	int FP = incorrect + unmatchedFalsePositives;
	int FN = incorrect + missed;

	double precision = (TP + FP > 0)
						   ? (double)TP / (TP + FP)
						   : 0.0;

	double recall = (TP + FN > 0)
						? (double)TP / (TP + FN)
						: 0.0;

	double f1 = (precision + recall > 0)
					? 2.0 * precision * recall / (precision + recall)
					: 0.0;

	cout << "\nOverall Method Evaluation\n";
	cout << "True Positives: " << TP << endl;
	cout << "False Positives: " << FP << endl;
	cout << "False Negatives: " << FN << endl;
	cout << "Precision: " << precision << endl;
	cout << "Recall: " << recall << endl;
	cout << "F1 Score: " << f1 << endl;
}
// Map to create a confusion matrix for detected balls for colour recognition
map<string, map<string, int>> detectedConfusionMatrix;

// Map to create a confusin matrix for recognised and unrecognised balls
map<string, map<string, int>> overallConfusionMatrix;

void MyApplication()
{
	const char *file_location = "Media/Pool/";
	const char *pool_files[] = {
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

	Mat perspective_matrix = getPerspectiveTransform(source, destination);

	// Detecting the balls:  Hough Circle Transform
	// First: Greyscale the images
	Mat *gs_images = new Mat[number_of_images];
	for (int i = 0; i < number_of_images; i++)
	{
		cvtColor(pool_image[i], gs_images[i], cv::COLOR_BGR2GRAY);
		imshow("Greyscale", gs_images[i]);
		waitKey(0);
	}

	// Next: Use Guassian blur to remove image noise
	Mat *bl_images = new Mat[number_of_images];
	for (int i = 0; i < number_of_images; i++)
	{
		GaussianBlur(gs_images[i], bl_images[i], Size(5, 5), 1);
		imshow("Blurred images", bl_images[i]);
		waitKey(0);
	}

	// Maxmimum distance between a ground truth centre and a detect centre
	int distancelimit = 22;

	// Variables to store average number of true positives, false positives, false negatives and average precision, recall and F1 score
	double avTP = 0;
	double avFP = 0;
	double avFN = 0;
	double avP = 0;
	double avR = 0;
	double avF1 = 0;

	// Matrix to store the transformed images
	Mat *tf_images = new Mat[number_of_images];

	// Vector to store the detected circles in each image
	vector<vector<Vec3f>> allDetectedCircles(number_of_images);
	// Hough Circle Transform
	for (int i = 0; i < number_of_images; i++)
	{

		Mat displayImage = pool_image[i].clone();
		Mat displayImage2 = pool_image[i].clone();

		// Vector to store the detected circles
		vector<Vec3f> circles;

		// Hough Circle Transform performed on the Guassian blurred greyscale image
		cv::HoughCircles(
			bl_images[i],
			circles,
			cv::HOUGH_GRADIENT,
			1, 25, 65, 15, 20, 24);

		// Saving the detecting circles into its vector
		allDetectedCircles[i] = circles;

		// Vectors for the detected centresa and their transformed coordinates
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

		imshow("Hough Transform Circles:", displayImage2);
		waitKey(0);

		// Variables to store the number of true positive, true negative and false positive detections in the image
		double TP = 0;
		double FN = 0;
		double FP = 0;

		// Transforming the image
		warpPerspective(pool_image[i], tf_images[i], perspective_matrix, Size(1433, 682));
		imshow("Transformed Image: ", tf_images[i]);

		// Transforming the detected centres into the same geometric space as the ground truths
		perspectiveTransform(detectedCenters, tfCenters, perspective_matrix);
		vector<Point2f> groundTruthCenters(images[i].pool_balls.size());

		// Vector to keep track of the matched ground truths
		vector<bool> matched(groundTruthCenters.size(), false);

		for (int j = 0; j < images[i].pool_balls.size(); j++)
		{
			PoolBall pool_ball = images[i].pool_balls[j];
			groundTruthCenters[j] = Point2f(pool_ball.position.column, pool_ball.position.row);
		}

		// Inverse matrix to display false negatives on original image
		Mat inverseH = perspective_matrix.inv();

		vector<Point2f> originalGT;

		perspectiveTransform(groundTruthCenters, originalGT, inverseH);

		// Finding the nearest available ground truth for the detected circle centre
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

			// Displaying the detected centre, the nearest ground truth and the distance between them
			cout << "Detected Centre: ("
				 << dc.x << ", " << dc.y << ")" << endl;

			if (nearestIndex != -1)
			{
				Point2f gt = groundTruthCenters[nearestIndex];

				cout << "Ground Truth Centre: ("
					 << gt.x << ", " << gt.y << ")" << endl;

				cout << "Distance: " << minDistance << endl;
			}
			else
			{
				cout << "Ground Truth Centre: None available" << endl;
			}

			cout << "------------------------" << endl;

			// Matching the detected centre to the nearest ground truth centre
			// Incrementing TP as matched detections and unmatched detections as false positives
			// Displaying the true positive, false positive, and false negative circles on the image
			if (nearestIndex != -1 && minDistance < distancelimit)
			{
				matched[nearestIndex] = true;
				TP++;

				circle(
					displayImage, Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)), cvRound(circles[k][2]),
					cv::Scalar(0, 255, 0), 2);

				putText(
					displayImage, "TP", Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)) + cv::Point(5, -10),
					cv::FONT_HERSHEY_SIMPLEX, 0.5,
					cv::Scalar(0, 255, 0), 2);
			}
			else
			{
				FP++;
				circle(
					displayImage, Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)), 15,
					cv::Scalar(0, 0, 255), 2);

				putText(
					displayImage, "FP", Point(cvRound(detectedCenters[k].x), cvRound(detectedCenters[k].y)) + cv::Point(5, -10),
					cv::FONT_HERSHEY_SIMPLEX, 0.5,
					cv::Scalar(0, 0, 255), 2);
			}
		}

		// if there are any unmatched ground truths, they are recorded and displayed
		//  as false negatives
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
		// Adding the true positives, false positives and false negatives to the average count of each
		if (i != 0)
		{
			avTP = avTP + TP;
			avFP = avFP + FP;
			avFN = avFN + FN;
		}

		// Displaying the amount of  false positive, false negative and true positive in each image
		cout << "True positives: " << TP << endl;
		cout << "False positives: " << FP << endl;
		cout << "False Negatives: " << FN << endl;

		// Computing the metrics of each image and displaying them
		tuple<double, double, double> metrics =
			computeMetrics(TP, FP, FN);
		cout << "Precision: " << get<0>(metrics) << endl;
		cout << "Recall: " << get<1>(metrics) << endl;
		cout << "F1 Score: " << get<2>(metrics) << endl;

		// Adding to average precision, recall and f1 score
		if (i != 0)
		{
			avP = avP + get<0>(metrics);
			avR = avR + get<1>(metrics);
			avF1 = avF1 + get<2>(metrics);
		}

		// Displaying the Hough Circles on the image
		imshow("Hough Transform Circles:", displayImage);
		waitKey(0);
	}

	// Computing the average of the metrics used
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

	// Recognising the balls using K-means clustering

	// Transforming the training image into the
	Mat training_perspective;
	warpPerspective(pool_image[0], training_perspective, perspective_matrix, Size(1433, 682));
	Mat ts_km_tf_image;
	// Transforming the training image
	warpPerspective(
		pool_image[0],
		ts_km_tf_image,
		perspective_matrix,
		Size(1433, 682));

	Mat trainingDisplay = ts_km_tf_image.clone();

	// Converting the transformed image into HSV
	Mat hsv_image;
	cvtColor(ts_km_tf_image, hsv_image, COLOR_BGR2HSV);

	imshow("HSV Image", hsv_image);
	waitKey(0);

	// Number of clusters
	int k = 3;

	// Vector of training circles
	const vector<Vec3f> &tsCircles = allDetectedCircles[0];

	// Iterating through each training image circle to get its colour information
	for (int i = 0; i < tsCircles.size(); i++)
	{

		Vec3f c = tsCircles[i];

		Point2f originalCentre(c[0], c[1]);
		float originalRadius = c[2];

		// Vector of points on the edge of the original detected circle and its centre
		vector<Point2f> originalPoints = {
			originalCentre,
			Point2f(c[0] + originalRadius, c[1]),
			Point2f(c[0] - originalRadius, c[1]),
			Point2f(c[0], c[1] + originalRadius),
			Point2f(c[0], c[1] - originalRadius)};

		vector<Point2f> transformedPoints;

		// Transforming the points
		perspectiveTransform(
			originalPoints,
			transformedPoints,
			perspective_matrix);

		Point2f transformedCentre = transformedPoints[0];

		Point centre(
			cvRound(transformedCentre.x),
			cvRound(transformedCentre.y));

		float radiusSum = 0.0f;

		// Finding the transformed radius to create a mask
		for (int j = 1; j < transformedPoints.size(); j++)
		{
			radiusSum += norm(
				transformedPoints[j] - transformedCentre);
		}

		float transformedRadius = radiusSum / 4.0f;
		// Radius decreased to 90% of the transformed radius
		int radius = cvRound(transformedRadius * 0.9f);

		// Mask for the transformed ball
		Mat mask = Mat::zeros(
			ts_km_tf_image.size(),
			CV_8UC1);

		circle(
			mask,
			centre,
			radius,
			Scalar(255),
			-1);

		// Vectors to keep track of pixels and coloured pixels
		vector<Vec3f> pixels;
		vector<Vec3f> colouredPixels;

		// Counts to keep track of white, black, other pixels
		//  and the amount of saturated pixels
		int whiteCount = 0;
		int blackCount = 0;
		int colourCount = 0;
		int totalPixels = 0;
		int saturatedCount = 0;
		Mat debugImage = ts_km_tf_image.clone();

		// Displaying the mask on the transofrmed image
		circle(
			debugImage,
			centre,
			radius,
			Scalar(0, 255, 255),
			2);

		imshow("Detected Circle", debugImage);
		imshow("Circle Mask", mask);
		waitKey(0);

		// Creating a boundary rectangle to limit the area searched when finding the pixels
		Rect bounds = Rect(
						  centre.x - radius,
						  centre.y - radius,
						  radius * 2 + 1,
						  radius * 2 + 1) &
					  Rect(0, 0, mask.cols, mask.rows);

		// Looping through all pixels in the boundary rectangle
		for (int y = bounds.y; y < bounds.y + bounds.height; y++)
		{
			for (int x = bounds.x; x < bounds.x + bounds.width; x++)
			{
				if (mask.at<uchar>(y, x) == 0)
					continue;

				// Incrementing the total pixels
				totalPixels++;

				// Vectors for BGR channels and HSV
				Vec3b bgr = ts_km_tf_image.at<Vec3b>(y, x);
				Vec3b hsv = hsv_image.at<Vec3b>(y, x);
				Vec3f pixel(
					static_cast<float>(bgr[0]), // Blue
					static_cast<float>(bgr[1]), // Green
					static_cast<float>(bgr[2])	// Red
				);

				pixels.push_back(pixel);

				// Finding the saturation and value of each pixel
				//  in order to find white, black, coloured and saturated pixels
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

		// Calculating the percentage for each count to help thresholding

		double saturatedPercentage =
			100.0 * saturatedCount / totalPixels;

		double whitePercentage =
			100.0 * whiteCount / totalPixels;

		double blackPercentage =
			100.0 * blackCount / totalPixels;

		double colourPercentage =
			100.0 * colourCount / totalPixels;

		// Finding the mean HSV values of the mask
		Scalar meanHSV = mean(hsv_image, mask);

		double meanSaturation = meanHSV[1];
		double meanBrightness = meanHSV[2];

		string ballType = "Unknown";

		// Using thresholds to classify each ball type
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

		// Outputting the results
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

		// Finding the coloured pixels of the striped and solid balls
		const vector<Vec3f> &selectedPixels =
			(ballType == "Solid" || ballType == "Striped") && colouredPixels.size() >= k
				? colouredPixels
				: pixels;

		if (selectedPixels.size() < k)
			continue;

		// Taking samples from those pixels
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

		// Performing K-means on the samples
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

		// Finding the number of pixels that belong to each cluster
		for (int m = 0; m < labels.rows; m++)
		{
			int cluster = labels.at<int>(m, 0);
			counts[cluster]++;
		}

		// Finding the dominant cluster for each ball
		int dominantCluster = static_cast<int>(
			max_element(counts.begin(), counts.end()) - counts.begin());

		// Finding the BGR values of the dominant cluster
		float blue =
			centres.at<float>(dominantCluster, 0);

		float green =
			centres.at<float>(dominantCluster, 1);

		float red =
			centres.at<float>(dominantCluster, 2);

		// Find the nearest training ground truth
		double minDistance = DBL_MAX;
		int nearestIndex = -1;

		for (int j = 0; j < images[0].pool_balls.size(); j++)
		{
			const PoolBall &gt = images[0].pool_balls[j];

			Point2f gtCentre(gt.position.column, gt.position.row);

			double distance = norm(
				transformedCentre - gtCentre);

			if (distance < minDistance)
			{
				minDistance = distance;
				nearestIndex = j;
			}
		}

		// Save the BGR reference
		if (nearestIndex != -1 && minDistance < 23)
		{
			string label =
				images[0].pool_balls[nearestIndex].colour;

			if (label != "White" && label != "Black")
			{
				string colourName = label.substr(0, label.find(' '));

				// Only store one reference for each colour
				bool exists = false;

				for (const auto &reference : colourReferences)
				{
					if (reference.name == colourName)
					{
						exists = true;
						break;
					}
				}

				if (!exists)
				{
					colourReferences.push_back({colourName,
												Vec3f(blue, green, red)});
				}
			}
		}

		// Outputting the results
		cout << "\nCircle " << i << endl;
		cout << "Ball Type: " << ballType << endl;

		cout << "Dominant Blue: " << blue << endl;
		cout << "Dominant Green: " << green << endl;
		cout << "Dominant Red: " << red << endl;
		cout << "Mean Saturation: " << meanHSV[1] << endl;
		cout << "Mean Brightness: " << meanHSV[2] << endl;
		cout << "White Percentage: " << whitePercentage << "%" << endl;
		cout << "Black Percentage: " << blackPercentage << "%" << endl;
		cout << "Coloured Percentage: " << colourPercentage << "%" << endl;
		cout << "Saturation Percentage: " << saturatedPercentage << "%" << endl;

		putText(
			trainingDisplay,
			ballType,
			Point(centre.x - radius, centre.y - radius - 10),
			FONT_HERSHEY_SIMPLEX,
			0.5,
			Scalar(0, 255, 255),
			2);
	}

	imshow("Classified Pool Balls", trainingDisplay);
	waitKey(0);

	// Colour Recogniton on Test Images

	// Count of the unmatched false positives
	int totalUnmatchedFalsePositives = 0;

	Mat *km_tf_images = new Mat[number_of_images - 1];
	for (int i = 1; i < number_of_images; i++)
	{
		// Vector to match the circles with their ground truths
		vector<bool> matched(
			Testimages[i - 1].pool_balls.size(), false);

		// Count of unmatched circles
		int unmatchedCircles = 0;

		Mat displayImage = pool_image[i].clone();

		// Reusing the circles detected in the detection stage
		vector<Vec3f> &circles = allDetectedCircles[i];

		vector<Point2f> groundTruthCenters(Testimages[i - 1].pool_balls.size());

		// Finding the ground truths for each image
		for (int j = 0; j < Testimages[i - 1].pool_balls.size(); j++)
		{
			PoolBall pool_ball = Testimages[i - 1].pool_balls[j];
			groundTruthCenters[j] = Point2f(pool_ball.position.column, pool_ball.position.row);
		}

		// Transforming the original image
		warpPerspective(
			pool_image[i],
			km_tf_images[i - 1],
			perspective_matrix,
			Size(1433, 682));

		Mat recognitionDisplay = km_tf_images[i - 1].clone();

		// Creating a HSV image of the transformed image
		Mat hsv_image;
		cvtColor(km_tf_images[i - 1], hsv_image, COLOR_BGR2HSV);

		// Number of clusters
		int k = 3;

		// Iterating through each ball
		for (int n = 0; n < circles.size(); n++)
		{

			Vec3f c = circles[n];

			Point2f originalCentre(c[0], c[1]);
			float originalRadius = c[2];

			// Finding points on the edge of the ball
			vector<Point2f> originalPoints = {
				originalCentre,
				Point2f(c[0] + originalRadius, c[1]),
				Point2f(c[0] - originalRadius, c[1]),
				Point2f(c[0], c[1] + originalRadius),
				Point2f(c[0], c[1] - originalRadius)};

			// Transforming the edge points
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

			// Reducing the radius to 0.9 of its original size
			int radius = cvRound(transformedRadius * 0.9f);

			// Creating a mask
			Mat mask = Mat::zeros(
				km_tf_images[i - 1].size(),
				CV_8UC1);

			circle(
				mask,
				centre,
				radius,
				Scalar(255),
				-1);

			// Vectors and counts to keep track of different types of pixels
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

			// Creating the boundary rectangle area
			Rect bounds = Rect(
							  centre.x - radius,
							  centre.y - radius,
							  radius * 2 + 1,
							  radius * 2 + 1) &
						  Rect(0, 0, mask.cols, mask.rows);

			// Iterating through it
			for (int y = bounds.y; y < bounds.y + bounds.height; y++)
			{
				for (int x = bounds.x; x < bounds.x + bounds.width; x++)
				{
					if (mask.at<uchar>(y, x) == 0)
						continue;

					totalPixels++;

					// Vectors for the BGR colour space and HSV
					Vec3b bgr = km_tf_images[i - 1].at<Vec3b>(y, x);
					Vec3b hsv = hsv_image.at<Vec3b>(y, x);
					Vec3f pixel(
						static_cast<float>(bgr[0]),
						static_cast<float>(bgr[1]),
						static_cast<float>(bgr[2]));

					pixels.push_back(pixel);
					int saturation = hsv[1];
					int value = hsv[2];
					// Counting the number of pixels in each category
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

			// If any circle does not have enough pixels, it is considered unmatched
			if (totalPixels == 0)
			{
				unmatchedCircles++;
				continue;
			}

			// Calculating the percentages
			double saturatedPercentage =
				100.0 * saturatedCount / totalPixels;

			double whitePercentage =
				100.0 * whiteCount / totalPixels;

			double blackPercentage =
				100.0 * blackCount / totalPixels;

			double colourPercentage =
				100.0 * colourCount / totalPixels;

			// Finding the mean HSV values of the mask
			Scalar meanHSV = mean(hsv_image, mask);

			double meanSaturation = meanHSV[1];
			double meanBrightness = meanHSV[2];

			string ballType = "Unknown";

			// Using the thresholds from the training image to
			// identify the ball type
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
			// Vector to get the coloured pixels
			const vector<Vec3f> &selectedPixels =
				(ballType == "Solid" || ballType == "Striped") && colouredPixels.size() >= k
					? colouredPixels
					: pixels;

			// if less than 3 pixels are available for kmeans,
			//  do not perform recognition
			if (selectedPixels.size() < k)
			{
				unmatchedCircles++;
				continue;
			}

			// Create samples from the pixels
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

			// Perform kmeans on the samples
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

			// Finding the dominant cluster
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

			// Classifying the colour based on the training data
			string predictedColour =
				predictColour(cv::Vec3f(blue, green, red), ballType);

			string predictedLabel;

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

			// Using the matching algorithm to match the circles with the ground truth
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

				string actualLabel = groundTruth.colour;

				detectedConfusionMatrix[actualLabel][predictedLabel]++;
				overallConfusionMatrix[actualLabel][predictedLabel]++;

				cout << "Ground Truth: " << actualLabel
					 << " (" << getBallNumber(actualLabel) << ")" << endl;

				cout << "Predicted: " << predictedLabel
					 << " (" << getBallNumber(predictedLabel) << ")" << endl;

				if (predictedLabel == actualLabel)
				{
					cout << "Result: CORRECT" << endl;
				}
				else
				{
					cout << "Result: INCORRECT" << endl;
				}
			}
			else
			{
				unmatchedCircles++;
			}

			// Getting the ball number based of its predicted classification
			int ballNumber = getBallNumber(predictedLabel);

			string displayLabel = to_string(ballNumber);

			// Displaying the ball number and coloured circle on the transformed images
			putText(
				recognitionDisplay,
				displayLabel,
				Point(centre.x - 10, centre.y),
				FONT_HERSHEY_SIMPLEX,
				0.75,
				Scalar(255, 105, 180),
				2);

			circle(
				recognitionDisplay,
				centre,
				radius,
				Scalar(blue, green, red),
				2,
				LINE_AA);

			imshow("Recognition Image", recognitionDisplay);
			waitKey(0);
		}
		// For any unmatched or unrecognised circles, it is counted
		// as a false positive
		totalUnmatchedFalsePositives += unmatchedCircles;
		for (int m = 0; m < matched.size(); m++)
		{
			if (!matched[m])
			{
				string actualLabel =
					Testimages[i - 1].pool_balls[m].colour;

				overallConfusionMatrix[actualLabel]["Not Detected"]++;
			}
		}
	}

	// Calculating and outputting the confusion matrix, its metrics for
	//  each ball
	cout << "\nRECOGNISED BALLS CONFUSION MATRIX METRICS\n";

	calculateConfusionMetrics(
		detectedConfusionMatrix,
		ballLabels);

	// Calculating and outputting the overall metrics.
	cout << "\nOVERALL CONFUSION MATRIX METRICS\n";
	calculateConfusionMetrics(
		overallConfusionMatrix,
		ballLabels);
	computeFinalMetrics(
		overallConfusionMatrix,
		totalUnmatchedFalsePositives);
}
