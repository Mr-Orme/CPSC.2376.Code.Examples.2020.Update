#ifndef CHILD1FACTORY_H
#define CHILD1FACTORY_H

#include"ObjectFactory.h"
#include"Child1.h"

class Child1Factory: public ObjectFactory{
public:
	std::unique_ptr<Object> create() {return std::make_unique<Child1>();}
};


#endif
