#ifndef TOBACCO_H
#define TOBACCO_H
#include "GroceryItem.h";
class Tobacco : public GroceryItem
{
public:
	Tobacco(float price) : GroceryItem(price) {}
	double accept(iVisitor& visitor) override
	{
		return visitor.visit(this);
	}
};
#endif // !TOBACCO_H
