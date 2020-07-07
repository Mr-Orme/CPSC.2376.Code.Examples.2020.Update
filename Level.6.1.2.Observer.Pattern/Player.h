#pragma once
#include <vector>
#include <string>
class Enemy;

class Player
{
public:
	Player(std::string name);
	void update(char command);
	void attach(Enemy* enemy);
	void detach(Enemy* enemy);
	void notify();

	
	int health{ 10 };
	int strength{ 5 };
	std::string name{ "player" };
	char command{ ' ' };
	std::vector<Enemy*> enemiesToNotify;
};