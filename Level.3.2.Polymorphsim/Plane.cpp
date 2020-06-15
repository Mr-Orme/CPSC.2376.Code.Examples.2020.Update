#include <iostream>
#include <sstream>
#include "Plane.h"

using namespace std;

Plane::Plane() { /*Default Constructor of Vehicle is called*/
	setPosition({ 2.0f, 2.1f });
	setName("Plane");
	z = 2.2;
}

Plane::~Plane() {
}

string Plane::toString() {

	stringstream result;

	result << "(Plane Object, " << Vehicle::toString() << ", z=" << z << ")";

	return(result.str());
}

void Plane::changePosition(char command) {

	switch (command) {
	case 'u':
		z++;
		break;
	case 'd':
		z--;
		break;
	default:
		Vehicle::changePosition(command); //Handles other commands AND ignores garbage
		break;
	}

}
