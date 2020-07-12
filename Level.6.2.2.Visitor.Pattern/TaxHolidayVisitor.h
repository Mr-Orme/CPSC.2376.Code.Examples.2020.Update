#ifndef TAXHOLIDAYVISITOR_H
#define TAXHOLIDAYVISITOR_H
#include <iostream>

#include "iVisitor.h"
#include "Liquor.h"
#include "Necessity.h"
#include "Tobacco.h"
#include "General.h"
class TaxHolidayVisitor : public iVisitor
{
public:
	double visit(Liquor* liqourItem) override
	{
		std::cout << "Liquor item: Price with tax: $";
		return liqourItem->getPrice() * 1.10;
	}
	double visit(Tobacco* tobaccoItem) override
	{
		std::cout << "Tobacco item: Price with tax: $";
		return tobaccoItem->getPrice() * 1.25;
	}
	double visit(Necessity* necessityItem) override
	{
		std::cout << "Necessity item: Price with tax: $";
		return necessityItem->getPrice() * 1.0;
	}
	double visit(General* generalItem) override
	{
		std::cout << "General item: Price with tax: $";
		return generalItem->getPrice() * 1.00;
	}
private:

};
#endif // !TAXHOLIDAYVISITOR_H

