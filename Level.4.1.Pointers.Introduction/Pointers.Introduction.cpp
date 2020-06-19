
#include <iostream>

int main() {

	int i{ 5 };//i[5] @ memory address 128adb83

	int* p{ nullptr }; //p -->
	int* t{ &i };
	p = &i;// p --> i

	std::cout << &i << std::endl; //memory address of i
	std::cout << p << std::endl; // address stored in p same as MA stored in i;
	std::cout << i << std::endl; // value of i
	std::cout << *p << std::endl; // dereferences p and get's us the value stored in i;
	 //p --> i
	//*p --> i[5]

	system("PAUSE");

	return 0;
}