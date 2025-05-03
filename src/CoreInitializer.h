#pragma once

#include "Core.h"
#include "ImWindow.h"
#include "Component.h"

#include "User.h"

std::unique_ptr<ImWindow> CreateHelloWorldWindow() {
	auto window = std::make_unique<WHelloWorld>("Hello World");
	return window;
}

std::unique_ptr<ImWindow> CreateCanvasWindow() {
	auto window = std::make_unique<WCanvas>("Canvas");
	return window;
}

std::unique_ptr<ImWindow> CreateDelaunayTestbedWindow() {
	auto window = std::make_unique<WDelaunayTestbed>("Delaunay Testbed");
	return window;
}

void CoreInitialize(Core* core) {
	core->AddWindow(CreateHelloWorldWindow());
	core->AddWindow(CreateCanvasWindow());
	core->AddWindow(CreateDelaunayTestbedWindow());
}

