#pragma once

#include "Test.h"
#include "../Grid.h"



namespace test {

    class TestIris : public Test
    {
    public:
        TestIris();
        ~TestIris();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window,int* frameBufferWidth,int* frameBufferHeight) override;
        void OnImGuiRender() override;  
    private:
        std::unique_ptr<VertexArray>     m_VAO;
        std::unique_ptr<VertexBuffer>    m_VertexBuffer;
        std::unique_ptr<IndexBuffer>     m_IndexBuffer;
        std::unique_ptr<IndexBuffer>     m_IndexBuffer2;

        std::unique_ptr<Shader>          m_Shader;
        std::unique_ptr<Shader>          m_Shader2;



        glm::mat4 m_Proj, m_View;
        glm::vec3 m_TranslationA, m_Rotation, m_Scale;


    };
    
    
      
}