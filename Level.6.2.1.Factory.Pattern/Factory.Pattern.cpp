#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <random>

#include"GameLibrary.h"
#include"BaseGameLibrary.h"
#include"ModGameLibrary.h"

int main(){

	//Factory types
	std::unique_ptr<GameLibrary> baseLibrary{ std::make_unique<BaseGameLibrary>() }; //storeas an inventory of base ObjectFactories
	std::unique_ptr<GameLibrary> modLibrary{ std::make_unique<ModGameLibrary>() };  //stores inventory of modifed ObjectFactories (if they exist)

	//Display utility of the object factory
	std::vector<std::unique_ptr<Object>> objects;
	
	std::random_device seed;
	std::default_random_engine engine(seed());
	std::uniform_int_distribution chooseType(1, 3);
	const int N{ 10 };
	for(int i=0;i<N;i++){
		//Imagine that the game is dynamically calling for types
		std::string objectType;
		/*Randomly demand one of three types of object*/
		switch(chooseType(engine)){
		case 1:
			objectType = "child1";
			break;
		case 2:
			objectType = "child2";
			break;
		case 3:
			objectType = "child3";
			break;
		}

		std::cout << "TYPE: " << objectType << std::endl;
		
		//Search through the mod classes
		if (auto found{ modLibrary->inventory.find(objectType) }; found != modLibrary->inventory.end()) {
			objects.push_back(found->second->create());
		}
		//Search through the base classes
		else if (auto found{ baseLibrary->inventory.find(objectType) }; found != baseLibrary->inventory.end()) {
			objects.push_back(found->second->create());
		}
	}

	//Display the game space
	for(auto& object : objects){
		cout << object->getNumber()  << endl;
	}

	system("PAUSE");

	return 0;
}
