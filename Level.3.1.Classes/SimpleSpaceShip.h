
#ifndef SIMPLESPACESHIP_H
#define SIMPLESPACESHIP_H

#include <string>

struct Vector2D
{
	float x{ 0.0f };
	float y{ 0.0f };
};

class SimpleSpaceShip {

public:

	SimpleSpaceShip();				//default constructor
	SimpleSpaceShip(Vector2D position, std::string name);   //conversion constructor

	Vector2D getPosition() const;		//accessor method
	void setPosition(Vector2D position);		//accessor method	
	void setName(std::string);	//accessor method

	void print() const;		//I/O method
private:
	Vector2D position{ 0.0f, 0.0f };
	std::string name{ "Enterprise" };   //data member
	int fuel{ 0 };     //data member (no accessors for teaching purposes)


};

#endif