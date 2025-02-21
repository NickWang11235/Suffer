#version 330 core
out vec4 FragColor;
in vec3 color;


void main()
{   
    // FragColor = vec4(sin(position.x)/2+0.5f, sin(position.y)/2+0.5f, sin(position.z)/2+0.5f, 1);
    FragColor = vec4(color, 1.0f);
}