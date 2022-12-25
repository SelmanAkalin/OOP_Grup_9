/**
* @Author	: Selman Akalýn
* @date		: 24.12.2022
* @file		: Point_PointCloud_TEST.cpp
*/
#include"PointCloud.h"
/**
* @brief	: Testing Point classes functions.
*/
void Point_TEST() {
	Point P1, P2;
	P1.setX(1.1111);
	P1.setY(1.2222);
	P1.setZ(1.3333);

	P2.setX(2.1111);
	P2.setY(2.2222);
	P2.setZ(2.3333);

	cout << "P1(X, Y, Z) = (" << P1.getX() << ", " << P1.getY() << ", " << P1.getZ() << ")\n";
	cout << "P2(X, Y, Z) = (" << P2.getX() << ", " << P2.getY() << ", " << P2.getZ() << ")\n";

	if (P1 == P2) {
		cout << "Iki nokta birbirine esit.\n";
	}
	else {
		cout << "Iki nokta farkli.\n";
	}

	cout << "P1 ve P2 arasindaki uzaklik = " << P1.distance(P2) << endl;

	P1 = P2;

	if (P1 == P2) {
		cout << "Iki nokta birbirine esit.\n";
	}
	else {
		cout << "Iki nokta farkli.\n";
	}

	cout << "P1 ve P2 arasindaki uzaklik = " << P1.distance(P2) << endl;
}
/**
* @brief	: Testing PointCloud classes functions.
*/
void PointCloud_TEST() {

	Point P1, P2, P3, P4, P5, P6;
	P1.setX(1.1111);
	P1.setY(1.2222);
	P1.setZ(1.3333);

	P2.setX(2.1111);
	P2.setY(2.2222);
	P2.setZ(2.3333);

	P3.setX(3.1111);
	P3.setY(3.2222);
	P3.setZ(3.3333);

	P4.setX(4.1111);
	P4.setY(4.2222);
	P4.setZ(4.3333);

	P5.setX(5.1111);
	P5.setY(5.2222);
	P5.setZ(5.3333);

	P6.setX(6.1111);
	P6.setY(6.2222);
	P6.setZ(6.3333);

	PointCloud PC1(3), PC2(3);
	Point *pP1, *pP2;

	pP1 = PC1.getPoints();
	pP2 = PC2.getPoints();

	pP1[0] = P1;
	pP1[1] = P2;
	pP1[2] = P3;
	pP2[0] = P4;
	pP2[1] = P5;
	pP2[2] = P6;

	for (int i = 0; i < 3; i++) {
		cout << "PC1 " << i << ". nokta X: " << pP1[i].getX() << " Y: " << pP1[i].getY() << " Z: " << pP1[i].getZ() << endl;
		cout << "PC2 " << i << ". nokta X: " << pP2[i].getX() << " Y: " << pP2[i].getY() << " Z: " << pP2[i].getZ() << endl;
	}

	cout << "PC1 pointNumber: " << PC1.getpointNumber() << endl << "PC2 pointNumber: " << PC2.getpointNumber() << endl;

	PC1.setPoints(pP1);
	PC2.setPoints(pP2);

	PointCloud PC3(PC1.getpointNumber() + PC2.getpointNumber());

	PC3 = PC1;

	Point *pP3 = PC3.getPoints();

	for (int i = 0; i < PC3.getpointNumber(); i++) {
		cout << "PC3 " << i << ". nokta X: " << (*pP3).getX() << " Y: " << (*pP3).getY() << " Z: " << (*pP3).getZ() << endl;
		pP3++;
	}

}

int main() {

	Point_TEST();

	PointCloud_TEST();

	system("pause");

	return 0;
}