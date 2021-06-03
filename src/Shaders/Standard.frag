/*
	This is the Crynn standard shader.
	It is a simple, fast blinn phong implemtation that should make it easier to get up and running with crynn.
*/

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

	int type;

	vec3 direction; //directional light
};

uniform Light light;  

//adapted from: https://learnopengl.com/Lighting/Light-casters
float attenuation (vec3 fragPos, vec3 lightPos) 
{
	float kC = 1.0f;
	float kL = 0.7f;
	float kQ = 1.8f;

	float dist = length(fragPos - lightPos);
	float distSqr = dist * dist;

	float fAtt = 1.0 / (kC + kL * dist + kQ * distSqr);
	return fAtt;
}

void main()
{
	vec3 surfNorm = normalize(normal); //surface normal

	vec3 lightDir = vec3(0); //direction of fragment to light

	if (light.type == LIGHT_DIRECTIONAL) 
		-light.direction;
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
		float attenuation = attenuation(fragPos, light.position);
		diffuse *= attenuation;
		specular *= attenuation;

		//Apply light colors
		ambient *= light.ambient;
		diffuse *= light.diffuse;
		specular *= light.specular;
	}

	vec3 result = (ambient + diffuse + specular);

	FragColor = texture(texture_diffuse1, texCoord) * vec4(result, 1.0);
}