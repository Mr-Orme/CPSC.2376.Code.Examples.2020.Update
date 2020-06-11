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

SimpleSpaceShip::SimpleSpaceShip(Coordinates position, int fuel, int shield, std::string name)
	:shield{ shield }, position{ position }, fuel{ fuel }
{
	this->name = name + "_conversion";

	cout << "Conversion Constructor Called, " << name << endl;
}

SimpleSpaceShip::SimpleSpaceShip(const SimpleSpaceShip & src) : shield{ src.getShieldStrength() }
{
	position = src.getPosition();
	fuel = src.fuel;
	name = src.getName() + "_copy";

	cout << "Copy Constructor Called, " << name << endl;
}

SimpleSpaceShip::SimpleSpaceShip(SimpleSpaceShip && src) : shield{ src.getShieldStrength() }
{
	//1. release my resouces
	position = { 0.0f, 0.0f };
	fuel = 0;
	name = " ";

	//2. Steal resources from src.
	position = src.getPosition();
	fuel = src.fuel;
	name = src.getName() + "_move";

	//3. kill off src resources.
	src.getPosition() = { 0.0f, 0.0f };
	src.fuel = 0;
	src.getName() = " ";

	//Move constructor becomes less trivial when we learn about pointers! stay tuned!!
	cout << "Move Constructor Called, " << name << endl;

}

SimpleSpaceShip::~SimpleSpaceShip()
{
	cout << name << " is being destroyed" << endl;
}

Coordinates SimpleSpaceShip::getPosition() const
{
	return position;
}

int SimpleSpaceShip::getShieldStrength() const
{
	return shield;
}

std::string SimpleSpaceShip::getName() const
{
	return name;
}

void SimpleSpaceShip::setPosition(Coordinates position)
{
	this->position = position;
}

void SimpleSpaceShip::setName(string name)
{
	this->name = name;
}

SimpleSpaceShip & SimpleSpaceShip::operator=(const SimpleSpaceShip & src)
{
	if (this == &src)
	{
		return *this;
	}

	position = src.getPosition();
	fuel = src.fuel;
	name = src.getName() + "_copyAssignment";
	return *this;
}

SimpleSpaceShip & SimpleSpaceShip::operator++()
{
	position.x++;
	position.y++;
	return *this;
}

SimpleSpaceShip & SimpleSpaceShip::operator--()
{
	position.x--;
	position.y--;
	return *this;
}

SimpleSpaceShip & SimpleSpaceShip::operator+=(const SimpleSpaceShip & src)
{
	*this = *this + src;
	return *this;
}

SimpleSpaceShip operator+(const SimpleSpaceShip & srcL, const SimpleSpaceShip & srcR)
{
	return 
	{
		{srcL.getPosition().x + srcR.getPosition().x, srcL.getPosition().y + srcR.getPosition().y }
		,srcL.fuel + srcR.fuel, srcL.getShieldStrength() + srcR.getShieldStrength() , srcL.getName()
	};
}

SimpleSpaceShip operator-(const SimpleSpaceShip & srcL, const SimpleSpaceShip & srcR)
{
	return
	{
		{ srcL.getPosition().x - srcR.getPosition().x, srcL.getPosition().y - srcR.getPosition().y }
		,srcL.fuel - srcR.fuel, srcL.getShieldStrength() - srcR.getShieldStrength() , srcL.getName()
	};
}

std::ostream & operator<<(std::ostream & o, const SimpleSpaceShip & src)
{
	o << src.getName() << ", Position: (" << src.getPosition().x << ", " << src.getPosition().y << ", " << src.fuel << ")";
	return o;
}

std::istream & operator>>(std::istream & o, SimpleSpaceShip & src)
{
	Coordinates tempPosition;
	o >> tempPosition.x >> tempPosition.y >> src.fuel;
	src.setPosition(tempPosition);
	return o;
}

bool operator<(const SimpleSpaceShip & srcL, const SimpleSpaceShip & srcR)
{
	return srcL.getPosition().x < srcR.getPosition().x && srcL.getPosition().y < srcR.getPosition().y;
}

bool operator>(const SimpleSpaceShip & srcL, const SimpleSpaceShip & srcR)
{
	return srcR < srcL;
}

bool operator==(const SimpleSpaceShip & srcL, const SimpleSpaceShip & srcR)
{
	return srcL.getPosition().x == srcR.getPosition().x && srcL.getPosition().y == srcR.getPosition().y;
}

bool operator!=(const SimpleSpaceShip & srcL, const SimpleSpaceShip & srcR)
{
	return !(srcL==srcR);
}
