#version 430 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 textureCord;
layout (location = 2) in vec3 surfaceNormal;

out vec3 fragPos;

void main()
{
    fragPos = vec3(vec4(pos, 1.0));
    vec4(pos, 1.0);
}