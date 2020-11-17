#pragma once

#include "Test.h"


namespace test {

    class TestColorAssign : public Test
    {
    public:
        TestColorAssign();
        ~TestColorAssign();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window) override;
        void OnImGuiRender() override;  
    private:
        float m_ClearColor[4];
    };
    
    
      
}