#ifndef ACCELERATE_STRATEGY_H
#define ACCELERATE_STRATEGY_H
#include "iStratgey.h"
class Object;

class AccelerateStrategy :public iStrategy
{
	void execute(Object* object) override;
};
#endif // !LEFT_STRATEGY_H
