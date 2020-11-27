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
    m_TranslationA(0.0f,0.0f,0.0f), m_Rotation(2.f,0.f,0.f), m_Scale(1.f, 1.f, 1.f)
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


        

         unsigned int Igraliste[6] = {
            0, 1 , 21,
            1, 21, 22};

        int countIgraliste = 6;  

        /* GLOBALNI VERTEX BUFFER */
        m_VertexBuffer = std::make_unique<VertexBuffer> (verteksi2, countVertexXYZ  *3 * sizeof(float));


        /* VAO za grid i tracker */
        m_VAO = std::make_unique<VertexArray>();     
        VertexBufferLayout layout;
        layout.Push<float>(3);
        m_VAO->AddBuffer(*m_VertexBuffer, layout);
        

        /* VAO2 za igraliste */
        m_VAO2 = std::make_unique<VertexArray>();     
        VertexBufferLayout layout2;
        layout2.Push<float>(3);
        m_VAO2->AddBuffer(*m_VertexBuffer, layout2);



        /* ovdje dodajes indekse za zice */
        m_IndexBuffer  = std::make_unique<IndexBuffer>(indeksiNiz,  countIndeks);

        /* ovdje dodajes indekse za igraliste */
        m_IndexBuffer4 = std::make_unique<IndexBuffer>(Igraliste, countIgraliste);






        //shader 1 je za selekciju
        m_Shader = std::make_unique<Shader> ("../res/shaders/Basic2.shader");
        m_Shader-> Bind();
        m_Shader->SetUniform4f("u_Color", 0.2f, 0.4f, 0.6f, 0.7f ); 

        //shader 2 je za zice
        m_Shader2 = std::make_unique<Shader> ("../res/shaders/Basic2.shader");
        m_Shader2-> Bind();
        m_Shader2-> SetUniform4f("u_Color", 0.6f, 0.6f, 0.6f, 0.5f );

        //shader 3 je za selekciju klik crveni
        m_Shader3 = std::make_unique<Shader> ("../res/shaders/Basic2.shader");
        m_Shader3-> Bind();
        m_Shader3-> SetUniform4f("u_Color", 1.f, 0.f, 0.f, 1.f );

        //shader 4 je za Igraliste
        m_Shader4 = std::make_unique<Shader> ("../res/shaders/Basic2.shader");
        m_Shader4-> Bind();
        m_Shader4-> SetUniform4f("u_Color", 1.f, 1.f, 0.f, 1.f );



        

    }

    TestAssemblied1::~TestAssemblied1()
    {
    }

    void TestAssemblied1::OnUpdate(float deltaTime)
    {
    }

    void TestAssemblied1::OnRender(GLFWwindow* window,int* frameBufferWidth,int* frameBufferHeight)
    {  

        GLCall(glClearColor( 0.0f, 0.0f, 0.0f, 1.0f )); 
        GLCall(glClear( GL_COLOR_BUFFER_BIT )); 

        Renderer renderer; 

        GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));// GL_FRONT, GL_FRONT_AND_BACK...  GL_FILL  GL_LINE  GL_POINT


        

        //mora biti 'm v p ' redoslijed kad ih gradis
        {    


            /* Model matrix. mora da ide t r s redoslijed kad ih gradis*/
           glm::mat4 model(1.0f);//identity matrux with 1 diagonal
           model = glm::translate( model, m_TranslationA );
           model = glm::rotate   ( model, glm::radians(45.f), m_Rotation );
           model = glm::scale    ( model,  m_Scale );


            /* Viev matrix */            
           glm::vec3 camPosition(0.f, 0.f, 2.f);
           glm::vec3 worldUp(0.f, 1.f, 0.f);
           glm::vec3 camFront(0.f, 0.f, -1.f);
           glm::mat4 m_View(1.0);
           m_View = glm::lookAt(camPosition, camPosition +camFront, worldUp);



            /* Projection matrix */
           
           float fov = 35.f;
           float nearPlane = 0.1f;
           float farPlane = 100.f;

             int r1 = *frameBufferWidth;
             int r2 = *frameBufferHeight;
            float ratio = r1/r2;

           glfwGetFramebufferSize(window, &r1, &r2);

            //glm::mat4 m_Proj (1.0f);
           glm::mat4 m_Proj = glm::ortho(0.0f, width , 0.0f, height, -1.0f, 1.0f);
            // m_Proj = glm::perspective(glm::radians(fov), static_cast<float>(ratio), nearPlane, farPlane);
           glm::mat4 mvp = m_Proj * m_View * model;  


            //===========================================================
            /* OVDJE ISCRTAVAS IGRALISTE  */
            //===========================================================

            m_Shader4 -> Bind(); 
            m_Shader4 -> SetUniformMat4f("u_MVP", m_Proj);
            renderer.Draw(*m_VAO, *m_IndexBuffer4, * m_Shader4);  




            //===========================================================
            /* OVDJE RADIS SELEKCIJU  */
            //===========================================================


            double mouseX;
            double mouseY;
        
            unsigned int kvadrat = 6;
            

            glfwGetCursorPos(window, &mouseX, &mouseY);       
            
             if(mouseX<0 || mouseY<0 || mouseX>atr.ScreenWidth || mouseY>atr.ScreenHeight)
             {
                mouseX = 2;
                mouseY = 2;
                kvadrat = 0;
             }
                      

            
            std::cout<<"Pozicija: "<<"  X= "<<mouseX << "   Y= "<< mouseY <<std::endl;

            unsigned int* test = new unsigned int[kvadrat];
            B.IndexBufferElement(mouseX, mouseY, test);

            for(int i=0; i<kvadrat; i++)
            std::cout<< test[i] << "  ";

            std::cout<<std::endl;         
            
            /* Indeksi za traker svijetli */
             m_IndexBuffer2 = std::make_unique<IndexBuffer>(test, kvadrat);
             
      

            /*  ovaj dio koda nije izbrisan jer pokazuje kako sa glm-om mozes odraditi intersect

            glm::vec3 origin(mouseX, mouseY, -1.f);
            glm::vec3 direction(mouseX, mouseY, 1.f);

            glm::vec3 vert0( 0.f, 1600.0f-160.0f, 0.f);
            glm::vec3 vert1( 1600.0f/10, 1600.f, 0.f);
            glm::vec3 vert2( 0.f, 1600.f, 0.f);


            float distance;
            float baryX;
            float baryY;
            glm::vec2 baryposition(baryX, baryY);

            std::cout<<"Pozicija: "<<"  X= "<<mouseX << "   Y= "<< mouseY <<std::endl;

            if( glm::intersectRayTriangle ( origin, direction, vert0, vert1, vert2, baryposition,  distance))//ovdje samo dodas && i trougao pored da ti selektuje kvadratic
            {
                std::cout<<"Presjekao na: "<<"  X= "<<mouseX << "   Y= "<< mouseY <<std::endl;

                //Filled mesh
                m_Shader -> Bind(); 
                m_Shader -> SetUniformMat4f("u_MVP", m_Proj);
                renderer.Draw(*m_VAO, *m_IndexBuffer2, *m_Shader);
            }

            else
                std::cout<<"Nije presjekao"<<std::endl; 
                */

        
            //===============================================================        
            /* TRACKER I MOUSE INPUT */
            //===============================================================

            //Filled mesh
            m_Shader -> Bind(); 
            m_Shader -> SetUniformMat4f("u_MVP", m_Proj);
            renderer.Draw(*m_VAO, *m_IndexBuffer2, * m_Shader);    


            if( glfwGetMouseButton (  window, GLFW_MOUSE_BUTTON_LEFT ) == GLFW_PRESS )
            {
                /* kod za iscrtavanje kvadrata */
                m_Shader3 ->Bind();
                m_Shader3 -> SetUniformMat4f("u_MVP", m_Proj);
                renderer.Draw(*m_VAO, * m_IndexBuffer2, * m_Shader3);
            }


            //===========================================================
            /* OVDJE CRTAS MREZU  */
            //===========================================================

            //Wires over filled mesh
            GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));// GL_FRONT, GL_FRONT_AND_BACK...  GL_FILL  GL_LINE  GL_POINT
            m_Shader2 -> Bind(); 
            m_Shader2 -> SetUniformMat4f("u_MVP", m_Proj);
            renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader2); 

        }

  


            //=========== MODEL MATRIX ============================ 
                 /* Translation */
            if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
            {         
            m_TranslationA.x -= 0.03f;
            }else if( glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
             m_TranslationA.x += 0.03f;
            }else if( glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
             m_TranslationA.y += 0.03f;
            }else if( glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
             m_TranslationA.y -= 0.03f;
            
                   /* Scale */        
            }else if( glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
             m_Scale += 0.001f;             
            }else if( glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
             m_Scale -= 0.001f;             
             

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
        ImGui::Text("Ukljucena je samo frontalna projektna matrica da bi se dobio frontalni pogled");
        ImGui::Text("Sve je tvrdo kodirano (indeksi zapravo) pa radi samo trenutno na matrici 10x10 ");


        ImGui::SliderFloat("Visina ",&width, 0, 12);//utice na m_Proj matricu. razvuce ga zapravo na dimenzije ekrana 
        ImGui::SliderFloat("Sirina `",&height, 0, 8);

        // ImGui::Text("Use W A S D for moving ");
        // ImGui::SliderFloat2("translationA", &m_TranslationA.x, 0.0f, 960.0f);

        // ImGui::Text("Use G H J  &  T Y U for rotating");
        // ImGui::SliderFloat3("rotation", &m_Rotation.x, 0.0f, 1960.0f);

        // ImGui::Text("Use Q E  for scaling");
        // ImGui::SliderFloat("Scale", &m_Scale.x, 0.0f, 960.0f);





    }


}