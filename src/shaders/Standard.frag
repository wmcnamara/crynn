#version 330 core
out vec4 FragColor;

in vec2 texCoord;
uniform sampler2D tex;
uniform float time;

void main()
{
	FragColor = texture(tex, texCoord);	
	//FragColor = texture(tex, texCoord * tan(time)) * vec4(1, 1, 1, 1);	
}