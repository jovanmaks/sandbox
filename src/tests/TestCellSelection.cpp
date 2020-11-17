#include "TestCellSelection.h"

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace test
{

    TestCellSelection::TestCellSelection()
        : m_ClearColor { 0.2f, 0.3f, 0.8f, 1.0f  }
    {

    }


    TestCellSelection::~TestCellSelection()
    {

    }

    void TestCellSelection::OnUpdate(float deltaTime)
    {

    }

    void TestCellSelection::OnRender(GLFWwindow* window)
    {

        GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3])); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 


    }

    void TestCellSelection::OnImGuiRender()
    {
        ImGui::ColorEdit4("Clear Color", m_ClearColor);

    }


}