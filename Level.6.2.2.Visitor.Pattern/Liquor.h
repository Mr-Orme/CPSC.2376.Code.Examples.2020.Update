#ifndef LIQUOR_H
#define LIQUOR_H
#include "GroceryItem.h";
class Liquor : public GroceryItem
{
public:
	Liquor(float price) : GroceryItem(price) {}
	double accept(iVisitor& visitor) override
	{
		return visitor.visit(this);
	}
};
#endif // !LIQUOR_H
