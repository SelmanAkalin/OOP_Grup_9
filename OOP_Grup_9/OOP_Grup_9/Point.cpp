/**
* @Author	: Selman Akalýn
* @date		: 23.12.2022
* @file		: Point.cpp
*/
#include"Point.h"
/**
* @brief	: Constructor with parameters
* @param	: _x, _y and _z are parameters for setting classes attributes.
*/
Point::Point(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
/**
* @brief	: Constructor without parameters
*/
Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}
/**
* @brief	: Destructor
*/
Point::~Point() {}
/**
* @brief	: This function is for changing x value.
* @param	: _x is a parameter for setting  x.
*/
void Point::setX(const double& _x) {
	x = _x;
}
/**
* @brief	: This function is for changing y value.
* @param	: _y is a parameter for setting  y.
*/
void Point::setY(const double& _y) {
	y = _y;
}
/**
* @brief	: This function is for changing z value.
* @param	: _z is a parameter for setting  z.
*/
void Point::setZ(const double& _z) {
	z = _z;
}
/**
* @brief	: This function is for returning x value.
*/
double Point::getX()const {
	return x;
}
/**
* @brief	: This function is for returning y value.
*/
double Point::getY()const {
	return y;
}
/**
* @brief	: This function is for returning z value.
*/
double Point::getZ()const {
	return z;
}
/**
* @brief	: This function is deciding if two Points are equal or not.
* @param	: P is a parameter for comparing.
*/
bool Point::operator==(const Point& P)const {
	if (x == P.x&&y == P.y&&z == P.z) return true;

	else return false;
}
/**
* @brief	: This function is setting a  point with another.
* @param	: P is a parameter for setting.
*/
void Point::operator=(const Point& P) {
	setX(P.x);
	setY(P.y);
	setZ(P.z);
}
/**
* @brief	: This functions job is calculating and returning between two Points distance.
* @param	: P is a parameter for calculating.
*/
double Point::distance(const Point& P)const {
	return sqrt((x - P.x)*(x - P.x) + (y - P.y)*(y - P.y) + (z - P.z)*(z - P.z));
}