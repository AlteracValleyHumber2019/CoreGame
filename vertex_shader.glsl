#version 450 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 textureCord;
layout (location = 2) in vec3 surfaceNormal;

out vec2 fsTextureCord;
out vec3 fragPos;
out vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	fsTextureCord = textureCord;
    fragPos = vec3(model * vec4(pos, 1.0));
    normal = mat3(transpose(inverse(model))) * surfaceNormal;  

    gl_Position = projection * view * vec4(fragPos, 1.0);
}