#ifndef PLANE_H
#define PLANE_H

#include <string>
#include "Vehicle.h"

using namespace std;

class Plane : public Vehicle {

private:
	float z;

public:
	Plane();
	~Plane();

	void changePosition(char) override;
	string toString() override;
	//void changePosition(char);
	//string toString();


};

#endif