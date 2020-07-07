#include "DecelerateStrategy.h"
#include "Object.h"
void DecelerateStrategy::execute(Object * object)
{
	object->position.x--;
}
