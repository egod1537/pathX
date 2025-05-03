#include "CDelaunayCanvas.h"

#include <CDT.h>
#include <iostream>
#include "imgui.h"

void CDelaunayCanvas::OnDrawCanvas()
{
	std::vector<ImVec2> points = {
		{0.0f, 0.0f},
		{100.0f, 0.0f},
		{0.0f, 100.0f},
		{100.0f, 100.0f},
		{50.0f, 50.0f},
		{50.0f, 150.0f},
		{200.0f, 100.0f},
	};

	std::vector<CDT::V2d<float>> pointsV2d(points.size());
	std::transform(
		points.begin(),
		points.end(),
		pointsV2d.begin(),
		[](const ImVec2 &p)
		{
			return CDT::V2d<float>{p.x, p.y};
		});

	CDT::Triangulation<float> cdt;
	cdt.insertVertices(pointsV2d);
	cdt.eraseSuperTriangle();

	auto triangles = cdt.triangles;
	PushStyle(DrawStyle::Create()
				  .Fill(IM_COL32(255, 0, 0, 255))
				  .Build());
	{
		for (auto &triangle : triangles)
		{
			auto &[a, b, c] = triangle.vertices;
			Line(points[a], points[b]);
			Line(points[b], points[c]);
			Line(points[a], points[c]);
		}
	}
	PopStyle();
}

void CDelaunayCanvas::OnMouseMove(ImVec2 position)
{
	std::cout << position.x << " " << position.y << "\n";
}