#pragma once
#include "AddOnDecorator.h"
class CreamDecorator :
	public AddOnDecorator
{
public:
	CreamDecorator() = delete;
	CreamDecorator(std::unique_ptr<Beverage> beverage);
	float cost() const override;
};

