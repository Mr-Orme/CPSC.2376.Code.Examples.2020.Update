#include "CaramelDecorator.h"



CaramelDecorator::CaramelDecorator(std::unique_ptr<Beverage> beverage):AddOnDecorator(std::move(beverage))
{
}

float CaramelDecorator::cost() const
{
	return beverage->cost() + 0.25f;
}
