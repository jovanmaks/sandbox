#pragma once 

#include <functional>
#include <vector>
#include <iostream>

#include "../VertexBuffer.h"
#include "../VertexBufferLayout.h"
#include "../Texture.h"

#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtx/intersect.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"

#include <memory>


namespace test 
{

    class Test
    {
    private:
        /* data */
    public:
        Test(){}
        virtual ~Test(){}

        virtual void OnUpdate( float deltaTime) {}
        virtual void OnRender(GLFWwindow* window, int* frameBufferWidth,int* frameBufferHeight){ }
        virtual void OnImGuiRender() {}
    };
    

    class TestMenu : public Test
    {
        public:
            TestMenu( Test*& currentTestPointer);

            void OnImGuiRender() override;

            template <typename T>
            void RegisterTest ( const std::string& name )
            {
                std::cout << "Registering test"<< name << std::endl;


                m_Tests.push_back(std::make_pair(name, [](){return new T(); } ));
            }
        private:
            Test*& m_CurrentTest;
            std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;

    };
    


}