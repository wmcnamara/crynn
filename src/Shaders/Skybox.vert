#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 texCoord;

uniform mat4 model;

layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

void main () 
{
	texCoord = aTexCoord;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}