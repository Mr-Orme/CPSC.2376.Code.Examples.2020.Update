#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "Enemy.h"

using namespace std;
Player::Player(std::string name): name(name){}

void Player::update(char command)
{
	this->command = command;
	switch (command)
	{
	case 'h':
		health += strength;
	}
	health-=2;
	notify();
	if (enemiesToNotify.size() == 0)
	{
		cout << "All enemies defeated for " << name << "!!!!!" << endl;
	}
}

void Player::attach(Enemy * enemy)
{
	enemiesToNotify.push_back(enemy);
}

void Player::detach(Enemy * enemy)
{
	auto toDelete{ std::find(enemiesToNotify.begin(), enemiesToNotify.end(), enemy) };
	if (toDelete != enemiesToNotify.end()) enemiesToNotify.erase(toDelete);
}

void Player::notify()
{
	for (auto enemies : enemiesToNotify)
	{
		enemies->update(this);
	}
}
