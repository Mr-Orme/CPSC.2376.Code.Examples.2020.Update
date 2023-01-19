/*
 * File: SimpleSpaceShip.cpp
 * Author: Keith Bush (2012)
 */
#include <iostream>
#include "SimpleSpaceShip.h"

using namespace std;

SimpleSpaceShip::SimpleSpaceShip()
{
	name += "_default";
	cout << "Default Constructor Called, " << name << endl;
}

SimpleSpaceShip::SimpleSpaceShip(Vector2D position, std::string name)
	: position{ position }, name{ name }
{
	name += "_conversion";
	cout << "Conversion Constructor Called, " << name << endl;
}


void SimpleSpaceShip::setName(string name)
{
	this->name = name;
}

void SimpleSpaceShip::print() const {
	cout << name << ", Position: (" << position.x << ", " << position.y << ", " << fuel << ")" << endl;
}