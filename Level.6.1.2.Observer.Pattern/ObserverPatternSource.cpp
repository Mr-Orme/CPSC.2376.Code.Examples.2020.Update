#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include "Enemy.h"
#include "Player.h"

using namespace std;

int main()
{
	vector<std::unique_ptr<Player>> players;
	players.push_back(std::make_unique<Player>("player 1"));
	players.push_back(std::make_unique<Player>("player 2"));

	Enemy e1(players[0].get());
	Enemy e2(players[0].get());

	Enemy e3(players[1].get());
	while (!players.empty())
	{
		for (auto& player : players)
		{
			cout << player->name << ": (" << player->strength << ", " << player->health << ")\n";
			cout << "(a)ttack or (h)eal";
			char command;
			cin >> command;
			player->update(command);
		}
		players.erase((std::remove_if(players.begin(), players.end(), [](std::unique_ptr<Player>& player)
			{
				return player->enemiesToNotify.empty() && player->health <= 0;
			})), players.end());
	}
}