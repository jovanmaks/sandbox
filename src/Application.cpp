/* OpenGl */
#include <GL/glew.h> 
#include <GLFW/glfw3.h>

/* Atributes */
#include "Atributes.h"

/* UI */
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

/* STREAM */
//for raise(SIGTRAP) function in gcc - instead of __debugbreak()
#include <signal.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/* CLASSES */
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "Grid.h"

/* Math */
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

/* Tests */
/* #include "tests/TestClearColor.h"
#include "tests/TestTexture2D.h"
#include "tests/TestKeyInput.h"
#include "tests/TestGrid.h"
#include "tests/TestMousePosition.h"
#include "tests/TestColorAssign.h"
#include "tests/TestCellSelection.h"
#include "tests/TestPerspectiveView.h"
#include "tests/TestAddingElement.h"
#include "tests/TestMVP.h"

#include "tests/TestAssemblied1.h"
#include "tests/TestIris.h" */






// #define SCREEN_WIDTH 900
// #define SCREEN_HEIGHT 900


void cursorPositionCallback ( GLFWwindow *window, double xPos, double yPos)
{
    std::cout<< xPos << "   :   " << yPos << std::endl;
}


void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{

    glViewport(0, 0, fbW, fbH);
}



void updateInput(GLFWwindow* window)
{

       if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//////////KRAJ
       {
             glfwTerminate();    

       }

}




int main (void)
{
    Atributes atr;
    grid::Buffer B;
    float width = atr.rows;
    float height = atr.colums;

    int SCREEN_WIDTH = atr.ScreenWidth;
    int SCREEN_HEIGHT = atr.ScreenHeight;

    int frameBufferWidth = 0;
    int frameBufferHeight = 0;

    /* Setting up OpenGL and GLFW */
    GLFWwindow* window;


    if (!glfwInit())
        return -1;

    

    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// GLFW_OPENGL_CORE_PROFILE  GLFW_OPENGL_COMPAT_PROFILE 


    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "sandbox", NULL, NULL);

    // glfwSetCursorPosCallback( window, cursorPositionCallback );

    if(!window)
    {
        glfwTerminate();
        return -1;
    }


    glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
    // glViewport(0, 0, frameBufferWidth, frameBufferHeight);
    
    glfwMakeContextCurrent(window);

    glfwSwapInterval(0.5);


    GLenum err1 = glewInit();
    if (GLEW_OK != err1)
    {
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err1));    
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "Status: Using GL %s\n", glGetString(GL_VERSION));   



    
    //=======================================================================
    //=======================================================================
    //=======================================================================




    /* Important stuf */
 {

    //===========  BATCHED POSITIONS =======================

    int countPlayground = 6;  
    unsigned int* Playground = new unsigned int [countPlayground];
    B.IndexBufferElement(Playground);


    int countVertexXYZ = atr.countCoordinatesXYZ;
    float* verteksi2 = new float[countVertexXYZ];
    B.VertexBuffer_XYZ( verteksi2);

    std::vector <unsigned int> indeksi;
    B.IndexBuffer( indeksi );



    int countIndeks = atr.countIndeks;
    unsigned int* indeksiNiz = new unsigned int [countIndeks];
    indeksiNiz = &indeksi[0];

    //======================================================


    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)  );

    /* Vertex array layout */
    VertexArray va;
    VertexBuffer vb(verteksi2, countVertexXYZ * 3 * sizeof(float));
    VertexBufferLayout layout;
    layout.Push<float>(3);
    va.AddBuffer(vb, layout);


    /* Index array */
    IndexBuffer ib_Wires(indeksiNiz, countIndeks);
    IndexBuffer ib_Playground(Playground, countPlayground);


    /* Matrices   */
    glm::mat4 proj  = glm::ortho(0.0f, width, 0.0f, height, -1.0f, 1.0f);
    // glm::mat4 view  = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));


    /* Shader for wires */
    Shader shaderWires("../res/shaders/Basic2.shader");
    shaderWires.Bind();
    shaderWires.SetUniform4f("u_Color",0.6f, 0.6f, 0.6f, 0.5f );

    /* Shader for tracker */
    Shader shaderTracker("../res/shaders/Basic2.shader");
    shaderTracker.Bind();
    shaderTracker.SetUniform4f("u_Color",0.2f, 0.4f, 0.6f, 0.7f );

    /* Shader for playground */
    Shader shaderPlayground("../res/shaders/Basic2.shader");
    shaderPlayground.Bind();
    shaderPlayground.SetUniform4f("u_Color",1.f, 1.f, 0.f, 1.f );

    va.Unbind();
    vb.Unbind();
    ib_Wires.Unbind();
    shaderWires.Unbind();
    shaderTracker.Unbind();
    shaderPlayground.Unbind();


    Renderer renderer;



    /* Setup Dear ImGui context */     
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io; 
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();


    //flags for trigerring imGui 
    bool show_another_window = true;



    /* Main if loop */
 

    /* Main while loop */
    while(!glfwWindowShouldClose(window))
    {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        renderer.Clear();
        

        ImGui_ImplGlfw_NewFrame();  
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();           
   

        //===========================================================
        /* BLOK KODA ZA TRAKER */
        //===========================================================


        /* Tracker */
        {
            GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));// GL_FRONT, GL_FRONT_AND_BACK...  GL_FILL  GL_LINE  GL_POINT
            
            double mouseX;
            double mouseY;
            int countIndexTracker = 6;
            glfwGetCursorPos(window, &mouseX, &mouseY);       
            /* test for out of screen  */
            if(mouseX<0 || mouseY<0 || mouseX>atr.ScreenWidth || mouseY>atr.ScreenHeight)
            {
            mouseX = 2;
            mouseY = 2;
            countIndexTracker = 0;
            }

            std::cout<<"Position: "<<"  X= "<<mouseX << "   Y= "<< mouseY <<std::endl;

            unsigned int* tracker = new unsigned int[countIndexTracker];
            B.IndexBufferTracker(mouseX, mouseY, tracker);
            IndexBuffer ib_Tracker(tracker, countIndexTracker);

            shaderTracker.Bind();
            shaderTracker.SetUniformMat4f("u_MVP", proj);
            renderer.Draw(va, ib_Tracker, shaderTracker);
        }


        /* Playground */
        {
            shaderPlayground.Bind();
            shaderPlayground.SetUniformMat4f("u_MVP", proj);
            renderer.Draw(va, ib_Playground, shaderPlayground);            
        }

        /* Wires */
        {
            GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));// GL_FRONT, GL_FRONT_AND_BACK...  GL_FILL  GL_LINE  GL_POINT
            shaderWires.Bind();
            shaderWires.SetUniformMat4f("u_MVP", proj);
            renderer.Draw(va, ib_Wires, shaderWires);      
        }


        /* ImGui UI */
        if( show_another_window)
        {
            ImGui::Begin("PASULJKO");         
            ImGui::Text("Ovdje vlada pasuljko!");
            ImGui::End();
        }

    
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());    

        updateInput(window);//ovo ti je funkcija za tastaturu koja pravi core dumped.
        // Nastaje zato sto zatvoris prozor a ostane neizbrisan delta time u imguiu. Mora ovdje jer prima window kontekst. Dolje ne moze jer nema konteksta.
        glfwSwapBuffers(window);
        glfwPollEvents();        

    }

    
 }
 
    ImGui_ImplGlfw_Shutdown();   
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();    
    glfwTerminate();

    return 0;

}

