#pragma once

#include "Test.h"


namespace test {

    class TestClearColor : public Test
    {
    public:
        TestClearColor();
        ~TestClearColor();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window,int* frameBufferWidth,int* frameBufferHeight) override;
        void OnImGuiRender() override;  
    private:
        float m_ClearColor[4];
    };
    
    
      
}