#include "WDelaunayTestbed.h"

#include "UserComponents.h"

WDelaunayTestbed::WDelaunayTestbed(std::string _name)
	: ImWindow(_name)
{
	AddComponent<CDelaunayCanvas>();
}