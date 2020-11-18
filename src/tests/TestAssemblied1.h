#pragma once

#include "Test.h"


namespace test {

    class TestAssemblied1 : public Test
    {
    public:
        TestAssemblied1();
        ~TestAssemblied1();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window) override;
        void OnImGuiRender() override;  
    private:
        float m_ClearColor[4];
    };
    
    
      
}