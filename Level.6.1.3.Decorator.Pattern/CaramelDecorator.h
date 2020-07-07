#pragma once
#include "AddOnDecorator.h"
class CaramelDecorator :
	public AddOnDecorator
{
public:
	CaramelDecorator() = delete;
	CaramelDecorator(std::unique_ptr<Beverage> beverage);
	float cost() const override;
};

