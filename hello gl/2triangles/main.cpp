//
//  main.cpp
//  2triangles
//
//  Created by Emmanuel Baah on 10.9.2023.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}



int main(int argc, const char * argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "@ Triangles", NULL, NULL);
    if (window == NULL){
        std::cout<< "Failed to create GLFW window"<< std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"Failed to initialize GLAD"<<std::endl;
        return  -1;
    }
    
    glViewport(0,0,800,600);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // Build and compile shader program
    Shader customShader("vertex.vs","fragment.fs");
    
    float vertices1[] = {
        -0.9f, -0.5f, 0.0f,  // top right
        -0.0f, -0.5f, 0.0f,  // bottom right
        -0.45f, 0.5f, 0.0f,  // bottom left
    };
    float vertices2[] = {
        0.0f, -0.5f, 0.0f,  // top right
        0.9f, -0.5f, 0.0f,  // bottom right
        0.45f, 0.5f, 0.0f,  // bottom left
    };
    
    unsigned int VAOs[2], VBOs[2];
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);
    
    // create bindings
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)){
        // process input
        processInput(window);
        
        // render commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
//        glUseProgram(shaderProgram);
        customShader.use();
        
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        
//        customShader.setFloat(const std::string &name, float value);
//        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f,1.0f);
        
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0,3);
        
        
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0,3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // clean-up
    std::cout<<"Freeing resources....."<<std::endl;
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2,VBOs);
    
    glfwTerminate();
    
    return 0;
}
