#ifndef NECESSITY_H
#define NECESSITY_H
#include "GroceryItem.h";
class Necessity : public GroceryItem
{
public:
	Necessity(float price) : GroceryItem(price) {}
	double accept(iVisitor& visitor) override
	{
		return visitor.visit(this);
	}
};
#endif // !NECESSITY_H
