
#ifndef SIMPLESPACESHIP_H
#define SIMPLESPACESHIP_H

#include <string>
#include <memory>
#include "Shield.h"
struct Coordinates
{
	float x{ 0.0f };
	float y{ 0.0f };
};
class SimpleSpaceShip{

public:
	/*******************Default constructor*******************/
	/*called when no values are passed in*/
	SimpleSpaceShip();	//Compiler will create for yoU!			
	/*******************Conversion constructor*******************/
	/*Sets values of classes members upon creation!*/
	SimpleSpaceShip(Coordinates position, int fuel, int frontShield, int rearShield, std::string name);
	/*******************Copy constructor*******************/
	/*Needed with pointer members to prevent shallow copying
	Separate memory spaces are reserved for new object and old*/
	SimpleSpaceShip(const SimpleSpaceShip& src); //compiler will create for you, but will be shallow!
	/*******************Copy Assignment Operator*******************/
	/*When = causes a copy into a new instance of an object
	Separate memory spaces are reserved for new object and old*/
	SimpleSpaceShip& operator=(const SimpleSpaceShip& src) noexcept; //compiler will create for you, but will be shallow!
	/*******************Move constructor*******************/
	/*Notice src is not const! Copies addresses for all pointers, then sets src to nullptr for all pointers
	Separate memory spaces are reserved for new object ONLY*/
	SimpleSpaceShip(SimpleSpaceShip&& src) noexcept; //compiler will just use copy constructor
	/*******************Move Assignment Operator*******************/
	/*Notice src is not const! Copies addresses for all pointers, then sets src to nullptr for all pointers
	Need to be sure to delete memory that is being copied IN TO. 
	moved object is left with nullptr's for all pointers.*/
	SimpleSpaceShip& operator=(SimpleSpaceShip&& src) noexcept; //compiler will just use copy assignment
	/*******************destructor*******************/
	/*called when object dies. Uses to delete memory on the heap!*/
	/*not usually needed with smart pointers!*/
	~SimpleSpaceShip();				//destructor

	Coordinates getPosition() const;//accessor method
	int getFrontShieldStrength() const;//accessor method
	int getRearShieldStrength() const;//accessor method
	void setPosition(Coordinates);//accessor method
	void setFrontShieldStrength(int);//accessor method
	void setRearShieldStrength(int strength);//accessor method
	void setName(std::string);		//accessor method
	void print() const;				//I/O method

private: 
	Coordinates position{ 0.0f, 0.0f };   //data member
	std::string name;//data member
	int fuel{ 0 };        //data member

	std::unique_ptr<Shield> frontShield{ nullptr }; //data member 
	std::unique_ptr<Shield> rearShield{ nullptr }; //data member

};

#endif