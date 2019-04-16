#version 430 core

in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * vec3(1, 1, 1);

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(vec3(0, 1, 0) - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(1, 1, 1);

    vec3 result = (ambient + diffuse) * vec3(1, 1, 0);
    FragColor = vec4(result, 1.0);
}