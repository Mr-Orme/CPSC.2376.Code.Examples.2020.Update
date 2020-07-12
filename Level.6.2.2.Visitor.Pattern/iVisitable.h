#ifndef IVISITABLE_H
#define IVISITABLE_H
#include <memory>
#include "iVisitor.h";
class iVisitable
{
public:
	virtual double accept(iVisitor& visitor) = 0;
};
#endif // !IVISITABLE_H

