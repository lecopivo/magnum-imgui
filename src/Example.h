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
#pragma once
#ifndef Example_h__
#define Example_h__

#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/DefaultFramebuffer.h>

// To use installed version of MagnumImGui change the following two lines to:
// #include <MagnumImGui/MagnumImGui.h>
// #include <MagnumImGui/imgui.h>
#include "MagnumImGui.h"     
#include <imgui.h>

using namespace Magnum;

class Example : public Platform::Application
{
public:
  explicit Example(const Arguments& arguments);

  void drawEvent() override;

  void viewportEvent(const Vector2i& size) override;

  void keyPressEvent(KeyEvent& event) override;

  void keyReleaseEvent(KeyEvent& event) override;

  void mousePressEvent(MouseEvent& event) override;

  void mouseReleaseEvent(MouseEvent& event) override;

  void mouseMoveEvent(MouseMoveEvent& event) override;

  void mouseScrollEvent(MouseScrollEvent& event) override;

  void textInputEvent(TextInputEvent& event) override;

private:
  MagnumImGui mMagnumImgui;

  bool show_test_window = true;
  bool show_another_window = false;
  ImVec4 clear_color = ImColor(114, 144, 154);
};

#endif // Example_h__
