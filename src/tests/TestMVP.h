#pragma once

#include "Test.h"

namespace test {

    class TestMVP : public Test
    {
    public:
        TestMVP();
        ~TestMVP();

        void OnUpdate(float deltaTime) override;
        void OnRender(GLFWwindow* window) override;
        void OnImGuiRender() override;  

    private:
        std::unique_ptr<VertexArray>     m_VAO;
        std::unique_ptr<VertexBuffer>    m_VertexBuffer;
        std::unique_ptr<IndexBuffer>     m_IndexBuffer;
        std::unique_ptr<Shader>          m_Shader;


        glm::mat4 m_Proj, m_View;
        glm::vec3 m_TranslationA, m_RotationX, m_RotationY, m_RotationZ, m_Scale;
    };          
}