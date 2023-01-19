#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>

class Vehicle {

public:
	

	Vehicle();
	Vehicle(float x, float y);
	void setX(float);
	void setY(float);
	float getX() const;
	float getY() const;	
	float x{ 0 };

	friend std::ostream& operator <<(std::ostream&, const Vehicle&);

protected:

	float y{ 0 };

	std::string name{ " " };

};


#endif