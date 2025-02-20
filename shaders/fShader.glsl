#version 330 core
in vec3 position;
out vec4 FragColor;


void main()
{   
    //FragColor = vec4(sin(position.x)/2+0.5f, sin(position.y)/2+0.5f, sin(position.z)/2+0.5f, 1);
    FragColor = vec4(position.x+0.5, position.y+0.5, position.y+0.5, 1.0f);
} 