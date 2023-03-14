/*
 * File: demoOverloadedOperators.cpp
 * Author: Keith Bush (2013)
 *
 * Purpose: demonstration of operator overloading for a user-defined class
 */
#include <iostream>
#include <string>

#include "SimpleSpaceShip.h"

int main() {


	SimpleSpaceShip sss1({ 0.0f,1.0f }, 10, 5, "SS1");
	SimpleSpaceShip sss2({ 10.0f,2.0f }, 8, 9, "SSS2");
	SimpleSpaceShip sss3({ 1.4f,-0.5f }, 20, 14, "SSS3");

	//Calling Output Stream Operator
	std::cout << sss1 << ", " << sss2 << std::endl;
	std::cout << sss3 << std::endl;

	//Calling stream insertion operator with addition operator
	std::cout << sss1 + sss2 << std::endl;

	//binary addition operator
	sss1 += sss2;

	////Calling stream insertion, addition operators with copy constructor
	SimpleSpaceShip sss4(sss1 + (sss2 + sss3));

	////Checking results
	std::cout << sss4 << std::endl;

	//calling increment
	++sss4;
	std::cout << sss4 << std::endl;

	//comparison
	if (sss3 != sss4)
	{
		std::cout << "Shoot 'em down!!!" << std::endl;
	}
	system("PAUSE");
}



