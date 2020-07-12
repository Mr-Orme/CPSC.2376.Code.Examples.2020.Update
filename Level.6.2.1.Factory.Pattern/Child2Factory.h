#ifndef CHILD2FACTORY_H
#define CHILD2FACTORY_H

#include"ObjectFactory.h"
#include"Child2.h"

class Child2Factory: public ObjectFactory{
public:
	std::unique_ptr<Object> create() { return std::make_unique<Child2>(); }
};


#endif