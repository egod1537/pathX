#pragma once

#include "stdafx.h"
class ImWindow;

class Core {
public :
	void Start();
	void Update();
	void End();

	void AddWindow(std::unique_ptr<ImWindow> window);

private:
	std::list<std::unique_ptr<ImWindow>> windows;
};