#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>

using namespace std;

class Vehicle {

public:
	

	Vehicle();
	void setX(float);
	void setY(float);
	float getX() const;
	float getY() const;	
	float x{ 0 };

	friend ostream& operator <<(ostream&, const Vehicle&);

protected:

	float y{ 0 };

	std::string name{ " " };

};


#endif