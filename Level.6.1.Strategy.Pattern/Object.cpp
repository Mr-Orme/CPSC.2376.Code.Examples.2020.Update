#include <iostream>
#include <string>
#include <sstream>
#include "Object.h"
#include "LeftStrategy.h"
#include "RightStrategy.h"
#include "AccelerateStrategy.h"
#include "DecelerateStrategy.h"

using namespace std;


Object::Object() :position{ 0,0 }, name{ "Object" } 
{
	behaviors['l'] = std::make_unique<LeftStrategy>();
	behaviors['r'] = std::make_unique<RightStrategy>();
	behaviors['f'] = std::make_unique<AccelerateStrategy>();
	behaviors['b'] = std::make_unique<DecelerateStrategy>();
}


Object::~Object() {}


void Object::setPosition(Coordinate position)
{
	this->position = position;
}

void Object::setName(string name)
{
	this->name = name;
}

Coordinate Object::getPosition() const
{
	return(position);
}



string Object::getName()
{
	return(name);
}


string Object::toString() {
	stringstream result;
	result << "(Object Object, " << name << ": x=" << position.x << ", y=" << position.y << ")";
	return(result.str());
}

void Object::changePosition(char command)
{
	auto currStrategy = behaviors.find(command);
	if (currStrategy != behaviors.end())
	{
		currStrategy->second->execute(this);
	}
}
//void Object::changePosition(char command) {
//
//	switch (command) {
//	case 'l':
//		position.x--;
//		break;
//	case 'r':
//		position.x++;
//		break;
//	case 'f':
//		position.y++;
//		break;
//	case 'b':
//		position.y--;
//		break;
//	default:
//		break;
//	}
//
//}