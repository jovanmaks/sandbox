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


    float positions[6] = {
            -0.5f, -0.5f,
             0.0f,  0.5f,
             0.5f, -0.5f

    };


    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); 







    while(!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawElements(GL_TRIANGLES, 3, nullptr)



        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}