
#ifndef SHIELD_H
#define SHIELD_H

class Shield{

public:
	Shield();				//default constructor
	Shield(int strength);            //conversion constructor
	void setStrength(int strength);
	int getStrength() const;

private: 
	int strength{ 0 };

};

#endif