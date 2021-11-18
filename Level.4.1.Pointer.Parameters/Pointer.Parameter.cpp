#include <iostream>
using namespace std;

void swap_by_value(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void swap_by_reference(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//int* a = &x;
//int* b = &y;
void swap_by_pointer(int* a, int* b) {
	//a --> x
	//b --> y
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {

	int x = 5, y = 7;
	cout << "Before: " << x << " " << y << endl;
	swap_by_value(x, y);
	cout << "After value swap:  " << x << " " << y << endl;
	swap_by_reference(x, y);
	cout << "After reference swap:  " << x << " " << y << endl;
	swap_by_pointer(&x, &y);
	cout << "After pointer swap:  " << x << " " << y << endl;
	//swap_by_pointer(3, 6);
	system("PAUSE");

	return 0;
}
