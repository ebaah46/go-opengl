//
//  Shader.h
//  hello gl
//
//  Created by Emmanuel Baah on 11.9.2023.
//

#ifndef Shader_h
#define Shader_h

#include <glad/glad.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

 enum class COMPILATION_TYPE {
    PROGRAM = 0 ,
    VERTEX_SHADER,
    FRAGMENT_SHADER
 };
class Shader{
public:
    unsigned int ID;
    
    Shader(const char* vertexPath, const char* fragmentPath);
    
    void use(); //use/activate the shader
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value)const;
    void setFloat(const std::string &name, float value)const;
private:
    int success;
    char infoLog[GL_INFO_LOG_LENGTH];
    void checkCompileErrors(unsigned int shader,COMPILATION_TYPE type );
};

#endif /* Shader_h */
