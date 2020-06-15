
#ifndef SIMPLESPACESHIP1_H
#define SIMPLESPACESHIP1_H

#include <string>
#include <iostream>
using namespace std;
struct Coordinates
{
	Coordinates(float x, float y) :x{ x }, y{ y }{}
	Coordinates() {};
	float x{ 0.0f };
	float y{ 0.0f };
};
class SimpleSpaceShip {

public:

	SimpleSpaceShip();				//default constructor
	SimpleSpaceShip(Coordinates position, int fuel, int shield, std::string name);   //conversion constructor


	Coordinates getPosition() const;		//accessor method
	int getShieldStrength()const;
	std::string getName() const;

	void setPosition(Coordinates position);		//accessor method	
	void setName(std::string);	//accessor method


	//return is by reference (&) which forces you to return something that exists past the life of the function.
	// paramaters are const and & because information is being gleaned from src, but src is not changed.
	SimpleSpaceShip& operator=(const SimpleSpaceShip & src);
	SimpleSpaceShip& operator++();
	SimpleSpaceShip& operator--();
	SimpleSpaceShip& operator+= (const SimpleSpaceShip& src);
	
	int fuel{ 0 };     //data member 
private:
	Coordinates position{ 0.0f, 0.0f };
	std::string name{ "Enterprise" };   //data member
	const int shield{ 0 };
};

/**** NOTE:: these are outside the class! ****/
/**** so we cannot access private members ****/
//arithmetic operators create new memory with new instance of class, so return is NOT &
SimpleSpaceShip operator+(const SimpleSpaceShip& srcL, const SimpleSpaceShip& srcR);
SimpleSpaceShip operator-(const SimpleSpaceShip& srcL, const SimpleSpaceShip& srcR);

//stream operators chain pieces together, so takes an ostream and returns one to carry on the chain.
//the stream is modified by what is in src.
std::ostream& operator<<(std::ostream& o, const SimpleSpaceShip& src);
//notice src is not const! because >> modifies src!!!
std::istream& operator>>(std::istream& o, SimpleSpaceShip& src);

//boolean operators return bool! define < and all the rest should be based off of <
bool operator<(const SimpleSpaceShip& srcL, const SimpleSpaceShip& srcR);
bool operator>(const SimpleSpaceShip& srcL, const SimpleSpaceShip& srcR);

//define == and != should be based off of ==
bool operator==(const SimpleSpaceShip& srcL, const SimpleSpaceShip& srcR);
bool operator!=(const SimpleSpaceShip& srcL, const SimpleSpaceShip& srcR);

#endif