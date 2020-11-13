/* OpenGl */
#include <GL/glew.h> 
#include <GLFW/glfw3.h>

//for raise(SIGTRAP) function in gcc - instead of __debugbreak()
#include <signal.h>



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"


#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"


/* UI */
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"


#include "tests/TestClearColor.h"




int main (void)
{

    GLFWwindow* window;

    if (!glfwInit())
        return -1;


    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// GLFW_OPENGL_CORE_PROFILE  GLFW_OPENGL_COMPAT_PROFILE 



    window = glfwCreateWindow(960, 540, "sandbox", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    GLenum err1 = glewInit();
    if (GLEW_OK != err1)
    {
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err1));    
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "Status: Using GL %s\n", glGetString(GL_VERSION));

    {


    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)  );



    Renderer renderer;



    /* Setup Dear ImGui context */     
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io; 
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();

    test::TestClearColor test;
      

    while(!glfwWindowShouldClose(window))
    {

        renderer.Clear();
        

        test.OnUpdate(0.0f);
        test.OnRender();

        ImGui_ImplGlfw_NewFrame();  
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        test.OnImGuiRender();



        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


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