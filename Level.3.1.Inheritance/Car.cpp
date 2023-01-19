#include "Car.h"
std::random_device Car::seed;
std::default_random_engine Car::engine(seed());
Car::Car(): 
	Vehicle()
{

}
