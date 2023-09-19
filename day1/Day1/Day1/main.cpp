//
//  main.cpp
//  Day1
//
//  Created by Emmanuel Baah on 22.8.2023.
//
//#pragma once

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#define GL_SILENCE_DEPRECATION

int main(int argc, const char * argv[]) {
    // insert code here...
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
    
    return 0;
}
