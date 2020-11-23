#pragma once

#include "Test.h"


namespace test {

    class TestAddingElement : public Test
    {
    public:
        TestAddingElement();
        ~TestAddingElement();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window,int* frameBufferWidth,int* frameBufferHeight) override;
        void OnImGuiRender() override;  
    private:
        float m_ClearColor[4];
    };
    
    
      
}