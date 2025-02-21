#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

const char* readFile(const std::string path);
unsigned int loadShader(const char* path, GLenum type);

#endif