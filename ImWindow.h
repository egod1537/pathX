#pragma once

#include "stdafx.h"
#include "Component.h"

class ImWindow {
public:
	const std::string name;
	ImWindow(std::string name);

	virtual void Start() {}
	virtual void Update();
	virtual void End() {}

	template<typename T>
	T* AddComponent();

	template<typename T>
	T* GetComponent();

private:
	std::list<std::unique_ptr<Component>> components;
};

#include "ImWindow.inl"