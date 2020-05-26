/*
* File: RandomWithIncludeMemory.cpp
* Author: Sean Orme (2016)
*/

#include <iostream>
#include <random>

using namespace std;

int main() {
	/*
		1. Seed
		2. Engine
		3. Distribution
	*/
	const int maxValue{ 50 };

	random_device seed;
	unsigned int tempSeed{ seed() };

	default_random_engine e(seed());
	default_random_engine e2(13);

	uniform_int_distribution<int> ud(0, maxValue - 1);
	normal_distribution<double> nd(25.0, 5.0); //(mean, standard deviation)
	bernoulli_distribution bd(.75);
	
	int distribution[maxValue] = { 0 };
	cout << ud(e);//<-- This does the actual generation!
	for (int i = 0; i < 10000; i++)
	{
		//distribution[ud(e)]++;
		distribution[(int)nd(e)]++;
		//distribution[(int)bd(e)]++;

	}

	for (int i = 0; i < maxValue; i++)
	{
		cout << i << ": " << distribution[i] << endl;;
	}
	cout << endl;
	system("PAUSE");

	return 0;

}