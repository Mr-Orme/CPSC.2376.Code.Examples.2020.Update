#include "LeftStrategy.h"
#include "Object.h"

void LeftStrategy::execute(Object * object)
{
	object->position.y--;
}
