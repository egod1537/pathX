cmake_minimum_required(VERSION 3.24)  # 3.31도 가능하지만 호환 고려
project(pathX)

set(CMAKE_CXX_STANDARD 17)

# 소스 디렉토리
set(SRC_DIR src)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)

# ImGui 디렉토리
set(IMGUI_DIR extern/imgui)
set(IMGUI_SRC
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/backends/imgui_impl_dx11.cpp
        ${IMGUI_DIR}/backends/imgui_impl_win32.cpp
)

set(CDT_INCLUDE_DIR extern/CDT/CDT/include)
# include 경로 추가
include_directories(
        ${SRC_DIR}
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
        ${CDT_INCLUDE_DIR}
)

# 실행파일 생성
add_executable(pathX ${SRC_FILES} ${IMGUI_SRC})
set_target_properties(pathX PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

# 링크할 윈도우용 라이브러리들
if (WIN32)
    target_compile_definitions(pathX PRIVATE -DUNICODE -D_UNICODE -DNOMINMAX)
    target_link_libraries(pathX
            d3d11
            dxgi
            dxguid
            user32
            gdi32
    )
endif()
