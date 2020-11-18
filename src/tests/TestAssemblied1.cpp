#include "TestAssemblied1.h"

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace test
{

    TestAssemblied1::TestAssemblied1()
        : m_ClearColor { 0.2f, 0.3f, 0.8f, 1.0f  }
    {

    }


    TestAssemblied1::~TestAssemblied1()
    {

    }

    void TestAssemblied1::OnUpdate(float deltaTime)
    {

    }

    void TestAssemblied1::OnRender(GLFWwindow* window)
    {

        GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3])); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 


    }

    void TestAssemblied1::OnImGuiRender()
    {
        ImGui::ColorEdit4("Clear Color", m_ClearColor);

    }


}