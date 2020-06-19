#include <iostream>
#include "SimpleSpaceShip.h"

using namespace std;

SimpleSpaceShip::SimpleSpaceShip()
{
	name += "_default";
	cout << "Default Constructor Called, " << name << endl;
}

SimpleSpaceShip::SimpleSpaceShip(Vector2D position, int fuel) : position{ position }, fuel{ fuel }
{
	name += "_conversion";
	cout << "Conversion Constructor Called, " << name << endl;
}
void SimpleSpaceShip::setPosition(Vector2D position)
{
	this->position = position;
}

void SimpleSpaceShip::setName(string name)
{
	this->name = name;
}

void SimpleSpaceShip::print() const {
	cout << name << ", Position: (" << position.x << ", " << position.y << ", " << fuel << ")" << endl;
}