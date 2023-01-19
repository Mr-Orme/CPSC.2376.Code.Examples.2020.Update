#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle() :x(1.1f), y(1.1f), name("Vehicle")
{
	cout << "Vehicle constructor" << endl;
}

Vehicle::Vehicle(float x, float y) : x{ x }, y{ y }
{
}

void Vehicle::setX(float x)
{
	this->x = x;
}

void Vehicle::setY(float y)
{
	this->y = y;
}

float Vehicle::getX() const
{
	return(x);
}

float Vehicle::getY() const
{
	return(y);
}

ostream& operator <<(ostream& o, const Vehicle& src) {
	o << "(Vehicle Object, " << src.name << ": x=" << src.x << ", y=" << src.y << ")";
	return o;

}