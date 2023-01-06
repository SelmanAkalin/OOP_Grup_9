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
	list<Point> pP1, pP2;

	pP1 = PC1.getPoints();
	pP2 = PC2.getPoints();

	pP1.push_back(P1);
	pP1.push_back(P2);
	pP1.push_back(P3);
	pP2.push_back(P4);
	pP2.push_back(P5);
	pP2.push_back(P6);

	list<Point>::iterator it1, it2;
	int i;
	for (i = 0, it1 = pP1.begin(); it1 != pP1.end(); it1++, i++)
		cout << "PC1 " << i << ". nokta X: " << (*it1).getX() << " Y: " << (*it1).getY() << " Z: " << (*it1).getZ() << endl;

	for (i = 0, it2 = pP2.begin(); it2 != pP2.end(); it2++, i++)
		cout << "PC2 " << i << ". nokta X: " << (*it2).getX() << " Y: " << (*it2).getY() << " Z: " << (*it2).getZ() << endl;

	cout << "PC1 pointNumber: " << PC1.getpointNumber() << endl << "PC2 pointNumber: " << PC2.getpointNumber() << endl;

	PC1.setPoints(pP1);
	PC2.setPoints(pP2);

	PointCloud PC3(PC1.getpointNumber());

	list<Point>::iterator it3;

	PC3 = PC1;

	list<Point>pP3 = PC3.getPoints();

	for (i = 0, it3 = pP3.begin(); it3 != pP3.end(); it3++, i++)
		cout << "PC3 " << i << ". nokta X: " << (*it3).getX() << " Y: " << (*it3).getY() << " Z: " << (*it3).getZ() << endl;

}

int main() {

	Point_TEST();

	PointCloud_TEST();

	system("pause");

	return 0;
}