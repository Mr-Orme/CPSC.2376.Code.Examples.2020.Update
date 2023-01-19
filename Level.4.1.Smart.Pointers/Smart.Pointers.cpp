#include <iostream>
#include <memory>
#include <vector>

#include "SimpleSpaceShip.h"
void print(std::unique_ptr<SimpleSpaceShip>& SSS)
{
	SSS->print();
	std::cout << std::endl;
}

void print(std::shared_ptr<SimpleSpaceShip> SSS)
{
	SSS->print();
	std::cout << std::endl;
}

void print(SimpleSpaceShip* SSS)
{
	SSS->print();
	std::cout << std::endl;
}

std::unique_ptr<SimpleSpaceShip> makeShip()
{
	auto temp { std::make_unique<SimpleSpaceShip>() };
	return temp;
}

int main()
{
	std::shared_ptr<SimpleSpaceShip> SSS{ std::make_shared<SimpleSpaceShip>() };

	print(SSS);
	{
		std::shared_ptr<SimpleSpaceShip> SSS1{ SSS };
		print(SSS1);
	}
	std::vector<std::shared_ptr<SimpleSpaceShip> > fleet;
	for (int i{ 0 }; i < 10; i++)
	{
		fleet.push_back(std::make_shared<SimpleSpaceShip>());
	}

	std::weak_ptr<SimpleSpaceShip> lastShip{ fleet.back() };
	std::shared_ptr<SimpleSpaceShip> firstShip{ fleet.front() };
	fleet.clear(); //weak keps nothing alive! front ship still alive!

	std::unique_ptr<SimpleSpaceShip> SSSu{ std::make_unique<SimpleSpaceShip>() };
	
	//std::unique_ptr<SimpleSpaceShip> SSSu2{ SSSu }; //can't have two things pointing at it!
	std::unique_ptr<SimpleSpaceShip> SSSu2{ std::move(SSSu)};

	print(SSSu2);//pass by reference
	print(SSSu2.get()); //pass raw pointer.

	std::vector<std::unique_ptr<SimpleSpaceShip> > uniqueFleet;
	for (int i{ 0 }; i < 10; i++)
	{
		uniqueFleet.push_back(makeShip());
	}
	//uniqueFleet.push_back(SSSu2);
	uniqueFleet.push_back(std::move(SSSu2));
}