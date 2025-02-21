#include "shader.hpp"


shader::shader(const std::string vertexShaderPath, const std::string fragmentShaderPath) {
    _vertexShaderPath = vertexShaderPath;
    _fragmentShaderPath = fragmentShaderPath;
}

void shader::initShaders(){
    programID = glCreateProgram();
    compileShaders();
    glAttachShader(programID, _vertexID);
    glAttachShader(programID, _fragmentID);
    glLinkProgram(programID);

    int success;
    char infoLog[512];
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    glDeleteShader(_vertexID);
    glDeleteShader(_fragmentID);
}

void shader::compileShaders(){
    int success;
    char infoLog[512];
    compileShader(&_vertexID, GL_VERTEX_SHADER, _vertexShaderPath, &success, infoLog);
    compileShader(&_fragmentID, GL_FRAGMENT_SHADER, _fragmentShaderPath, &success, infoLog);
}

void shader::userShaders(){
    glUseProgram(programID);
}


void shader::compileShader(unsigned int* shaderID, GLenum type, std::string shaderPath, int* success, char* infoLog){
    *shaderID = glCreateShader(type);
    const char* shaderSource = readFile(shaderPath);
    glShaderSource(*shaderID, 1, &shaderSource, NULL);
    glCompileShader(*shaderID);
    glGetShaderiv(*shaderID, GL_COMPILE_STATUS, success);
    if(!(*success)) {
        glGetShaderInfoLog(*shaderID, 512, NULL, infoLog);
        std::cout << shaderPath << std::endl;
    }
}