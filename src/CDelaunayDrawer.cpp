#include "CDelaunayDrawer.h"

#include "imgui.h"

void CDelaunayDrawer::OnDrawCanvas() {
	PushStyle(DrawStyle::Create().Stroke(IM_COL32(255, 0, 0, 255)).Build());
	{
		Line(ImVec2(0, 0), ImVec2(100, 100));
		Line(ImVec2(100, 0), ImVec2(0, 100));
	}
	PopStyle();
}