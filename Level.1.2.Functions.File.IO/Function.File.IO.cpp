
#include <iostream>
#include <tuple>
#include <string>
#include <fstream>
using namespace std;
class SomeLargeClass
{
	int x;
	//lot's of other data!
};
struct Answers {
	int sum;
	int product;
};

void addMultiplyTwoNumbers(int num1, int  num2, int& Psum, int& prod);
//prefer struct for multiple out values
Answers addMultiplyTwoNumbers(int num1, int num2);//this is an overload!
//sum, product
tuple<int, int> addMultiplyTwoNumberTuple(int num1, int num2);//return type difference does not make an overload...
tuple<int, int> loadTwoNumbers(const std::string& fileName);
void saveTwoNumbers(int num1, int num2, const std::string& fileName);
//const reference for large data types!
void foo(const SomeLargeClass& classInstance)
{

}

int main() {

	
	std::string fileName{ "numbers.txt" }; //best to set the file name in a string variable to prevent misspellings.

	//structured bindings make tuples fun and easy!
	auto [n1, n2] = loadTwoNumbers(fileName);

	int sum{ 0 };
	int product{ 0 };
	//Bad because the function doe not need the values stored in sum/product.
	addMultiplyTwoNumbers(n1, n2, sum, product);
	cout << sum << " " << product << endl;

	//just to modify the number.
	n1 += sum;
	n2 -= product;

	//struct is better. We can still use structured bindings...
	Answers answer{ addMultiplyTwoNumbers(n1, n2) };
	auto [ssum, sproduct] = addMultiplyTwoNumbers(n1, n2);
	cout << ssum << " " << sproduct << endl;
	cout << answer.sum << " " << answer.product << endl;

	auto [tsum, tproduct] = addMultiplyTwoNumberTuple(n1, n2);
	cout << tsum << " " << tproduct << endl;
	system("PAUSE");

	saveTwoNumbers(n1, n2, fileName);
	return 0;
}

void addMultiplyTwoNumbers(int num1, int  num2, int& Psum, int& prod) {
	Psum = num1 + num2;
	prod = num1 * num2;
	num1 = 99;
	num2 = 100;

}

Answers addMultiplyTwoNumbers(int num1, int num2)
{
	return { num1 + num2, num1 * num2 };
}

tuple<int, int> addMultiplyTwoNumberTuple(int num1, int num2)
{
	return { num1 + num2, num1 * num2 };
}

tuple<int, int> loadTwoNumbers(const std::string& fileName)
{
	std::ifstream fin;
	fin.open(fileName);
	int num1{ 0 };
	int num2{ 0 };
	if (fin.is_open())
	{
		fin >> num1 >> num2;
	}
	fin.close();
	return { num1, num2 };
	
}

void saveTwoNumbers(int num1, int num2, const std::string& fileName)
{
	std::ofstream fout;
	fout.open(fileName);
	fout << num1 << std::endl << num2;
	fout.close();

	std::fstream fio;
	fio.open(fileName, ios::app);
}
