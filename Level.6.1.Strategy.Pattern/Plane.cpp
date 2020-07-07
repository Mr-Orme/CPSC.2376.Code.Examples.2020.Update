#include <iostream>
#include <sstream>
#include "Plane.h"
#include "UpStrategy.h"
#include "DownStrategy.h"

using namespace std;

Plane::Plane() { /*Default Constructor of Object is called*/
	setPosition({ 2.0f, 2.1f });
	setName("Plane");
	z = 2.2f;
	behaviors['u'] = std::make_unique<UpStrategy>();
	behaviors['d'] = std::make_unique<DownStrategy>();
}

Plane::~Plane() {
}

string Plane::toString() {

	stringstream result;

	result << "(Plane Object, " << Object::toString() << ", z=" << z << ")";

	return(result.str());
}

//void Plane::changePosition(char command) {
//
//	switch (command) {
//	case 'u':
//		z++;
//		break;
//	case 'd':
//		z--;
//		break;
//	default:
//		Object::changePosition(command); //Handles other commands AND ignores garbage
//		break;
//	}
//
//}
