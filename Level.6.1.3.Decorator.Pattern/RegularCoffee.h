#pragma once
#include "Beverage.h"
class RegularCoffee :
	public Beverage
{
public:
	RegularCoffee();
	float cost() const override;
};

