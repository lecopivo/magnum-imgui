# Build library
find_package(Magnum REQUIRED
  Shaders
  Sdl2Application)
find_package(SDL2 REQUIRED)

add_library(MagnumImGui MagnumImGui.cpp ${MagnumImGuiShaders_RCS})

target_link_libraries(MagnumImGui
  Magnum::Application
  Magnum::GL
)

set_target_properties(MagnumImGui PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)


install(TARGETS MagnumImGui DESTINATION "lib/")
install(FILES MagnumImGui.h DESTINATION "include/")

# Build exmaple
if(BUILD_EXAMPLE)
add_executable(Example Example.cpp)

find_library(IMGUI_LIB ImGui)
target_link_libraries(Example
  Magnum::Application
  Magnum::Magnum
  Magnum::Shaders
  MagnumImGui
  ${IMGUI_LIB})
  SDL2::SDL2

set_target_properties(Example PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
endif()
