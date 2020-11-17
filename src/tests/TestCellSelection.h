#pragma once

#include "Test.h"


namespace test {

    class TestCellSelection : public Test
    {
    public:
        TestCellSelection();
        ~TestCellSelection();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window) override;
        void OnImGuiRender() override;  
    private:
        float m_ClearColor[4];
    };
    
    
      
}