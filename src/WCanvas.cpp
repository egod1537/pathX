#include "WCanvas.h"

#include "UserComponents.h"

WCanvas::WCanvas(std::string _name) 
	: ImWindow(_name){
	
	AddComponent<CTestCanvas>();
}