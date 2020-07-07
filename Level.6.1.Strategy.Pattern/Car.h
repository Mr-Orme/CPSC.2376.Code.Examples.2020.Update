#ifndef CAR_H
#define CAR_H

#include <string>
#include "Object.h"

using namespace std;

class Car : public Object {

public:
	Car();
	~Car();

	//void changePosition(char) override;
	string toString() override;


};

#endif