#ifndef CHILD3FACTORY_H
#define CHILD3FACTORY_H

#include"ObjectFactory.h"
#include"Child3.h"

class Child3Factory : public ObjectFactory{
public:
	std::unique_ptr<Object> create() { return std::make_unique<Child3>(); }
};


#endif