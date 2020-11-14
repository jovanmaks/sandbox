/* OpenGl */
#include <GL/glew.h> 
#include <GLFW/glfw3.h>
/* UI */
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"
/* Tests */
#include "tests/TestClearColor.h"
#include "tests/TestTexture2D.h"
#include "tests/TestKeyInput.h"




int main (void)
{
    

    /* Setting up OpenGL and GLFW */
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




    /* Important stuf */
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


    /* Calling the tests*/
    test::Test* currentTest = nullptr;
    test::TestMenu* testMenu = new test::TestMenu( currentTest );
    currentTest = testMenu; 


    testMenu->RegisterTest<test::TestClearColor> (" Clear Color ");
    testMenu->RegisterTest<test::TestTexture2D>  (" Texture 2D  ");
    testMenu->RegisterTest<test::TestKeyInput>   (" Key Input   ");


  



    /* Main while loop */
    while(!glfwWindowShouldClose(window))
    {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        renderer.Clear();
        

        ImGui_ImplGlfw_NewFrame();  
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();


        if( currentTest)
        {
            currentTest->OnUpdate(0.0f);
            currentTest-> OnRender();
            ImGui::Begin("Test");
            if ( currentTest != testMenu && ImGui::Button ("<-"))
            {
                delete currentTest; 
                currentTest = testMenu; 

            }
            currentTest->OnImGuiRender();

            ImGui::End();
        }


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    delete currentTest;
    if (currentTest != testMenu)
        delete testMenu;
    
    }


    ImGui_ImplGlfw_Shutdown();   
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;

}