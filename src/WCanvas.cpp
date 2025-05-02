#include "WCanvas.h"

#include "UserComponents.h"

#include <iostream>
#include <vector>
#include <CDT.h>

WCanvas::WCanvas(std::string _name) 
	: ImWindow(_name){
	AddComponent<CTestCanvas>();
}