#pragma once

#include "CCanvas.h"

class CDelaunayCanvas : public CCanvas
{
public:
	void OnDrawCanvas() override;

	void OnMouseMove(ImVec2 position) override;
};