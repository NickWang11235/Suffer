#include "util.hpp"


const char* readFile(const std::string filename) {

    std::string vertexCode;
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try 
    {
        shaderFile.open(filename);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();	
        shaderFile.close();
        vertexCode   = shaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    return vertexCode.c_str();
}