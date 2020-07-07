#ifndef DOWN_STRATEGY_H
#define DOWN_STRATEGY_H
#include "iStratgey.h"
class Object;

class DownStrategy :public iStrategy
{
	void execute(Object* object) override;
};
#endif // !LEFT_STRATEGY_H
