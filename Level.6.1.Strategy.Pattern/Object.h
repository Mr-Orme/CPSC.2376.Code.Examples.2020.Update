#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <map>
#include <memory>
#include "iStratgey.h"

struct Coordinate
{
	Coordinate(float x, float y) :x{ x }, y{ y } {}
	float x{ 0.0f };
	float y{ 0.0f };
};

class Object {
public:

	Object();
	~Object();

	void setPosition(Coordinate position);
	void setName(std::string name);

	Coordinate getPosition() const;
	std::string getName();

	/* Lesson 3: Polymorphism via dynamic binding*/

	virtual std::string toString();
	void changePosition(char);
	Coordinate position{ 0.0f,0.0f };

protected:
	std::map<char, std::unique_ptr<iStrategy>> behaviors;
	
	std::string name;

};
#endif // !OBJECT_H

