#ifndef TAXVISITOR_H
#define TAXVISITOR_H
#include <iostream>

#include "iVisitor.h"
#include "Liquor.h"
#include "Necessity.h"
#include "Tobacco.h"
#include "General.h"
class TaxVisitor : public iVisitor
{
public:
	double visit(Liquor* liqourItem) override
	{
		std::cout << "Liquor item: Price with tax: $";
		return liqourItem->getPrice() * 1.18;
	}
	double visit(Tobacco* tobaccoItem) override
	{
		std::cout << "Tobacco item: Price with tax: $";
		return tobaccoItem->getPrice() * 1.32;
	}
	double visit(Necessity* necessityItem) override
	{
		std::cout << "Necessity item: Price with tax: $";
		return necessityItem->getPrice() * 1.0;
	}
	double visit(General* generalItem) override
	{
		std::cout << "General item: Price with tax: $";
		return generalItem->getPrice() * 1.07;
	}
private:

};
#endif // !TAXVISITOR_H

