#pragma once
#include "AddOnDecorator.h"
class SugarDecorator :
	public AddOnDecorator
{
public:
	SugarDecorator() = delete;
	SugarDecorator(std::unique_ptr<Beverage> beverage);
	float cost() const override;
};

