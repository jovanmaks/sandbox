#include "TestAssemblied1.h"

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace test
{

    Atributes atr;
    grid::Buffer B;
    float width = atr.rows;
    float height = atr.colums;


 

    TestAssemblied1::TestAssemblied1()
    : m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))), 
    m_TranslationA(5.0f,5.0f,0.0f), m_Rotation(0.f,0.f,0.f), m_Scale(0.5f, 0.5f, 0.5f)
    {

        /* 
        int countVertexXYZ_RGBA = atr.countAllXYZ;
        float* verteksi = new float[countVertexXYZ_RGBA];
        B.VertexBuffer_XYZ_RGBA( verteksi); 
        */


        int countVertexXYZ = atr.countCoordinatesXYZ;
        float* verteksi2 = new float[countVertexXYZ];
        B.VertexBuffer_XYZ( verteksi2);

        std::vector <unsigned int> indeksi;
        B.IndexBuffer( indeksi );

        int countIndeks = atr.countIndeks;
        unsigned int* indeksiNiz = new unsigned int [countIndeks];
        indeksiNiz = &indeksi[0];



        m_VAO = std::make_unique<VertexArray>();     
        m_VertexBuffer = std::make_unique<VertexBuffer> (verteksi2, countVertexXYZ  *3 * sizeof(float));
        VertexBufferLayout layout;

        layout.Push<float>(3);

        // layout.Push<float>(3);
        // layout.Push<float>(4);



        m_VAO->AddBuffer(*m_VertexBuffer, layout);
        m_IndexBuffer = std::make_unique<IndexBuffer>(indeksiNiz, countIndeks);

        m_Shader = std::make_unique<Shader> ("../res/shaders/Basic2.shader");
        m_Shader-> Bind();
        m_Shader->SetUniform4f("u_Color", 0.8f, 0.4f, 0.2f, 1.0f );

        

    }

    TestAssemblied1::~TestAssemblied1()
    {
    }

    void TestAssemblied1::OnUpdate(float deltaTime)
    {
    }

    void TestAssemblied1::OnRender(GLFWwindow* window)
    {  

        GLCall(glClearColor( 0.0f, 0.0f, 0.0f, 1.0f )); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 

        GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));//  GL_FILL  GL_LINE  GL_POINT

        Renderer renderer; 


        {

           glm::mat4 m_Proj (1.0f);
           m_Proj = glm::ortho(0.0f, width , 0.0f, height, -1.0f, 1.0f);

           glm::mat4 model(1.0f);//identity matrux with 1 diagonal
           model = glm::translate( model, m_TranslationA );
           model = glm::rotate   ( model, glm::radians(50.f), m_Rotation );
           model = glm::scale    ( model,  m_Scale );

           
           


           glm::mat4 mvp = m_Proj * m_View * model;       

           m_Shader -> Bind();
           m_Shader -> SetUniformMat4f("u_MVP", mvp);
           renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
        }

            //=========== MODEL MATRIX ============================ 
                 /* Translation */
            if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
            {         
            m_TranslationA.x -= 0.1f;
            }else if( glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
             m_TranslationA.x += 0.1f;
            }else if( glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
             m_TranslationA.y += 0.1f;
            }else if( glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
             m_TranslationA.y -= 0.1f;
            
                   /* Scale */        
            }else if( glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
             m_Scale += 0.01f;             
            }else if( glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
             m_Scale -= 0.01f;             
             

                 /* Rotation */
            }else if( glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS){
             m_Rotation.x += 1.f;     
            }else if( glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS){
             m_Rotation.x -=1.f;
            }else if( glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS){
             m_Rotation.y += 1.f;
            }else if( glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS){
             m_Rotation.y -= 1.f;             
            }else if( glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS){
             m_Rotation.z += 1.f;
            }else if( glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS){
             m_Rotation.z -= 1.f;             
            } 
    }
    
    void TestAssemblied1::OnImGuiRender()
    {
        ImGui::Text("used projection and model matrices");
        ImGui::SliderFloat("Visina ",&width, 0, 12);//utice na m_Proj matricu. razvuce ga zapravo na dimenzije ekrana 
        ImGui::SliderFloat("Sirina `",&height, 0, 8);

        ImGui::Text("Use W A S D for moving ");
        ImGui::SliderFloat2("translationA", &m_TranslationA.x, 0.0f, 960.0f);

        ImGui::Text("Use G H J  &  T Y U for rotating");
        ImGui::SliderFloat3("rotation", &m_Rotation.x, 0.0f, 1960.0f);

        ImGui::Text("Use Q E  for scaling");
        ImGui::SliderFloat("Scale", &m_Scale.x, 0.0f, 960.0f);





    }


}