/* Example based off this video: https://www.youtube.com/watch?v=GCraGHx6gso */

#include <iostream>
#include <vector>
#include <memory>

#include "Beverage.h"
#include "Espresso.h"
#include "RegularCoffee.h"
#include "DecafCoffee.h"

#include "AddOnDecorator.h"
#include "MochaDecorator.h"
#include "CaramelDecorator.h"
#include "CreamDecorator.h"
#include "SugarDecorator.h"

using namespace std;

enum class CoffeeType {Espresso=1, Regular, Decaf, NumCoffeeTypes};
enum class AddOns {Mocha=1, Caramel, Cream, Sugar, NumAddOns};

std::unique_ptr<Beverage> chooseCoffeeType();
bool addOn(std::unique_ptr<Beverage> & beverage);
bool anotherBeverage(const std::unique_ptr<Beverage>& beverage);
void finalizeOrder(const vector<std::unique_ptr<Beverage>>& order);


int main()
{
	cout << "Welcome to Mr. Orme's Coffe Cafe!!! \n"
		<< "May I take your order!\n";
	
	vector<std::unique_ptr<Beverage>> order;
	
	do
	{
		order.push_back(chooseCoffeeType());
		while (addOn(order.back())) {}

	} while (anotherBeverage(order.back()));

	finalizeOrder(order);
}

std::unique_ptr<Beverage> chooseCoffeeType()
{
	int type{ 0 };
	while (type < 1 || type >= (int)CoffeeType::NumCoffeeTypes)
	{
		cout << "What type of coffee do you want: \n"
			<< "1. Espresso \n"
			<< "2. Regular Coffee\n"
			<< "3. Decaf Coffee" << endl;

		cin >> type;
		switch ((CoffeeType)type)
		{
		case CoffeeType::Espresso:
			return std::make_unique<Espresso>();
		case CoffeeType::Regular:
			return std::make_unique<RegularCoffee>();
		case CoffeeType::Decaf:
			return std::make_unique<DecafCoffee>();
		default:
			cout << "Please choose a valid coffee!\n";
			system("PAUSE");
			system("CLS");
		}
	}
	return nullptr;
}

bool addOn(std::unique_ptr<Beverage>& beverage)
{
	cout << "Do you want to add something to your drink?(y/n)\n";
	char addAddOn;
	cin >> addAddOn;
	if (addAddOn == 'y')
	{
		int type{ 0 };
		while (type < 1 || type >= (int)AddOns::NumAddOns)
		{
			cout << "What do you want to add to your drink: \n"
				<< "1. Mocha \n"
				<< "2. Caramel\n"
				<< "3. Cream \n"
				<< "4. Sugar" << endl;

			cin >> type;
			
			switch ((AddOns)type)
			{
			case AddOns::Mocha:
				beverage = std::make_unique<MochaDecorator>(std::move(beverage));
				break;
			case AddOns::Caramel:
				beverage = std::make_unique<CaramelDecorator>(std::move(beverage));
				break;
			case AddOns::Cream:
				beverage = std::make_unique<CreamDecorator>(std::move(beverage));
				break;
			case AddOns::Sugar:
				beverage = std::make_unique<SugarDecorator>(std::move(beverage));
				break;
			default:
				cout << "Please choose a valid coffee!\n";
				system("PAUSE");
				system("CLS");
			}
			
		}
		return true;
	}
	return false;
}

bool anotherBeverage(const std::unique_ptr<Beverage>& beverage)
{
	cout << "Drink added to order, cost: $" << beverage->cost() << endl;
	cout << "Do you want to add another drink to your order (y/n): ";
	char anotherDrink{ 'n' };
	cin >> anotherDrink;
	if (anotherDrink == 'y') return true;
	else return false;

}

void finalizeOrder(const vector<std::unique_ptr<Beverage>>& order)
{
	cout << "Your cost is:  $";
	float orderTotal{ 0.0f };
	for (const auto& drink : order)
	{
		orderTotal += drink->cost();
	}

	cout << orderTotal << endl;
	system("PAUSE");
}
