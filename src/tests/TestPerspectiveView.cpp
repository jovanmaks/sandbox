#include "TestPerspectiveView.h"

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace test
{

    TestPerspectiveView::TestPerspectiveView()
        : m_ClearColor { 0.2f, 0.3f, 0.8f, 1.0f  }
    {

    }


    TestPerspectiveView::~TestPerspectiveView()
    {

    }

    void TestPerspectiveView::OnUpdate(float deltaTime)
    {

    }

    void TestPerspectiveView::OnRender(GLFWwindow* window)
    {

        GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3])); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 


    }

    void TestPerspectiveView::OnImGuiRender()
    {
        ImGui::ColorEdit4("Clear Color", m_ClearColor);

    }


}