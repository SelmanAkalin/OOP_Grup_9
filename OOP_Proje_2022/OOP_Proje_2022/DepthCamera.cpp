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

	Point* tempP = turnPC.getPoints();

	while (!file.eof()) {
		
		double X, Y, Z;

		file >> X >> Y >> Z;
		(*tempP).setX(X);
		(*tempP).setY(Y);
		(*tempP).setZ(Z);
		file.ignore(256, '\n');

		tempP++;
	}
	
	file.close();
	
	return turnPC;
}