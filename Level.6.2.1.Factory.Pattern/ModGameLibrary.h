#ifndef MODGAMELIBRARY_H
#define MODGAMELIBRARY_H

#include"Child3Factory.h"

//Declare GameLibrary as a valid type
#include "GameLibrary.h"

class ModGameLibrary : public GameLibrary{

public:

	ModGameLibrary(){
		inventory["child3"] = std::make_unique<Child3Factory>();
	}
};

#endif