#ifndef UP_STRATEGY_H
#define UP_STRATEGY_H
#include "iStratgey.h"
class Object;

class UpStrategy :public iStrategy
{
	void execute(Object* object) override;
};
#endif // !LEFT_STRATEGY_H
