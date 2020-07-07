#include "DownStrategy.h"
#include "Object.h"
#include "Plane.h"
void DownStrategy::execute(Object * object)
{
	((Plane*)object)->z--;
}
