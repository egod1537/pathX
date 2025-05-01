#include "CTestCanvas.h"

#include "imgui.h"

void CTestCanvas::Update() {
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImVec2 canvas_size = ImGui::GetContentRegionAvail();

    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    // 배경 사각형
    draw_list->AddRectFilled(p, ImVec2(p.x + canvas_size.x, p.y + canvas_size.y), IM_COL32(50, 50, 50, 255));

    // 예: 선, 사각형, 원
    draw_list->AddLine(ImVec2(p.x + 10, p.y + 10), ImVec2(p.x + 100, p.y + 100), IM_COL32(255, 0, 0, 255), 2.0f);
    draw_list->AddRect(ImVec2(p.x + 120, p.y + 20), ImVec2(p.x + 200, p.y + 100), IM_COL32(0, 255, 0, 255), 5.0f);
    draw_list->AddCircle(ImVec2(p.x + 300, p.y + 80), 40.0f, IM_COL32(0, 128, 255, 255), 32, 3.0f);

    // 마우스 입력 처리
    ImGui::InvisibleButton("canvas", canvas_size, ImGuiButtonFlags_MouseButtonLeft);
    bool is_hovered = ImGui::IsItemHovered();
    bool is_active = ImGui::IsItemActive();

    ImVec2 mouse_pos = ImGui::GetIO().MousePos;
}