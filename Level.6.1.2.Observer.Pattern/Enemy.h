#pragma once
class Player;
class Enemy
{
public:
	Enemy(Player* player);
	void update(Player* player);
	int health{ 0 };
	int strength{ 0 };
};

