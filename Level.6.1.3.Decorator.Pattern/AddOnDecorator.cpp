#include "AddOnDecorator.h"



AddOnDecorator::AddOnDecorator(std::unique_ptr<Beverage> beverage):beverage(std::move(beverage))
{}

