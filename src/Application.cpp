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

    float positions[] = {
           -50.0f,-50.0f, 0.0f, 0.0f, //0
            50.0f, -50.0f, 1.0f, 0.0f, //1
            50.0f,  50.0f, 1.0f, 1.0f, //2
           -50.0f, 50.0f, 0.0f,1.0f  //3

    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };


    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)  );


    VertexArray va;
    VertexBuffer vb(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);

    va.AddBuffer(vb, layout);

    IndexBuffer ib(indices, 6);


    glm::mat4 proj  = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    glm::mat4 view  = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));



    Shader shader("../res/shaders/Basic.shader");
    shader.Bind();

    shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f );

    Texture texture("../res/texture/arabeska.png");
    texture.Bind();
    shader.SetUniform1i("u_Texture", 0);



    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

    Renderer renderer;



    /* Setup Dear ImGui context */     
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io; 
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();
    
    //flags for trigerring imGui 
    bool show_demo_window = true;
    bool show_another_window = true;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    glm::vec3 translationA(100, 0, 0);
    glm::vec3 translationB(400, 0, 0);



    float r = 0.0f;
    float increment = 0.05f;



    float g = 0.0f;
    float b = 0.5f;

    bool on = true;

    while(!glfwWindowShouldClose(window))
    {

        renderer.Clear();


        ImGui_ImplGlfw_NewFrame();  
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();


        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f),translationA );
            glm::mat4 mvp = proj * view * model;
            shader.Bind();
            shader.SetUniformMat4f("u_MVP", mvp);
            renderer.Draw(va, ib, shader);      
        }


        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f),translationB );
            glm::mat4 mvp = proj * view * model;
            shader.Bind();
            shader.SetUniformMat4f("u_MVP", mvp);
            renderer.Draw(va, ib, shader);      
        }

        
       

        if ( r > 1.0f)
            increment = -0.05f;
        else if ( r < 0.0f )
            increment = 0.05f;

        r+= increment;


        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            ImGui::Text("Vertex position");
            if (ImGui::Button("Show"))
                on == true;
          
            ImGui::Separator();
            ImGui::SliderFloat("color  r", &r, 0.0f, 1.0f);
            ImGui::SliderFloat3("translationA", &translationA.x, 0.0f, 960.0f);
            ImGui::SliderFloat3("translationB", &translationB.x, 0.0f, 960.0f);

           
            ImGui::End();
        }

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