#version 430 core
layout (location = 0) in vec3 pos;

uniform mat4 model;
uniform mat4 trans;

void main()
{
    gl_Position = vec4(pos, 1.0);
}