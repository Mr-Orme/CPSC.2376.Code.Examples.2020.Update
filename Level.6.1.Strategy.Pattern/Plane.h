#ifndef PLANE_H
#define PLANE_H

#include <string>
#include "Object.h"

using namespace std;

class Plane : public Object {

public:
	Plane();
	~Plane();
	float z;

	//void changePosition(char) override;
	string toString() override;


};

#endif