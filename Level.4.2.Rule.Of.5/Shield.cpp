#include "Shield.h"	


Shield::Shield(){}

Shield::Shield(int strength): strength(strength){}

void Shield::setStrength(int strength)
{
	this->strength = strength;
}

int Shield::getStrength() const
{
	return(strength);
}