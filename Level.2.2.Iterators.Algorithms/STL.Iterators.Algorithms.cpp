#include<iostream>

#include <algorithm>
#include <vector>
#include <list>


struct Vector2D//mathematical vector, not STL vector!
{
	int x{ 0 };
	int y{ 0 };
};
int fooFunction(int num1, int num2)
{
	return num1 * num2;
}
int main()
{
	/*** Iterators***/
	std::vector<int> v{ 1,2,3,4,5 };

	std::vector<int>::iterator vIter; //<-- ugly syntax for iterators.
	auto vIter2{ v.begin() }; //<-- by initializing with the first item 
							//in the vector, we can use auto. MUCH nicer!

	//std::cout << vIter2; //<--can't just "cout" iterators. They are like pointers....
	std::cout << *vIter2; //must dereference with the '*' operator (dereferencing operator).

	*vIter2 = 2; //can use to modify the container at the spot where the iterator is pointing!

	std::vector<Vector2D> points{ {0,0}, {1,1}, {2,2} };
	auto thisPoint{ points.begin() };
	//std::cout << *thisPoint.y; //Note, that the '.' operator has precedence over the * operator, so this won't work.
	std::cout << (*thisPoint).y << std::endl; //paranthesis enure * is done first.
	std::cout << thisPoint->y << std::endl; //arrow is easier!
	thisPoint++; //<-- can increment and decrement iterators!
	thisPoint += 2;
	Vector2D myPoint;
	/*** Lambdas vs function ****/
	auto fooLambda{ [&](int num1, int num2)  //Note:: -> returnType is optional
	{
			myPoint.x = 2;
			thisPoint;
			//think of capture [&] as automatic parameters.
			points.begin()->x = 3;//we have captured by reference and so can modify this!!!
			return num1 * num2;
			//return { num1, num2 };
		} };
	myPoint.x++;
	std::cout << fooFunction(2, 3) << std::endl;
	std::cout << fooLambda(2, 3) << std::endl;

	/*** Algorithms ***/ //Here is a list: http://www.cplusplus.com/reference/algorithm/
	int x{ 4 };
	for (auto& i : v)
	{
		i += x;
	}
	std::for_each(v.begin()+2, v.end()-1, [=](int& i) 
		{
			i+=x; 
		}); //do something to each element.
	
	std::sort(v.begin(), v.end()); //sort
	std::reverse(v.begin(), v.end());
	if (std::is_sorted(v.begin(), v.end()))
	{
		std::cout << "sorted" << std::endl;
	}
	
	auto [smallest, largest] = std::minmax_element(v.begin(), v.end());

	std::cout << *smallest << ", " << *largest << std::endl;
	v.push_back(-1);
	v.push_back(19);
	smallest = std::min_element(v.begin(), v.end());
	largest = std::max_element(v.begin(), v.end());

	/** Must overload < operator for user-defined types. **/
	if (std::all_of(v.begin(), v.end(), [](int i) {return i < 20; }))//check if something is true for every element.
	{
		std::cout << "everything's under 20" << std::endl;
	}
	if (std::none_of(v.begin(), v.end(), [](int i) {return i < -1; }))//check if something is false for every element
	{
		std::cout << "nothing's under 20" << std::endl;
	}

	/** must overload == operator for user-defined types. **/
	std::cout << std::count(v.begin(), v.end(), 6) << std::endl; //count the number of times
	if (auto result{ find(v.begin(), v.end(), 12) }; result != v.end()) //returns first one that matches.
	{
		std::cout << "Found it" << std::endl;
	}
	Vector2D comparePoint{ 2,3 };//please note, it is better to overload the == operator and just use find....
	if (auto result
		{ 
		find_if(points.begin(), points.end(), 
			[&](Vector2D point)//finds, but not just ==
			{
				return point.x == comparePoint.x && point.y == comparePoint.y;
			}
	) }; result != points.end())
	{
		std::cout << "found a matching point!" << std::endl;
	}
	//can store lambdas in a variable for reusue or clarity...
	auto inFirstQuadrant{ [](Vector2D point) {return point.x > 0 && point.y > 0; } };
	auto found{ std::find_if_not(points.begin(), points.end(), inFirstQuadrant) };
	

	//NOTE:: the + operator only works on iterators for sequential containers!!
	std::fill(v.begin(), v.begin() + 2, -6);//fills the first 2 item's with a -6
	
	//NOTE:: remove & remove_if, moves data to overwrite matching values.
	//and returns an iterator to the first one that was "removed"
	//This saves a lot of deleting in the middle on containers where such deleting is expensive...
	//deleting off the end is always cheap.
	v.erase(
		std::remove(v.begin(), v.end(), -6)
		, v.end()); //removes matching values...
	v.erase(std::remove_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; }), v.end());//choose your own comparison!

	std::reverse(v.begin(), v.end()); //reverses the order
	
	for (auto& item : v)
	{
		item++;
	}
}