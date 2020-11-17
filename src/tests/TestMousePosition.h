#pragma once

#include "Test.h"


namespace test {

    class TestMousePosition : public Test
    {
    public:
        TestMousePosition();
        ~TestMousePosition();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window) override;
        void OnImGuiRender() override;  
    private:
        float m_ClearColor[4];
    };
    
    
      
}