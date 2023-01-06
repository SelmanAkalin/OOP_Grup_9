/**
* @Author	: Resulberdi Akyyev
* @date		: 24.12.2022
* @file		: DepthCamera.cpp
*/
#include"DepthCamera.h"
/**
* @brief	: Constructor with a parameter.
* @param	: _fileName is a parameter for setting fileName attribute.
*/
DepthCamera::DepthCamera(string _fileName) :fileName(_fileName) {}
void DepthCamera::setfileName(string _fileName) {
	fileName = _fileName;
}
/**
* @brief	: getfileName without a parameter it returns fileName.
*/
string DepthCamera::getfileName()const {
	return fileName;
}
/**
* @brief	: capture is a function for getting values for a PointCloud.
*/
PointCloud DepthCamera::capture() {
	fstream file(fileName, ios::in);

	if (!file) return false;

	file.ignore(256, '\n');

	int sizePC;

	file >> sizePC;

	PointCloud turnPC(sizePC);

	list<Point> tempP;

	while (!file.eof()) {

		double X, Y, Z;
		Point pP;
		file >> X >> Y >> Z;
		pP.setX(X);
		pP.setY(Y);
		pP.setZ(Z);
		tempP.push_back(pP);
		file.ignore(256, '\n');

	}

	turnPC.setPoints(tempP);

	file.close();

	return turnPC;
}
/**
* @brief	: captureFor is a function for getting values for a PointCloud and transform them.
*/
PointCloud DepthCamera::captureFor() {
	fstream file(fileName, ios::in);

	if (!file) return false;

	file.ignore(256, '\n');

	int sizePC;

	file >> sizePC;

	PointCloud turnPC(sizePC);

	list<Point> tempP;

	while (!file.eof()) {

		double X, Y, Z;
		Point pP;
		file >> X >> Y >> Z;
		pP.setX(X);
		pP.setY(Y);
		pP.setZ(Z);
		tempP.push_back(pP);
		file.ignore(256, '\n');

	}

	turnPC.setPoints(tempP);

	transform.doTransform(turnPC);

	file.close();

	return turnPC;
}