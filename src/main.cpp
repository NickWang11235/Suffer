#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "util/util.hpp"
#include <math.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

bool escPressed = false;
float vertices[] = {
    0.5f,  0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
   -0.5f, -0.5f, 0.0f,
   -0.5f,  0.5f, 0.0f 
};  

unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3 
};  

int main(int argc, const char** argv) {


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    GLint success;
    unsigned int vertexShader = loadShader("shaders/vShader.glsl", GL_VERTEX_SHADER);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        std::cout << "vertex shader compilation failed!!" << std::endl;
    }
    unsigned int fragmentShader = loadShader("shaders/fShader.glsl", GL_FRAGMENT_SHADER); 
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        std::cout << "fragment shader compilation failed!!" << std::endl;
    }

    
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    

    

    unsigned int VBO, VAO, EBO;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


    float time;
    float red, green, blue, alpha;
    
    while (!glfwWindowShouldClose(window))
    {           
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);

        time = glfwGetTime();
        red = (sin(time) / 2) + 0.5;
        green = (sin(time+1) / 2) + 0.5;
        blue = (sin(time+2) / 2) + 0.5;
        alpha = (sin(time+3) / 2) + 0.5;

        // glUniform3f(glGetUniformLocation(shaderProgram, "color"), red, green, blue);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        // glfwSetWindowShouldClose(window, true);
        // std::cout << "ESC Pressed" << std::endl;
        escPressed = true;
    }
    if(escPressed && glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE) {
        escPressed = false;
        glfwSetWindowShouldClose(window, true);
    }
}