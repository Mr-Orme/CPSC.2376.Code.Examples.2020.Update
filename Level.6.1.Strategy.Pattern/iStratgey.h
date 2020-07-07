#ifndef I_STRATEGY_H
#define I_STRATEGY_H

class Object;
class iStrategy
{
public:
	virtual void execute(Object* object) = 0;
};
#endif // !I_STRATEGY_H
