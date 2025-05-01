#include "ImWindow.h"

ImWindow::ImWindow(std::string _name) 
	: name(std::move(_name)) {

}

void ImWindow::Update() {
	for (auto& component : components) {
		component->Update();
	}
}