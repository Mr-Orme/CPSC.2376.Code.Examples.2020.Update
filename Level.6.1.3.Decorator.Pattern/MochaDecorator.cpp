#include "MochaDecorator.h"



MochaDecorator::MochaDecorator(std::unique_ptr<Beverage> beverage):AddOnDecorator(std::move(beverage))
{
}

float MochaDecorator::cost() const
{
	return beverage->cost() + 0.25f;
}
