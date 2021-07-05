/*
	This is the Crynn standard shader.
	It is a simple, fast blinn phong implemtation that should make it easier to get up and running with crynn.
*/

@VERTEXSTART
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;

uniform mat4 model;
uniform mat3 normalMatrix;

layout(std140) uniform Matrices
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
@VERTEXEND

@FRAGMENTSTART

#version 330 core

#define LIGHT_POINT 0 
#define LIGHT_DIRECTIONAL 1

out vec4 FragColor;

in vec2 texCoord;
in vec3 fragPos;
in vec3 normal;

uniform sampler2D texture_diffuse1;
uniform float time;
uniform vec3 cameraPos;
uniform bool sceneHasLights;

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

uniform Material material;

struct Light
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float intensity;

	int type;

	vec3 direction; //directional light
	float pointLightDistance; //point light
};

uniform Light light;

//equation adapted from: https://wiki.ogre3d.org/Light+Attenuation+Shortcut
float attenuation(vec3 fragPos, vec3 lightPos, float pointDist)
{
	float kC = 1.0f;
	float kL = 4.5f / pointDist;
	float kQ = 75.0f / (pointDist * pointDist);

	float lightToFragDist = length(fragPos - lightPos);
	float distSqr = lightToFragDist * lightToFragDist;

	float fAtt = 1.0 / (kC + kL * lightToFragDist + kQ * lightToFragDist);
	return fAtt;
}

void main()
{
	vec3 surfNorm = normalize(normal); //surface normal

	vec3 lightDir = vec3(0); //direction of fragment to light

	if (light.type == LIGHT_DIRECTIONAL)
		lightDir = -light.direction;

	else if (light.type == LIGHT_POINT)
		lightDir = normalize(light.position - fragPos);


	//ambient
	vec3 ambient = material.ambient;

	//diffuse
	float diff = max(dot(surfNorm, lightDir), 0.0);
	vec3 diffuse = (diff * material.diffuse);

	//specular
	vec3 viewDir = normalize(cameraPos - fragPos);
	vec3 halfwayDir = normalize(lightDir + viewDir);

	float spec = pow(max(dot(surfNorm, halfwayDir), 0.1), material.shininess);
	vec3 specular = (material.specular * spec);

	//Apply attenuation if its a point light
	if (light.type == LIGHT_POINT && sceneHasLights)
	{
		//Apply point light attenuation
		float attenuation = attenuation(fragPos, light.position, light.pointLightDistance);
		diffuse *= attenuation;
		specular *= attenuation;
	}

	if (sceneHasLights)
	{
		//Apply light colors
		ambient *= light.ambient;
		diffuse *= light.diffuse * light.intensity;
		specular *= light.specular * light.intensity;
	}

	vec3 result = (ambient + diffuse + specular);

	FragColor = texture(texture_diffuse1, texCoord) * vec4(result, 1.0);
}

@FRAGMENTEND