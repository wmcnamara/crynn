#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;

uniform mat4 model;
uniform mat3 normalMatrix;

layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

void main()
{
    fragPos = vec3(model * vec4(aPos, 1.0f));
    normal = normalMatrix * aNormal;
    texCoord = aTexCoords;  
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}