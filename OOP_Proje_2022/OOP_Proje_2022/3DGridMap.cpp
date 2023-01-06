/**
* @Author	: Ali Yalnýz
* @date		: 24.12.2022
* @file		: 3DGridMap.cpp
*/
#include"3DGridMap.h"
/**
* @brief	: Constructor without parameter.
*/
GridMap::GridMap() {
	for (int i = 0; i < 75; i++) {
		for (int j = 0; j < 75; j++) {
			for (int k = 0; k < 75; k++) {
				map[i][j][k] = false;
			}
		}
	}
	gridSize = 0.08;
	depth = 0;
}
/**
* @brief	: Constructor with parameters.
* @param	: _gridSize is a parameter for setting gridSize attribute, _depth is a parameter for setting depth.
*/
GridMap::GridMap(float _gridSize = 0.08, int _depth = 0) :gridSize(_gridSize), depth(_depth) {
	for (int i = 0; i < 75; i++) {
		for (int j = 0; j < 75; j++) {
			for (int k = 0; k < 75; k++) {
				map[i][j][k] = false;
			}
		}
	}
}
/**
* @brief	: setgridSize is a funcion for setting gridSize.
* @param	: _gridSize is a parameter for setting gridSize attribute.
*/
void GridMap::setgridSize(float _gridSize) {
	gridSize = _gridSize;
}
/**
* @brief	: getgridSize is a funcion for returning gridSize.
*/
float GridMap::getgridSize()const {
	return gridSize;
}
/**
* @brief	: getdepth is a funcion for returning depth.
*/
int GridMap::getdepth()const {
	return depth;
}
/**
* @brief	: insertPointCloud is a funcion for putting a PointCloud into map.
* @param	: _PC is a parameter for putting into map.
*/
void GridMap::insertPointCloud(PointCloud& _PC) {
	list<Point> tut = _PC.getPoints();
	for (int i = 0; i < _PC.getpointNumber(); i++) {
		insertPoint(tut.back());
		tut.pop_back();
	}
}
/**
* @brief	: insertPoint is a funcion for putting a Point into map.
* @param	: _P is a parameter for putting into map.
*/
void GridMap::insertPoint(Point& _P) {
	int rotatX = 37 + _P.getX() / gridSize;
	int rotatY = 37 + _P.getY() / gridSize;
	int rotatZ = 37 + _P.getZ() / gridSize;

	map[rotatX][rotatY][rotatZ] = true;

	depth++;
}
/**
* @brief	: getGrid is a funcion for getting a locations value.
* @param	: _i, _j and _k are parameters for finding location.
*/
bool GridMap::getGrid(int _i, int _j, int _k)const {

	return map[_i][_j][_k];
}
/**
* @brief	: loadMap is a funcion for loading a map from a file.
* @param	: fileName is a parameter for accessing file.
*/
bool GridMap::loadMap(string fileName) {
	fstream file(fileName, ios::in);

	if (!file) return false;

	int i = 0;
	int j = 0;
	int k = 0;

	depth = 0;
	
	while (!file.eof()) {

		char value;

		file >> value;
		
		map[i][j][k] = value;

		depth++;

		k++;
		if (k == 75) {
			j++;
			k = 0;
		}
		if (j == 75) {
			i++;
			j = 0;
		}
	}



	file.close();

	return true;
}
/**
* @brief	: saveMap is a funcion for saving a map into a file.
* @param	: fileName is a parameter for accessing file.
*/
bool GridMap::saveMap(string fileName) {
	fstream file;

	file.open(fileName, ios::out);

	if (!file)return false;

	for (int i = 0; i < 75; i++) {
		for (int j = 0; j < 75; j++) {
			for (int k = 0; k < 75; k++) {
				if (map[i][j][k] == 0)file << '0';
				else file << '1';
			}
		}
	}

	file.close();

	return true;
}