/*
* File: SimpleSpaceShip.cpp
* Author: Keith Bush (2012)
*/
#include <iostream>
#include "SimpleSpaceShip.h"

SimpleSpaceShip::SimpleSpaceShip()
{
	name += "_default";
	std::cout << "Default Constructor Called, " << name << std::endl;
}

SimpleSpaceShip::SimpleSpaceShip(Coordinates position, int fuel, int frontShield, int rearShield, std::string name)
	:frontShield{ std::make_unique<Shield>(frontShield) }, 
	rearShield{ std::make_unique<Shield>(rearShield) }, 
	position{ position }, 
	fuel{ fuel }
{
	this->name = name + "_conversion";

	std::cout << "Conversion Constructor Called, " << name << std::endl;
}

SimpleSpaceShip::SimpleSpaceShip(const SimpleSpaceShip& src)
//new memory created
	: frontShield{ std::make_unique<Shield>(src.frontShield->getStrength()) },
	rearShield{ std::make_unique<Shield>(src.rearShield->getStrength()) },
	//rearShield(src.rearShield.get()),
	position(src.position),
	fuel(src.fuel),
	name(src.name + "_copy")
{
	std::cout << "Copy Constructor Called, " << name << std::endl;
}

SimpleSpaceShip::SimpleSpaceShip(SimpleSpaceShip && src) noexcept
	: 
	//1. Steal resources from src.
	frontShield{ std::move(src.frontShield) }, 
	rearShield{ std::move(src.rearShield) },
	position{ src.position },
	fuel{ src.fuel },
	name(src.name + "_move")
{
	//2. kill off src resources.
	//some done in initializers list with std::move
	src.position = { 0.0f, 0.0f };
	src.fuel = 0;
	src.name = " ";

	std::cout << "Move Constructor Called, " << name << std::endl;

}
SimpleSpaceShip& SimpleSpaceShip::operator=(const SimpleSpaceShip& src) noexcept
{
	//don't copy from myself!
	if (this == &src)
	{
		return *this;
	}
	
	//copy non-pointer values
	position = src.position;
	fuel = src.fuel;
	name = src.name + "_copyAssignment";
	
	//copy heap values from src
	frontShield = std::make_unique<Shield>(src.frontShield->getStrength());
	rearShield = std::make_unique<Shield>(src.rearShield->getStrength());
	
	return *this;
}
SimpleSpaceShip& SimpleSpaceShip::operator=(SimpleSpaceShip&& src) noexcept
{
	//1. release my resouces
	//We are using smart pointers, so not necessary!
	
	//2. Steal resources from src.
	frontShield = std::move(src.frontShield);
	rearShield = std::move(src.rearShield);
	position = src.position;
	fuel = src.fuel;
	name = src.name + "_moveAssignment";

	//3. kill off src resources.
	//some done above with std::move
	src.position = { 0.0f, 0.0f };
	src.fuel = 0;
	src.name = " ";

	std::cout << "Move Assignment Called, " << name << std::endl;

	return *this;
}

SimpleSpaceShip::~SimpleSpaceShip()
{
	std::cout << name << " is being destroyed" << std::endl;
}

Coordinates SimpleSpaceShip::getPosition() const
{
	return position;
}

int SimpleSpaceShip::getFrontShieldStrength() const
{
	return frontShield->getStrength();
}

int SimpleSpaceShip::getRearShieldStrength() const
{
	return rearShield->getStrength();
}

void SimpleSpaceShip::setPosition(Coordinates position)
{
	this->position = position;
}

void SimpleSpaceShip::setName(std::string name)
{
	this->name = name;
}

void SimpleSpaceShip::setFrontShieldStrength(int strength)
{
	frontShield->setStrength(strength);
}

void SimpleSpaceShip::setRearShieldStrength(int strength)
{
	rearShield->setStrength(strength);

}

void SimpleSpaceShip::print() const {
	std::cout << name << ", Position: (" << position.x << ", " << position.y << ", " << fuel << ")" << std::endl;
}


