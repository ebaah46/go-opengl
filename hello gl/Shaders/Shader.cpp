//
//  Shader.cpp
//  hello gl
//
//  Created by Emmanuel Baah on 13.9.2023.
//

#include "Shader.h"

Shader::Shader(const char* vertexShaderpath, const char* fragmentShaderPath) {
    const char* vertexCode;
    const char* fragmentCode;
    // File stream for shader source code files
    std::ifstream vShaderFile, fShaderFile;
    // Ensure ifstream can throw exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    
    try {
        vShaderFile.open(vertexShaderpath);
        fShaderFile.open(fragmentShaderPath);
        std::stringstream vShaderStream,fShaderStream;
        // Read shader source from file
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        
        vShaderFile.close();
        fShaderFile.close();
        // Copy shader program as string
        vertexCode = vShaderStream.str().c_str();
        fragmentCode = fShaderStream.str().c_str();
        
    } catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    // Create shader objects
    unsigned int vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Get shader source
    glShaderSource(vertexShader,1, &vertexCode, NULL);
    // Compile shader source
    glCompileShader(vertexShader);
    // Get shader compilation status
    checkCompileErrors(vertexShader, COMPILATION_TYPE::VERTEX_SHADER);
    
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
    glCompileShader(fragmentShader);
    
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS, &success);
    
    checkCompileErrors(fragmentShader, COMPILATION_TYPE::FRAGMENT_SHADER);
    // Create shader program
    ID = glCreateProgram();
    // Attach shaders to program
    glAttachShader(ID,vertexShader);
    glAttachShader(ID,fragmentShader);
    // Link program
    glLinkProgram(ID);
    
    // Check program link status
    checkCompileErrors(ID, COMPILATION_TYPE::PROGRAM);

    // Delete shaders after linking them to the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use(){
    glUseProgram(ID);
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::checkCompileErrors(unsigned int shader, COMPILATION_TYPE type){
    if(type == COMPILATION_TYPE::PROGRAM){
        glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &success);
        if(!success){
            glGetProgramInfoLog(shader,GL_INFO_LOG_LENGTH, NULL, infoLog);
            std::cout<<"ERROR::PROGRAM_LINKING::FAILED"<< infoLog <<std::endl;
        }
    } else {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &success);
        if (!success) {
            glGetShaderInfoLog(shader,GL_INFO_LOG_LENGTH,NULL,infoLog);
            std::cout << "ERROR::SHADER::COMPILE::FAILED\n COMPILATION_TYPE: "<< static_cast<int>(type)<<" ERROR: "<<infoLog << std::endl;
        }
    }
}
