#include <iostream>
#include <string>
#include <sstream>
#include "Vehicle.h"

using namespace std;


Vehicle::Vehicle() :position{ 0,0 }, name{ "Vehicle" } {}


Vehicle::~Vehicle() {}


void Vehicle::setPosition(Coordinate position)
{
	this->position = position;
}

void Vehicle::setName(string name)
{
	this->name = name;
}

Coordinate Vehicle::getPosition() const
{
	return(position);
}



string Vehicle::getName()
{
	return(name);
}


string Vehicle::toString() {
	stringstream result;
	result << "(Vehicle Object, " << name << ": x=" << position.x << ", y=" << position.y << ")";
	return(result.str());
}

void Vehicle::changePosition(char command) {

	switch (command) {
	case 'l':
		position.x--;
		break;
	case 'r':
		position.x++;
		break;
	case 'f':
		position.y++;
		break;
	case 'b':
		position.y--;
		break;
	default:
		break;
	}

}