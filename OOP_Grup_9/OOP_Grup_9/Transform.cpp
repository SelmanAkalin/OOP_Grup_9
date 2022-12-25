/**
* @Author	: Canan Çalýk
* @date		: 24.12.2022
* @file		: Transform.cpp
*/
#include"Transform.h"
/**
* @brief	: Constructor without parameters.
*/
Transform::Transform() {
	for (int i = 0; i < 3; i++) {
		angles[i] = 0;
		trans[i] = 0;
		for (int j = 0; j < 3; j++) {
			rotation[i][j] = 0;
		}
	}
}
/**
* @brief	: Constructor with parameters.
* @param	: _r is a parameter for setting classes rotation matrix and _t is setting classes trans matrix.
*/
Transform::Transform(double* _r, double* _t) {
	for (int i = 0; i < 3; i++) {
		trans[i] = _t[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			rotation[i][j] = (*_r);
			_r++;
		}
	}
	setTransMatrixWithRotation();
}
/**
* @brief	: This function setting transMatrix with rotation matrix.
*/
void Transform::setTransMatrixWithRotation() {
	transMatrix[0][0] = rotation[0][0];
	transMatrix[0][1] = rotation[0][1];
	transMatrix[0][2] = rotation[0][2];
	transMatrix[1][0] = rotation[1][0];
	transMatrix[1][1] = rotation[1][1];
	transMatrix[1][2] = rotation[1][2];
	transMatrix[2][0] = rotation[2][0];
	transMatrix[2][1] = rotation[2][1];
	transMatrix[2][2] = rotation[2][2];
	transMatrix[0][3] = trans[0];
	transMatrix[1][3] = trans[1];
	transMatrix[2][3] = trans[2];
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	transMatrix[3][3] = 1;
}
/**
* @brief	: This function setting transMatrix with angles matrix.
*/
void Transform::setTransMatrix()	 
{									
	transMatrix[0][0] = cos(angles[2])*cos(angles[1]);
	transMatrix[0][1] = cos(angles[2])*sin(angles[1])*sin(angles[0]) - sin(angles[2])*cos(angles[0]);
	transMatrix[0][2] = cos(angles[2])*sin(angles[1])*cos(angles[0]) + sin(angles[2])*sin(angles[0]);
	transMatrix[1][0] = sin(angles[2])*cos(angles[1]);
	transMatrix[1][1] = sin(angles[2])*sin(angles[1])*sin(angles[0]) + cos(angles[2])*cos(angles[0]);
	transMatrix[1][2] = sin(angles[2])*sin(angles[1])*cos(angles[0]) - cos(angles[2])*sin(angles[0]);
	transMatrix[2][0] = -(sin(angles[1]));
	transMatrix[2][1] = cos(angles[1])*sin(angles[0]);
	transMatrix[2][2] = cos(angles[1])*cos(angles[0]);
	transMatrix[0][3] = trans[0];
	transMatrix[1][3] = trans[1];
	transMatrix[2][3] = trans[2];
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	transMatrix[3][3] = 1;
}
/**
* @brief	: This function setting angles matrix with ang parameter.
* @param	: ang is a parameter for setting angles. 
*/
void Transform::setRotation(double ang[]) {
	for (int i = 0; i < 3; i++)angles[i] = ang[i];
	setTransMatrix();
}
/**
* @brief	: This function setting trans matrix with tr parameter.
* @param	: tr is a parameter for setting trans.
*/
void Transform::setTranslation(double tr[]) {
	for (int i = 0; i < 3; i++)trans[i] = tr[i];
	setTransMatrix();
}
/**
* @brief	: This function doing transform with a point.
* @param	: p is a parameter for doing transform.
*/
Point Transform::doTransform(Point p) {
	double lastD[3];
	for (int i = 0; i < 3; i++) {
		lastD[i] = p.getX()*transMatrix[i][0] + p.getY()*transMatrix[i][1] + p.getZ()*transMatrix[i][2] + 1 * transMatrix[i][3];
	}
	Point retP(lastD[0], lastD[1], lastD[2]);
	return retP;
}
/**
* @brief	: This function doing transform with a PointCloud.
* @param	: pc is a parameter for doing transform.
*/
PointCloud Transform::doTransform(PointCloud pc) {
	PointCloud retPC(pc);
	Point* now = retPC.getPoints();
	for (int i = 0; i < pc.getpointNumber(); i++)
	{
		(*now) = doTransform(*now);
		now++;
	}
	return retPC;
}