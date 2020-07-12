#ifndef GAMELIBRARY_H
#define GAMELIBRARY_H

#include<string>
#include<map>
#include<memory>

class ObjectFactory;
class GameLibrary{

public:
	std::map<std::string,std::unique_ptr<ObjectFactory>> inventory;
};

#endif