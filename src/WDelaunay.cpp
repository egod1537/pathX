#include "WDelaunay.h"

#include "UserComponents.h"

WDelaunay::WDelaunay(std::string _name) 
	: ImWindow(_name) {
	AddComponent<CDelaunayDrawer>();
}