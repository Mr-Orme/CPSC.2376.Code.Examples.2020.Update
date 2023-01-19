
#include<iostream>
#include <vector>
#include "Vehicle.h"
#include "Plane.h"
#include "Truck.h"

using namespace std;
void doCommand(Vehicle& v);

int main() {

	int numSteps{ 10 };


	/*Lesson 1: reference to parents can refer to children*/
	Plane p{ Plane() };
	Vehicle& v{ p };
	Vehicle v2;
	/*Lesson 2: invoking methods has the desired polymorphic behavior
	* because of virtual keyword (see Vehicle.h).
	*/

	/*invokes plane's toString() method*/
	cout << v.toString() << endl;

	for (int i = 0; i < numSteps; i++) {


		doCommand(p);

		/*char command;
		cout << "Input a command: ";
		cin >> command;*/

		/*invoke's plane's changePosition() method*/
		//v.changePosition(command);

		cout << v.toString() << endl;


	}

	return 0;

}
void doCommand(Vehicle& v)
{
	char command;
	cout << "Input a command: ";
	cin >> command;

	/*invoke's plane's changePosition() method*/
	v.changePosition(command);

	cout << v.toString() << endl;
}
