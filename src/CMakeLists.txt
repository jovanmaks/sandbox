cmake_minimum_required(VERSION 3.17.4)

project(tests VERSION  0.1)

include( GNUInstallDirs )

set( GLFWM_VERSION_MAJOR "3" )
set( GLFWM_VERSION_MINOR "2" )


find_package( OpenGL REQUIRED )
find_package( glfw3 REQUIRED )

set( SRCS

# ../src/Application.cpp
../src/API.cpp



../src/Renderer.cpp
../src/VertexBuffer.cpp
../src/IndexBuffer.cpp
../src/VertexArray.cpp
../src/Shader.cpp
../src/Texture.cpp
../src/GridMatrix.cpp
../src/Grid.cpp



../src/vendor/stb_image/stb_image.cpp

../src/vendor/imgui/imgui_demo.cpp
../src/vendor/imgui/imgui_draw.cpp
../src/vendor/imgui/imgui_impl_glfw.cpp
../src/vendor/imgui/imgui_impl_opengl3.cpp
../src/vendor/imgui/imgui_widgets.cpp
../src/vendor/imgui/imgui.cpp



../src/tests/Test.cpp
../src/tests/TestClearColor.cpp
../src/tests/TestTexture2D.cpp
../src/tests/TestKeyInput.cpp
../src/tests/TestGrid.cpp
../src/tests/TestMousePosition.cpp
../src/tests/TestColorAssign.cpp
../src/tests/TestCellSelection.cpp
../src/tests/TestPerspectiveView.cpp
../src/tests/TestAddingElement.cpp
../src/tests/TestMVP.cpp

../src/tests/TestAssemblied1.cpp



)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
    
   

target_link_libraries( tests ${../lib} GL )
target_link_libraries( tests ${../lib} GLEW )
target_link_libraries( tests ${../lib} glfw )