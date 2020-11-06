#include <iostream>
/* OpenGl */
#include <GL/glew.h> 
#include <GLFW/glfw3.h>

int main (void)
{

    GLFWwindow* window;

    if (!glfwInit())
        return -1;


    window = glfwCreateWindow(640, 480, "sandbox", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);


    GLenum err1 = glewInit();
    if (GLEW_OK != err1)
    {
    /* Problem: glewInit failed, something is seriously wrong. */
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err1));    
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "Status: Using GL %s\n", glGetString(GL_VERSION));


    while(!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}