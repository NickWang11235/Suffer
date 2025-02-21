#ifndef  _SHADER_HPP_
#define _SHADER_HPP_

#include <glad/glad.h>
#include <iostream>
#include <string>
#include "util.hpp"

class shader{
public:
    unsigned int programID;
    shader(const std::string vertexShaderPath, const std::string fragmentShaderPath);
    void initShaders();
    void compileShaders();
    void userShaders();
    void setVec3f(char* name, float x, float y, float z);

private:
    unsigned int _vertexID;
    unsigned int _fragmentID;
    std::string _vertexShaderPath;
    std::string _fragmentShaderPath;
    void compileShader(unsigned int* shaderID, GLenum type, std::string shaderPath, int* success, char* infoLog);
};

#endif 