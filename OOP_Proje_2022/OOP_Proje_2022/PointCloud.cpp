/**
* @Author	: Selman Akalýn
* @date		: 23.12.2022
* @file		: PointCloud.cpp
*/
#include"PointCloud.h"
/**
* @brief	: Constructor without parameter.
*/
PointCloud::PointCloud() {
	pointNumber = 1;
	points = new Point[pointNumber];
}
/**
* @brief	: Constructor with a parameter.
* @param	: _pointNumber is a parameter for setting classes pointNumber attribute.
*/
PointCloud::PointCloud(int _PN) {
	pointNumber = _PN;
	points = new Point[pointNumber];
}
/**
* @brief	: Copy Constructor with a parameter.
* @param	: _PC is a parameter for setting classes attributes.
*/
PointCloud::PointCloud(const PointCloud& PC) {
	pointNumber = PC.getpointNumber();

	points = new Point[pointNumber];

	for (int i = 0; i < PC.pointNumber; i++) {
		points[i] = PC.points[i];
	}
}
/**
* @brief	: Destructor for deleting list of points.
*/
PointCloud::~PointCloud(){
	delete[]points;
}
/**
* @brief	: setPoints function for setting points.
* @param	: P is a parameter for setting points.
*/
void PointCloud::setPoints(Point* P) {
	points = P;
}
/**
* @brief	: getPoints function for returning points.
*/
Point* PointCloud::getPoints() {
	return points;
}
/**
* @brief	: getpointNumber function for returning pointNumber.
*/
int PointCloud::getpointNumber() const {
	return pointNumber;
}
/**
* @brief	: This function is adding two PointClouds.
* @param	: _PC is a parameter for getting a PointCloud.
*/
PointCloud& PointCloud::operator+(const PointCloud& P) {
	
	PointCloud NP(pointNumber + P.pointNumber);

	for (int i = 0; i < pointNumber; i++) {
		NP.points[i] = points[i];
	}

	for (int i = pointNumber, j = 0; i < NP.getpointNumber(); i++, j++) {
		NP.points[i] = P.points[j];
		cout << " ";
	}

	return NP;
}
/**
* @brief	: This function is setting a PointCloud with anothers attributes.
* @param	: _PC is a parameter for getting a PointCloud.
*/
PointCloud& PointCloud::operator=(const PointCloud& PC) {

	delete[]points;

	pointNumber = PC.getpointNumber();

	points = new Point[pointNumber];

	for (int i = 0; i < pointNumber; i++) {
		points[i] = PC.points[i];
	}

	return (*this);
}
