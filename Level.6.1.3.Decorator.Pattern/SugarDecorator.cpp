#include "SugarDecorator.h"



SugarDecorator::SugarDecorator(std::unique_ptr<Beverage> beverage): AddOnDecorator(std::move(beverage))
{
}

float SugarDecorator::cost() const
{
	return beverage->cost() + 0.0f;
}
