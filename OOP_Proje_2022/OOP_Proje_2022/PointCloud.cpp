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
	pointNumber = 0;
}
/**
* @brief	: Constructor with a parameter.
* @param	: _pointNumber is a parameter for setting classes pointNumber attribute.
*/
PointCloud::PointCloud(int _PN) {
	pointNumber = _PN;
}
/**
* @brief	: Copy Constructor with a parameter.
* @param	: _PC is a parameter for setting classes attributes.
*/
PointCloud::PointCloud(const PointCloud& PC) {
	pointNumber = PC.getpointNumber();

	points = PC.points;
	
}
/**
* @brief	: Destructor for deleting list of points.
*/
PointCloud::~PointCloud(){
	points.clear();
}
/**
* @brief	: setPoints function for setting points.
* @param	: P is a parameter for setting points.
*/
void PointCloud::setPoints(list<Point> P) {
	points = P;
}
/**
* @brief	: getPoints function for returning points.
*/
list<Point> PointCloud::getPoints() const {
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

	PointCloud sum(pointNumber + P.getpointNumber());
	list<Point>::iterator it1;

	sum.points = P.getPoints();

	list<Point> list2 = sum.getPoints();

	for (it1 = points.begin(); it1 != points.end(); it1++)
		list2.push_back(*it1);

	sum.setPoints(list2);

	return sum;
}
/**
* @brief	: This function is setting a PointCloud with anothers attributes.
* @param	: _PC is a parameter for getting a PointCloud.
*/
PointCloud& PointCloud::operator=(const PointCloud& PC) {

	points = PC.points;
	pointNumber = PC.pointNumber;
	return (*this);
}
