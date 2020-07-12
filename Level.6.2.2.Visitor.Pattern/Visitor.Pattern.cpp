#include <memory>
#include <iomanip>
#include "iVisitable.h"
#include "TaxVisitor.h"
#include "TaxHolidayVisitor.h"

#include "General.h"
#include "Liquor.h"
#include "Necessity.h"
#include "Tobacco.h"

int main()
{
	TaxVisitor calculateTax;

	General bubbleGum(1.23);
	Liquor vodka(14.99);
	Tobacco cigars(19.99);
	Necessity bread(1.99);

	std::cout << "********** Standard Tax ****************" << std::endl;
	std::cout << std::setprecision(2) << std::fixed << bubbleGum.accept(calculateTax) << std::endl;
	std::cout << std::setprecision(2) << std::fixed << vodka.accept(calculateTax) << std::endl;
	std::cout << std::setprecision(2) << std::fixed << cigars.accept(calculateTax) << std::endl;
	std::cout << std::setprecision(2) << std::fixed << bread.accept(calculateTax) << std::endl;
	
	TaxHolidayVisitor calcHoldiayTax;
	std::cout << std::endl << "********** TAX HOLIDAY ****************" << std::endl;
	std::cout << std::setprecision(2) << std::fixed << bubbleGum.accept(calcHoldiayTax) << std::endl;
	std::cout << std::setprecision(2) << std::fixed << vodka.accept(calcHoldiayTax) << std::endl;
	std::cout << std::setprecision(2) << std::fixed << cigars.accept(calcHoldiayTax) << std::endl;
	std::cout << std::setprecision(2) << std::fixed << bread.accept(calcHoldiayTax) << std::endl;
	system("PAUSE");
}