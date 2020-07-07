#ifndef DECELERATE_STRATEGY_H
#define DECELERATE_STRATEGY_H
#include "iStratgey.h"
class Object;

class DecelerateStrategy :public iStrategy
{
	void execute(Object* object) override;
};
#endif // !LEFT_STRATEGY_H
