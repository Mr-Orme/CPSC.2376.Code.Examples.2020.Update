#pragma once
#include "Beverage.h"
class DecafCoffee :
	public Beverage
{
public:
	DecafCoffee();
	float cost() const override;
};

