/*
* File: Polymorphism.cpp
* Author: Keith Bush (2013)
*
* Purpose: understanding virtual methods, polymorphism, and
*          dynamic binding
*/
#include<iostream>
#include <vector>
#include <memory>
#include "Object.h"
#include "Plane.h"
#include "Car.h"

using namespace std;
void doCommand(Object* v);

int main() {

	int numSteps = 10;
   	
	std::unique_ptr<Object> v = std::make_unique<Plane>();

	/*Lesson 2: invoking methods has the desired polymorphic behavior
	* because of virtual keyword (see Object.h).
	*/

	/*invokes plane's toString() method*/
	cout << v->toString() << endl;

	for (int i = 0; i<numSteps; i++) {


		doCommand(v.get());

		char command;
		cout << "Input a command: ";
		cin >> command;

		/*invoke's plane's changePosition() method*/
		v->changePosition(command);

		cout << v->toString() << endl;


	}

	return 0;

}
void doCommand(Object* v)
{
	char command;
	cout << "Input a command: ";
	cin >> command;

	/*invoke's plane's changePosition() method*/
	v->changePosition(command);

	cout << v->toString() << endl;
}
