#pragma once
#include"PointCloud.h"
/**
* @Author	: Canan Çalýk
* @date		: 24.12.2022
* @file		: Transform.h
*/
//! class Transform
class Transform {
private:
	double rotation[3][3];
	double angles[3];
	double trans[3];
	double transMatrix[4][4];
	void setTransMatrix();
	void setTransMatrixWithRotation();
public:
	Transform();
	Transform(double*, double*);
	void setRotation(double[]);
	void setTranslation(double[]);
	Point doTransform(Point);
	PointCloud doTransform(PointCloud);
};