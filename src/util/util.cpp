#include "util.hpp"


char* readFile(const char* filename) {
    FILE *file = fopen(filename, "rb");

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *buffer = (char*)malloc(file_size + 1);
    size_t bytes_read = fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    
    fclose(file);
    return buffer;
}


unsigned int loadShader(const char* path, GLenum type) {
    unsigned int shader = glCreateShader(type);
    char* source = readFile(path);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int  success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success) {
        return -1;
    }
    return shader;
}