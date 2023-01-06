#pragma once
#include"PointCloud.h"
#include<Eigen/Dense>
/**
* @Author	: Canan Çalýk
* @date		: 24.12.2022
* @file		: Transform.h
*/
//! class Transform
class Transform {
private:
	//double rotation[3][3];
	Eigen::Matrix3d rotation;
	//double angles[3];
	Eigen::Vector3d angles, trans;
	//double trans[3];
	//double transMatrix[4][4];
	Eigen::Matrix4d transMatrix;

	void setTransMatrix();
	void setTransMatrixWithRotation();
public:
	Transform();
	//Transform(double*, double*);
	Transform(Eigen::Matrix3d, Eigen::Vector3d);
	//void setRotation(double[]);
	void setRotation(Eigen::Vector3d);
	//void setTranslation(double[]);
	void setTranslation(Eigen::Vector3d);
	Point doTransform(Point);
	PointCloud doTransform(PointCloud);
};