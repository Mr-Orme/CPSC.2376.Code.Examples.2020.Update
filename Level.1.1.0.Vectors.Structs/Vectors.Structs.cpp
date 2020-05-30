#include<iostream>
#include <vector>

struct Position
{
	int x;
	int y;
};
int main()
{

	std::vector<Position> coordinates{ {0,0}, {1,1}, {2,2} };
	std::cout << coordinates.size() << std::endl;

	coordinates.push_back({ 3,3 });
	std::cout << coordinates.back().x << ", " << coordinates.back().y << std::endl;

	Position player{ 4,4 };//this way is not prefered because of the creation of a temporary variable.
	coordinates.push_back(player);
	player.x = 3;
}