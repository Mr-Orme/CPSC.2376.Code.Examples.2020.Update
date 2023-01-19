#ifndef BASEGAMELIBRARY_H
#define BASEGAMELIBRARY_H
#include <memory>
#include"GameLibrary.h"
#include"Child1Factory.h"
#include"Child2Factory.h"

class BaseGameLibrary : public GameLibrary{

public:
	BaseGameLibrary(){
		inventory["child1"] = std::make_unique<Child1Factory>();
		inventory["child2"] = std::make_unique<Child2Factory>();
	}
};

#endif