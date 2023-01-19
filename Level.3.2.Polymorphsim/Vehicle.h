#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<string>

struct Coordinate
{
	Coordinate(float x, float y) :x{ x }, y{ y } {}
	float x{ 0.0f };
	float y{ 0.0f };
};

class Vehicle {
public:

	Vehicle();
	~Vehicle();

	void setPosition(Coordinate position);
	void setName(std::string name);

	Coordinate getPosition() const;
	std::string getName();

	/*** Abtract Classs ***/
	virtual std::string toString() = 0;
	virtual void changePosition(char) = 0;
	
	/*** polmorphic ***/
	//virtual std::string toString();
	//virtual void changePosition(char);

	/*** non-polymorphic ***/
	//std::string toString();
	//void changePosition(char);


protected:
	Coordinate position{ 0.0f,0.0f };
	std::string name;




};

#endif