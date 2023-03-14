#include<iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

#include <set>
#include <map>
#include <unordered_map>

/*
 * Below is the Programming 1 approach (function overloading)
 */

int addTwoNumbers(int a, int b) {
	std::cout << "Int version:" << std::endl;
	return(a + b);
}

float addTwoNumbers(float a, float b) {
	std::cout << "Float version:" << std::endl;
	return(a + b);
}

/*
 * Below is the Programming 2 approach (function Templates)
 */
template<typename A, typename B>
A addTwoNumbers(A a, B b)
{
	std::cout << "template version:" << std::endl;
	return(a + b);
}

void main() {

	/*
	 * Lesson 1: Try doing this with both overloaded functions and templates
	 * by commenting out and uncomment the code (either overloaded or templated) above
	 */
	int x1{ 1 };
	int y1{ 2 };
	float x2{ 1.0f };
	float y2{ 2.2f };
	auto returnValue{ addTwoNumbers(x1, y2) };
	std::cout << returnValue << std::endl;

	/*
	 * Lesson 2: Play around with the location of x3 and y3 in the
	 * parameter list to show how the template enforces casting in
	 * the declarations/definitions above
	 */
	int x3{ 4 };
	double y3{ 2.7 };
	struct Position { int x; int y; };
	Position position;
	std::cout << addTwoNumbers(x3, y3) << std::endl;

	/********** STL Arrays ***********/
	std::array<int, 5> stlArray{ 1,2,3 };
	int cArray[5]{ 1,2,3,4,5 };//c-style array
	std::cout << stlArray[0] << " " << stlArray.at(1) << std::endl;
	for (auto num : stlArray)
	{
		std::cout << num << " ";
		num++;
	}
	
	std::cout << std::endl;

	/*********** STL Vector ***********/
	std::vector<int> stlVector{ 1,2,3,4,5 };
	std::cout << stlVector[0] << " " << stlVector.at(1) << std::endl;
	
	stlVector.push_back(6);
	std::cout << stlVector.back() << std::endl;

	std::cout << stlVector.size() << std::endl;
	std::cout << stlVector.capacity() << std::endl;
	stlVector.shrink_to_fit();
	std::cout << stlVector.capacity() << std::endl;
	stlVector.reserve(20);
	std::cout << stlVector.capacity() << std::endl;
	
	for (auto num : stlVector)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	stlVector.clear();

	/*********** STL Set ***********/
	std::set<char> s{ 'a', 'q' };
	std::cout << "Insert c, s, and p." << std::endl;
	s.insert('c');
	s.insert('s');
	s.insert('p');

	std::cout << "Set contents: ";
	//set<char>::iterator p;
	for (auto item : s) 
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;
	
	/*
	 *Lesson 2: sets maintain uniqueness of elements
	 */
	std::cout << "Insert c" << std::endl;
	s.insert('c');
	std::cout << "Set contents: ";
	for (auto item : s)
	{
		std::cout << item << " ";
	}

	/*********** STL Map ***********/

	//ASCII table:
	std::map<int, char> ASCII;
	for (int i{ 0 }; i < 255; i++)
	{
		//if it doesn't exist, it adds it...
		ASCII.insert({ i,(char)i });
	}

	for (int i{ 0 }; i < ASCII.size(); i++)
	{
		std::cout << i << ": " << ASCII.at(i) << std::endl;
	}

	if (auto ASCIIit{ ASCII.find(64) }; ASCIIit != ASCII.end())
	{
		std::cout << "ASCII value ";
		std::cout << (*ASCIIit).first << " is ";
		std::cout << ASCIIit->second << std::endl;
	}
}