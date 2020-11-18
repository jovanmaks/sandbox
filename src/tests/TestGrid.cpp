#include "TestGrid.h"

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace test
{

     Atributes atr;
     grid::Buffer B;


     float sirina = atr.rows;
     float visina = atr.colums;


      

        TestGrid::TestGrid()      
         :  m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))), 
          m_TranslationA(500,220,0)  
    { 

        //=============================
        /* ovdje si doveo svih osam verteksa posto pravis samo jedan */
        //=============================

        int countIndeks = atr.countIndeks;
        int countVertex = atr.countCoordinates;

        int count = countVertex/2;

    
        float* verteksi = new float[countVertex];
        B.VertexBuffer_XY(verteksi);


        std::vector <unsigned int> indeksi;
        B.IndexBuffer(indeksi);


        unsigned int* indeksiNiz = new unsigned int [countIndeks];
        indeksiNiz = &indeksi[0];




        m_VAO = std::make_unique<VertexArray>();     
        m_VertexBuffer = std::make_unique<VertexBuffer> (verteksi, countVertex * 2 * sizeof(float));
        VertexBufferLayout layout;
        layout.Push<float>(2);

        m_VAO->AddBuffer(*m_VertexBuffer, layout);
        m_IndexBuffer = std::make_unique<IndexBuffer>(indeksiNiz, countIndeks);

        m_Shader = std::make_unique<Shader> ("../res/shaders/Basic2.shader");
        m_Shader-> Bind();
        m_Shader->SetUniform4f("u_Color", 0.8f, 0.8f, 0.8f, 1.0f );

    }


    TestGrid::~TestGrid()
    {
    }

    void TestGrid::OnUpdate(float deltaTime)
    {

    }

    void TestGrid::OnRender(GLFWwindow* window)
    {

        GLCall(glClearColor( 0.0f, 0.0f, 0.0f, 1.0f )); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 

        GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));//  GL_FILL  GL_LINE  GL_POINT

        Renderer renderer; 


        {

           glm::mat4 m_Proj = glm::ortho(0.0f, sirina , 0.0f, visina, -1.0f, 1.0f);            
           m_Shader -> Bind();
           m_Shader -> SetUniformMat4f("u_MVP", m_Proj);
           renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
        }
    }

    void TestGrid::OnImGuiRender()
    {
           ImGui::Text("Grid. Only projection matrix used");
           ImGui::SliderFloat("Visina ",&sirina, 0, 12);
           ImGui::SliderFloat("Sirina `",&visina, 0, 8);

    }
}