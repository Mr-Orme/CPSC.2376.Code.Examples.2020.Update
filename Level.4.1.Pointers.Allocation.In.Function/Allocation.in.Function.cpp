/*
 * File: allocateinfunction.cpp
 * Author: Keith Bush (2013)
 */

#include <iostream>

using namespace std;

/*Pass by value based allocation - doesn't work*/
// float * ma = myArray
void allocateInFunction(float* ma, int n) {

	float value;
	ma = new float[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter the next float: ";
		cin >> value;
		ma[i] = value;
	}

}

/*Pass by reference to a pointer based allocation*/
//float* & ma = myArray;
void allocateInFunctionRef(float*& ma, int n) {

	float value;
	ma = new float[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter the next float: ";
		cin >> value;
		ma[i] = value;
	}


}

/*Pass by value to a pointer to a pointer based allocation*/
//float ** ma = &myArray
void allocateInFunctionPtr(float** ma, int n) {
	//ma --> myArray --> NULL
	float value;
	*ma = new float[n];
	//ma --> myArray --> [][][][][][][][]
	for (int i = 0; i < n; i++) {
		cout << "Enter the next float: ";
		cin >> value;
		(*ma)[i] = value;
	}


}


int main() {

	float* myarray = nullptr;
	int size;
	cout << "Enter an array size: ";
	cin >> size;

	//allocateInFunction(myarray, size);
	//allocateInFunctionRef(myarray, size);
	allocateInFunctionPtr(&myarray, size);


	for (int i = 0; i < size; i++) {
		cout << myarray[i] << " ";
	}cout << endl;

	system("PAUSE");

	return 0;
}