#include <iostream>

using namespace std;

int main() {

	int health;
	cin >> health;
	//bool isTrue = true; //ES.87
	if (health == 0)
	{
		cout << "Fatality!" << endl;
	}
	else
	{
		if (health == 1)
		{
			cout << "Finish him!" << endl;
		}
		else
		{
			cout << "Fight!" << endl;
		}
	}

	enum class Life { dead, almostDead, nearlyDead };

	switch ((Life)health) //ES.70
	{
	case Life::dead:
	{
		int x{ 6 };//curly braces needed if you are declaring a new variable.
		cout << "Fatality!" << endl;
		//break;
	}
	case Life::nearlyDead:
	case Life::almostDead:
		cout << "Finish him!" << endl;
		break; //ES.78
	default:
		cout << "Fight!" << endl;
		break;
	}

	system("PAUSE");

	return 0;

}