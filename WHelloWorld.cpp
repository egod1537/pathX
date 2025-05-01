#include "WHelloWorld.h"

#include "UserComponents.h"

WHelloWorld::WHelloWorld(std::string _name)
	: ImWindow(_name) {
	AddComponent<CHelloWorldText>();
}