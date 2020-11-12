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


int main (void)
{

    GLFWwindow* window;

    if (!glfwInit())
        return -1;



    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// GLFW_OPENGL_CORE_PROFILE  GLFW_OPENGL_COMPAT_PROFILE 



    window = glfwCreateWindow(640, 480, "sandbox", NULL, NULL);
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
            -0.5f, -0.5f, 0.0f, 0.0f,//0
             0.5f, -0.5f, 1.0f, 0.0f,//1
             0.5f,  0.5f,1.0f,1.0f, //2
            -0.5f,  0.5f, 0.0f, 1.0f  //3

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


    float r = 0.0f;
    float increment = 0.05f;





    while(!glfwWindowShouldClose(window))
    {

        renderer.Clear();
        shader.Bind();
        shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f );

        renderer.Draw(va, ib, shader);
       

        if ( r > 1.0f)
            increment = -0.05f;
        else if ( r < 0.0f )
            increment = 0.05f;

        r+= increment;



        glfwSwapBuffers(window);
        glfwPollEvents();
    }



    }

    glfwTerminate();
    return 0;

}