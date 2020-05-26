#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	{// basic for loop
		int numTimes{ 0 };
		cin >> numTimes;
		/*   Initializer; Conditional  ; What happens after each loop*/
		for (int i{ 0 }/*ES.74*/; i <= numTimes; i++)
		{

			cout << i << endl;
			//i++; //ES.86
		}

		cout << endl;
	}

	{//Range based for loops
		vector<int> v{ 1,2,3,4,5,6 };
		//basic for loop, not best practice for STL containers.
		for (int i{ 0 }; i < v.size(); i++)
		{
			cout << v[i] << endl;
		}

		//range based for loop
		for (auto myInt : v)
		{
			myInt++;//doesn't not change v!
			cout << myInt << endl;
		}
		for (int myInt : v)//auto is not necessary if the type is easy, but if you change v's type, auto is nice.
		{
			myInt++;//doesn't not change v!
			cout << myInt << endl;
		}

		for (auto& myInt : v)
		{
			myInt++; //modify's v!
			cout << myInt << endl;
		}

		for (const auto& myInt : v)
		{
			//myInt++; //const, so can't modify the value! Shows intention!
			cout << myInt << endl;
		}
	}
	
	{//iterator for loop
		std::vector<int> v{ 1, 2, 3, 4 ,5 ,6 };
		for (auto vIter{ v.begin() }; vIter != v.end(); )
		{
			if (*vIter % 2 != 0)
			{
				vIter = v.erase(vIter);
			}
			else vIter++;
		}
	}
	system("PAUSE");
}