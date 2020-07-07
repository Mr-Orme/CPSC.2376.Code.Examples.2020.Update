#ifndef LEFT_STRATEGY_H
#define LEFT_STRATEGY_H
#include "iStratgey.h"
class Object;

class LeftStrategy :public iStrategy
{
	void execute(Object* object) override;
};
#endif // !LEFT_STRATEGY_H
