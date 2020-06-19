
#include <iostream>

int main() {

	int i = 5; //i[5]
	int j = 7; //j[7]
	int* p = &i; // p --> i
	int** q; // q --> *

	q = &p; // q --> p --> i[5]
	*p = 9; // p --> i[9]
	*q = &j; // q --> p --> j[7]
	**q = 11; // q --> p --> j[11]

	std::cout << i << std::endl;
	std::cout << j << std::endl;
	std::cout << *p << std::endl;
	std::cout << **q << std::endl;

	system("PAUSE");

	return 0;
}
