#include "Core.h"

#include "imgui.h"
#include "ImWindow.h"

void Core::Start() {

}

void Core::Update() {
    for (auto& window : windows) {
        ImGui::Begin(window->name.c_str());
        {
            window->Update();
        }
        ImGui::End();
    }
}

void Core::End() {

}

void Core::AddWindow(std::unique_ptr<ImWindow> window) {
    windows.push_back(std::move(window));
}