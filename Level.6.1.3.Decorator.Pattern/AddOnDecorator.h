#pragma once
#include <memory>
#include "Beverage.h"

class AddOnDecorator :
	public Beverage
{
public:
	AddOnDecorator() = delete;
	AddOnDecorator(std::unique_ptr<Beverage> beverage);

	std::unique_ptr<Beverage> beverage;
};

