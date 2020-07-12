#ifndef GROCERYITEM_H
#define GROCERYITEM_H
#include "iVisitable.h"
class GroceryItem: public iVisitable
{
public:
	GroceryItem(float price): price(price){	}
	float getPrice() const
	{
		return price;
	}
protected:
	float price{ 0.0f };
};
#endif // !GROCERYITEM_H

