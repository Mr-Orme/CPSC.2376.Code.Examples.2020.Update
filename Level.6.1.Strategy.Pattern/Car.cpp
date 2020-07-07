#include <iostream>
#include <sstream>
#include "Car.h"

using namespace std;

Car::Car()
{ /*Default Constructor of Object is called*/
	this->position = { -3.0f, -3.1f };
	this->name = "Car";

}

Car::~Car() {
}

string Car::toString() {

	stringstream result;

	result << "(Car Object, " << Object::toString() << ")";

	return(result.str());
}

//void Car::changePosition(char command) {
//
//	switch (command) {
//	case 'l':
//		setPosition({ getPosition().x - 2, getPosition().y });
//		break;
//	case 'r':
//		setPosition({ getPosition().x + 3, getPosition().y });
//		break;
//	case 'f':
//		setPosition({ getPosition().x, getPosition().y + 4 });
//		break;
//	case 'b':
//		setPosition({ getPosition().x, getPosition().y - 5 });
//		break;
//	default:
//		break;
//	}




