#include "TestAddingElement.h"

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace test
{

    TestAddingElement::TestAddingElement()
        : m_ClearColor { 0.2f, 0.3f, 0.8f, 1.0f  }
    {

    }


    TestAddingElement::~TestAddingElement()
    {

    }

    void TestAddingElement::OnUpdate(float deltaTime)
    {

    }

    void TestAddingElement::OnRender(GLFWwindow* window,int* frameBufferWidth,int* frameBufferHeight)
    {

        GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3])); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 


    }

    void TestAddingElement::OnImGuiRender()
    {
        ImGui::ColorEdit4("Clear Color", m_ClearColor);

    }


}