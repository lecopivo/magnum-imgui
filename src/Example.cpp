// The MIT License (MIT)
//
// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or distribute
// this software, either in source code form or as a compiled binary, for any
// purpose, commercial or non - commercial, and by any means.
//
// In jurisdictions that recognize copyright laws, the author or authors of
// this software dedicate any and all copyright interest in the software to
// the public domain.We make this dedication for the benefit of the public
// at large and to the detriment of our heirs and successors.We intend this
// dedication to be an overt act of relinquishment in perpetuity of all
// present and future rights to this software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#include "Example.h"

#include <Magnum/Math/Color.h>
#include <Magnum/Renderer.h>
#include <Magnum/Version.h>

Example::Example(const Arguments &arguments)
    : Platform::Application{
          arguments, Configuration{}
                         .setTitle("Magnum Imgui port")
                         .setWindowFlags(Configuration::WindowFlag::Resizable)
                         .setSize({1280, 960})} {}

void Example::drawEvent() {
  Renderer::setClearColor(
      {clear_color.x, clear_color.y, clear_color.z, clear_color.w});
  defaultFramebuffer.clear(FramebufferClear::Color);

  mMagnumImgui.newFrame(windowSize(), defaultFramebuffer.viewport().size());

  // 1. Show a simple window
  // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a
  // window automatically called "Debug"
  {
    static float f = 0.0f;
    ImGui::Text("Hello, world!");
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::ColorEdit3("clear color", (float *)&clear_color);
    if (ImGui::Button("Test Window"))
      show_test_window ^= 1;
    if (ImGui::Button("Another Window"))
      show_another_window ^= 1;
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
  }

  // 2. Show another simple window, this time using an explicit Begin/End pair
  if (show_another_window) {
    ImGui::SetNextWindowSize(ImVec2(500, 100), ImGuiSetCond_FirstUseEver);
    ImGui::Begin("Another Window", &show_another_window);
    ImGui::Text("Hello");
    ImGui::End();
  }

  // 3. Show the ImGui test window. Most of the sample code is in
  // ImGui::ShowTestWindow()
  if (show_test_window) {
    ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
    // ImGui::ShowTestWindow(&show_test_window);
    ImGui::ShowTestWindow();
  }

  mMagnumImgui.drawFrame();

  swapBuffers();

  redraw();
}

void Example::viewportEvent(const Vector2i &size) {
  defaultFramebuffer.setViewport({{}, size});
}

void Example::keyPressEvent(KeyEvent &event) {
  mMagnumImgui.keyPressEvent(event);
}

void Example::keyReleaseEvent(KeyEvent &event) {
  mMagnumImgui.keyReleaseEvent(event);
}

void Example::mousePressEvent(MouseEvent &event) {
  mMagnumImgui.mousePressEvent(event);
}

void Example::mouseReleaseEvent(MouseEvent &event) {
  mMagnumImgui.mouseReleaseEvent(event);
}

void Example::mouseMoveEvent(MouseMoveEvent &event) {
  mMagnumImgui.mouseMoveEvent(event);
}

void Example::mouseScrollEvent(MouseScrollEvent &event) {
  mMagnumImgui.mouseScrollEvent(event);
}

void Example::textInputEvent(TextInputEvent &event) {
  mMagnumImgui.textInputEvent(event);
}

MAGNUM_APPLICATION_MAIN(Example)
