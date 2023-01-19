#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <random>

class Car : public Vehicle 
{

public:
	Car();
	static std::random_device seed;
	static std::default_random_engine engine;
private:

};

#endif

