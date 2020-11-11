#pragma once

#include <GL/glew.h>

//for raise(SIGTRAP) function in gcc - instead of __debugbreak()
#include <signal.h>




#define ASSERT(x) if (!(x)) raise(SIGTRAP);
#define GLCall(x)   GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))




 void GLClearError();



bool GLLogCall(const char* function, const char* file, int line);
