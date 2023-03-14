#include <iostream>
#include "SimpleSpaceShip.h"

using namespace std;

SimpleSpaceShip::SimpleSpaceShip()
{
	name += "_default";
	std::cout << "Default Constructor Called, " << name << endl;
}

SimpleSpaceShip::SimpleSpaceShip(Coordinates position, int fuel, int shield, std::string name)
	:shield{ shield }, position{ position }, fuel{ fuel }
{
	this->name = name + "_conversion";

	cout << "Conversion Constructor Called, " << name << endl;
}

Coordinates SimpleSpaceShip::getPosition() const
{
	return position;
}


void SimpleSpaceShip::setPosition(Coordinates position)
{
	this->position = position;
}

int SimpleSpaceShip::getShieldStrength() const
{
	return shield;
}

std::string SimpleSpaceShip::getName() const
{
	return name;
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

SimpleSpaceShip& SimpleSpaceShip::operator+=(int src)
{
	fuel += src;
	return *this;
}

SimpleSpaceShip operator+(const SimpleSpaceShip & srcL, const SimpleSpaceShip & srcR)
{
	return 
	{
		{
			srcL.getPosition().x + srcR.getPosition().x, 
			srcL.getPosition().y + srcR.getPosition().y 
		}
		, srcL.fuel + srcR.fuel
		, srcL.getShieldStrength() + srcR.getShieldStrength() 
		, srcL.getName()
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

bool operator<=(const SimpleSpaceShip& srcL, const SimpleSpaceShip& srcR)
{
	return (srcL < srcR) || srcL == srcR;
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
