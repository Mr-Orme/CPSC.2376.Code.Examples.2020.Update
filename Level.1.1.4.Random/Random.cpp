/*
* File: RandomWithIncludeMemory.cpp
* Author: Sean Orme (2016)
*/
#include <vector>
#include <iostream>
#include <random>
#include <array>

int main() {
	/*
		1. Seed
		2. Engine
		3. Distribution
	*/
	const int maxValue{ 50 };
	
	std::random_device seed;
	auto tempSeed{ seed() };
	std::default_random_engine e(tempSeed);
	std::default_random_engine e2(13);

	std::uniform_int_distribution ud(0, maxValue - 1);
	std::normal_distribution nd(30.0, 2.0); //(mean, standard deviation)
	std::bernoulli_distribution bd(.75);
	
	std::array<int, maxValue> distribution{ 0 };
	std::cout << ud(e) << std::endl;//<-- This does the actual generation!
	for (int i = 0; i < 10000; i++)
	{
		//distribution.at(ud(e))++;
		//distribution[(int)nd(e)]++;
		distribution[(int)bd(e)]++;

	}

	for (int i = 0; i < maxValue; i++)
	{
		std::cout << i << ": " << distribution.at(i) << std::endl;;
	}
	std::cout << std::endl;
	system("PAUSE");

	return 0;

}