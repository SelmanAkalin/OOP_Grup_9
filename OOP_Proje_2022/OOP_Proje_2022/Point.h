/**
* @Author	: Selman Akalýn
* @date		: 23.12.2022
* @file		: Point.h
*/
#pragma once

#include<iostream>
#include<string>
#include<list>

using namespace std;
//! class Point
class Point {
private:
	double x;
	double y;
	double z;
public:
	Point(double, double, double);
	Point();
	~Point();
	void setX(const double&);
	void setY(const double&);
	void setZ(const double&);
	double getX()const;
	double getY()const;
	double getZ()const;
	bool operator==(const Point&)const;
	void operator=(const Point&);
	double distance(const Point&)const;
};