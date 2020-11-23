#include "TestColorAssign.h"

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace test
{

    TestColorAssign::TestColorAssign()
        : m_Proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)), m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))), 
          m_TranslationA(500,220,0)
    {


         float positions2[] =
        {     
           -50.0f,-50.0f,    //0
            50.0f, -50.0f,   //1
            50.0f,  50.0f,   //2
           -50.0f, 50.0f     //3
        };

        float positions[] =
        {     
           -50.0f,-50.0f,   0.58f, 0.6f, 0.96f, 1.0f,  //0
            50.0f, -50.0f,  0.6f, 0.16f, 1.0f,  1.0f,  //1
            50.0f,  50.0f,  0.6f, 0.36f, 1.0f,  1.0f,  //2
           -50.0f, 50.0f,   0.4f, 0.26f, 1.0f,  1.0f   //3


           
        };

        unsigned int indices[] = 
        {
        0, 1, 2,
        2, 3, 0,
    
        }; 

        m_VAO = std::make_unique<VertexArray>();     
        m_VertexBuffer = std::make_unique<VertexBuffer> (positions, 4 * 6 * sizeof(float));
        VertexBufferLayout layout;
        layout.Push<float>(2);

        layout.Push<float>(4);

        


        m_VAO->AddBuffer(*m_VertexBuffer, layout);
        m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6);

        m_Shader = std::make_unique<Shader> ("../res/shaders/Basic3.shader");
        m_Shader-> Bind();
        m_Shader->SetUniform4f("u_Color", 0.8f, 0.8f, 0.8f, 1.0f );



    } 


    TestColorAssign::~TestColorAssign()
    {

    }

    void TestColorAssign::OnUpdate(float deltaTime)
    {

    }

    void TestColorAssign::OnRender(GLFWwindow* window,int* frameBufferWidth,int* frameBufferHeight)
    {

 
        GLCall(glClearColor( 0.0f, 0.0f, 0.0f, 1.0f )); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 

        GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));//  GL_FILL  GL_LINE  GL_POINT


        Renderer renderer;


        {
           glm::mat4 model = glm::translate(glm::mat4(1.0f),m_TranslationA );
           glm::mat4 mvp = m_Proj * m_View * model;
           m_Shader -> Bind();
           m_Shader -> SetUniformMat4f("u_MVP", mvp);
           renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);      
  
        }

       
            if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
            {         
            m_TranslationA.x -= 5;
            }else if( glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
             m_TranslationA.x += 5;
            }else if( glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
             m_TranslationA.y += 5;
            }else if( glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
             m_TranslationA.y -= 5;
            }          


    }

    void TestColorAssign::OnImGuiRender()
    {
        ImGui::Text("Use 'W A S D'  `for moving the square");
        ImGui::SliderFloat2("translationA", &m_TranslationA.x, 0.0f, 960.0f);

    }


}