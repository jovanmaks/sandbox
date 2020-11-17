#pragma once

#include "Test.h"


namespace test {

    class TestPerspectiveView : public Test
    {
    public:
        TestPerspectiveView();
        ~TestPerspectiveView();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window) override;
        void OnImGuiRender() override;  
    private:
        float m_ClearColor[4];
    };
    
    
      
}