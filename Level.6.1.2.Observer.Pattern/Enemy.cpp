#include <iostream>
#include "Enemy.h"
#include "Player.h"

using namespace std;

Enemy::Enemy(Player * player)
{
	cout << "an enemy draws near to " << player->name << "." << std::endl;
	player->attach(this);
	health = rand() % (int)(player->health*1.5);
	strength = rand() % (int)(player->strength*1.5);
}

void Enemy::update(Player * player)
{
	if (health > player->strength)
	{
		
		cout << "The enemy attacks (" << strength << ", " << health << ") " << player->name << endl;
		if (player->command != 'h')
			health -= player->strength;
		player->health -= strength;
	}
	else
	{
		cout << "enemy blocks!" << endl;
		if (player->command != 'h')
			health -= player->strength / 2;

	}
	if (health <= 0)
		player->detach(this);
}
