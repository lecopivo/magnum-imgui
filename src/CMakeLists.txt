project(MagnumImGui CXX)

# Build library
find_package(Magnum REQUIRED
  Shaders
  Sdl2Application)
find_package(SDL2 REQUIRED)
find_package(imgui REQUIRED)

add_library(${PROJECT_NAME} MagnumImGui.cpp ${MagnumImGuiShaders_RCS})

target_link_libraries(${PROJECT_NAME}
  Magnum::Application
  Magnum::GL
  imgui::imgui
  )

install(TARGETS ${PROJECT_NAME}
  EXPORT MAGNUMIMGUIExport
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )
install(FILES MagnumImGui.h DESTINATION "include/")
install(EXPORT MAGNUMIMGUIExport FILE ${PROJECT_NAME}Config.cmake NAMESPACE ${PROJECT_NAME}:: DESTINATION share/${PROJECT_NAME})

# Build exmaple
if(BUILD_EXAMPLE)
  add_executable(Example Example.cpp)

  target_link_libraries(Example
    Magnum::Application
    Magnum::Magnum
    Magnum::Shaders
    ${PROJECT_NAME}
    SDL2::SDL2
    imgui::imgui
    )
endif()
