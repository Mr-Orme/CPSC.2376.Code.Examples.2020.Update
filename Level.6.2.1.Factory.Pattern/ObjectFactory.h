#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

class Object;
class ObjectFactory{
public:
	virtual std::unique_ptr<Object> create() = 0;
};

#endif