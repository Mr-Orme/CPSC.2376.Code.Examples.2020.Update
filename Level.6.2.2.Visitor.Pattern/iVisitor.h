#ifndef IVISITOR_H
#define IVISITOR_H
#include <memory>
class Liquor;
class Tobacco;
class Necessity;
class General;
class iVisitor
{
public:
	virtual double visit(Liquor* liqourItem) = 0;
	virtual double visit(Tobacco* tobaccoItem) = 0;
	virtual double visit(Necessity* necessityItem) = 0;
	virtual double visit(General* generalItem) = 0;
};

#endif // !IVISITOR_H