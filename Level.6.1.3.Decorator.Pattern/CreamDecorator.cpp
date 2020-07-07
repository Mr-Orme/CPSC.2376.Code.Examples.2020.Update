#include "CreamDecorator.h"



CreamDecorator::CreamDecorator(std::unique_ptr<Beverage> beverage) :AddOnDecorator(std::move(beverage))
{}

float CreamDecorator::cost() const
{
	return beverage->cost() + 0.10f;
}
