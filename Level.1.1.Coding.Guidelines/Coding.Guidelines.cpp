#include <iostream>

int main()
{
	const int multiplier{ 2 }; //ES.9, ES.45

	int x{ 3 };//ES.23
	{//ES.5
		int y{ 0 };//ES.20
		//int x{0}; BAD!!! ES.12
		std::cin >> y;
		auto z{ y * multiplier };//ES.21, ES.11
		x += z;
	}

	std::cout << x;
	//std::cout << z;
}