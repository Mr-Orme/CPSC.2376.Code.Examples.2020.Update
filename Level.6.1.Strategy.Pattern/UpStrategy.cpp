#include "UpStrategy.h"
#include "Object.h"
#include "Plane.h"

void UpStrategy::execute(Object * object)
{
	((Plane*)object)->z++;
}
