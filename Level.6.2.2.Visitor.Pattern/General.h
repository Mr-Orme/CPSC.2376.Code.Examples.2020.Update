#ifndef GENERAL_H
#define GENERAL_H
#include "GroceryItem.h";
class General : public GroceryItem
{
public:
	General(float price) : GroceryItem(price){}
	double accept(iVisitor& visitor) override
	{
		return visitor.visit(this);
	}
};
#endif // !GENERAL_H
