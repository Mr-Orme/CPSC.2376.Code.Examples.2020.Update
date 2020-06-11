/*
 * File: demoOverloadedOperators.cpp
 * Author: Keith Bush (2013)
 *
 * Purpose: demonstration of operator overloading for a user-defined class
 */
#include <iostream>
#include <string>

#include "SimpleSpaceShip.h"

using namespace std;

void main() {


	SimpleSpaceShip sss1({ 0.0f,1.0f }, 10, 5, "SS1");
	SimpleSpaceShip sss2({ 10.0f,2.0f }, 8, 9, "SSS2");
	SimpleSpaceShip sss3({ 1.4f,-0.5f }, 20, 14, "SSS3");

	//Calling Output Stream Operator
	cout << sss1 << ", " << sss2 << endl;
	cout << sss3 << endl;

	//Calling stream insertion operator with addition operator
	cout << sss1 + sss2 << endl;

	//binary addition operator
	sss1 += sss2;

	////Calling stream insertion, addition operators with copy constructor
	SimpleSpaceShip sss4(sss1 + (sss2 + sss3));

	////Checking results
	cout << sss4 << endl;

	//calling increment
	++sss4;
	cout << sss4 << endl;

	//comparison
	if (sss3 != sss4)
	{
		cout << "Shoot 'em down!!!" << endl;
	}
	system("PAUSE");
}



