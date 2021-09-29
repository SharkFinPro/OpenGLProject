#version 330 core
out vec4 FragColor;

uniform float greenColor;

void main()
{
    FragColor = vec4(0.0, greenColor, 0.5, 1.0);
}