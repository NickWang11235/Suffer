#ifndef _UTIL_
#define _UTIL_


#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>

char* readFile(const char* path);
unsigned int loadShader(const char* path, GLenum type);

#endif