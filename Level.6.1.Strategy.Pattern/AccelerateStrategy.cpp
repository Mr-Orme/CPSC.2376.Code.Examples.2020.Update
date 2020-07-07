#include "AccelerateStrategy.h"
#include "Object.h"

void AccelerateStrategy::execute(Object * object)
{
	object->position.x++;
}
