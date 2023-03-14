#include <iostream>
#include "SimpleSpaceShip.h"

int main() {

	SimpleSpaceShip sss1;
	sss1.print();

	SimpleSpaceShip sss2({ 21.5,-1.0 }, "Atlantis");
	sss2.print();
	system("PAUSE");

	return 0;
}