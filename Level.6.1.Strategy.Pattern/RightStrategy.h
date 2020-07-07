#ifndef RIGHT_STRATEGY_H
#define RIGHT_STRATEGY_H
#include "iStratgey.h"
class Object;

class RightStrategy :public iStrategy
{
	void execute(Object* object) override;
};
#endif // !RIGHT_STRATEGY_H
