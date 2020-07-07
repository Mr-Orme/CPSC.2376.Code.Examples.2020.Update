#pragma once
#include "AddOnDecorator.h"
class MochaDecorator :
	public AddOnDecorator
{
public:
	MochaDecorator() = delete;
	MochaDecorator(std::unique_ptr<Beverage> beverage);
	float cost() const override;
};

