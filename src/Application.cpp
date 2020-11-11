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



struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};



static ShaderProgramSource ParseShader(const std::string& filepath)
{
   std::ifstream stream(filepath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while(getline(stream, line))
    {
        if (line.find("#shader") !=std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if(line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int) type] << line << '\n'; 
        }
    }

    return { ss[0].str(), ss[1].str() };

}


static unsigned int CompileShader(  unsigned int type, const std::string& source )
{
    unsigned int id = glCreateShader( type );
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    //== error handling ==
    int result;
    glGetShaderiv(id,   GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int lenght;
        glGetShaderiv( id, GL_INFO_LOG_LENGTH, &lenght);
        char* message = (char*) alloca(lenght * sizeof(char));
        glGetShaderInfoLog (id, lenght, &lenght, message);
        std::cout<< "Failed to compile "<<(type == GL_VERTEX_SHADER ? "vertex" : "fragment" ) << "shader!" << std::endl;
        std::cout << message <<std::endl;
        glDeleteShader(id);
        return 0;  
    }
    //== error handling ==
    

    return id;
}




static int unsigned CreateShader( const std::string& vertexShader, const std::string& fragmentShader )
{
    GLCall(unsigned int program = glCreateProgram());

    unsigned int vs = CompileShader ( GL_VERTEX_SHADER, vertexShader );
    unsigned int fs = CompileShader ( GL_FRAGMENT_SHADER, fragmentShader );

    glAttachShader    ( program, vs );
    glAttachShader    ( program, fs );
    glLinkProgram     ( program );
    glValidateProgram ( program );

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}







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
            -0.5f, -0.5f, //0
             0.5f, -0.5f, //1
             0.5f,  0.5f, //2
            -0.5f,  0.5f  //3

    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };


    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));


    VertexArray va;
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);

    IndexBuffer ib(indices, 6);



    ShaderProgramSource source = ParseShader("../res/shaders/Basic.shader");
    unsigned int shader = CreateShader(source.VertexSource,  source.FragmentSource);
    GLCall(glUseProgram(shader));   




    GLCall( int location = glGetUniformLocation(shader, "u_Color") );
    ASSERT(location != -1);

    GLCall( glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f) );  

    GLCall(glBindVertexArray(0));
    GLCall(glUseProgram(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));



    float r = 0.0f;
    float increment = 0.05f;





    while(!glfwWindowShouldClose(window))
    {

        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        GLCall(glUseProgram(shader));
        GLCall( glUniform4f(location, r, 0.3f, 0.8f, 1.0f) );          

        va.Bind();
        ib.Bind();

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));



        if ( r > 1.0f)
            increment = -0.05f;
        else if ( r < 0.0f )
            increment = 0.05f;

        r+= increment;



        glfwSwapBuffers(window);
        glfwPollEvents();
    }





    glDeleteProgram(shader);

    }

    glfwTerminate();
    return 0;

}