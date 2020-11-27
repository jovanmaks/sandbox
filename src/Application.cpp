/* Atributes */
#include "Atributes.h"

/* UI */
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

/* Tests */
#include "tests/TestClearColor.h"
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
#include "tests/TestIris.h"



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




    testMenu->RegisterTest<test::TestAssemblied1>       (" PASULJKO       ");
    testMenu->RegisterTest<test::TestIris>              (" IRIS           ");

    // testMenu->RegisterTest<test::TestClearColor>        (" Clear Color      ");
    // testMenu->RegisterTest<test::TestTexture2D>         (" Texture 2D       ");
    // testMenu->RegisterTest<test::TestKeyInput>          (" Key Input        ");
    // testMenu->RegisterTest<test::TestGrid>              (" Grid             ");
    // testMenu->RegisterTest<test::TestColorAssign>       (" Color assign     ");
    // testMenu->RegisterTest<test::TestMVP>               (" MVP              ");
    // testMenu->RegisterTest<test::TestPerspectiveView>   (" Perspective view - TODO  ");


    // testMenu->RegisterTest<test::TestMousePosition>     (" Mouse Position   - TODO  ");
    // testMenu->RegisterTest<test::TestCellSelection>     (" Cell selection   - TODO  ");
    // testMenu->RegisterTest<test::TestAddingElement>     (" Adding Elements  - TODO  ");





    /* Main if loop */
 

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
            currentTest-> OnRender( window, &frameBufferWidth, &frameBufferHeight);

            /* ImGui UI */
            ImGui::Begin("Test");
            if ( currentTest != testMenu && ImGui::Button ("<-") )
            {
                delete currentTest; 
                currentTest = testMenu; 

            }
            currentTest->OnImGuiRender();
            ImGui::End();


        }

    
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());        
        
    

        updateInput(window);//ovo ti je funkcija za tastaturu koja pravi core dumped.
        // Nastaje zato sto zatvoris prozor a ostane neizbrisan delta time u imguiu. Mora ovdje jer prima window kontekst. Dolje ne moze jer nema konteksta.
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

