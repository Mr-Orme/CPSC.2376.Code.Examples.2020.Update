#include <iostream>
#include <sstream>
#include "Truck.h"

using namespace std;

Truck::Truck()
{ /*Default Constructor of Vehicle is called*/
	this->position = { -3.0f, -3.1f };
	this->name = "Truck";

}

Truck::~Truck() {
}

string Truck::toString() {

	stringstream result;

	result << "(Truck Object, " << Vehicle::toString() << ")";

	return(result.str());
}

void Truck::changePosition(char command) {

	switch (command) {
	case 'l':
		setPosition({ getPosition().x - 2, getPosition().y });
		break;
	case 'r':
		setPosition({ getPosition().x + 3, getPosition().y });
		break;
	case 'f':
		setPosition({ getPosition().x, getPosition().y + 4 });
		break;
	case 'b':
		setPosition({ getPosition().x, getPosition().y - 5 });
		break;
	default:
		break;
	}



}
