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
	//ambient
	vec3 ambient = material.ambient * light.ambient;

	//attenuation
	float attenuation = attenuation(fragPos, light.position);

	//diffuse
	vec3 norm = normalize(normal);
	vec3 lightToFragDir = normalize(light.position - fragPos);
	float diff = max(dot(norm, lightToFragDir), 0.0);
	vec3 diffuse = (diff * material.diffuse) * light.diffuse * attenuation;

	//specular
	vec3 viewDir = normalize(cameraPos - fragPos);
	vec3 lightDir = normalize(light.position - fragPos);
	vec3 halfwayDir = normalize(lightDir + viewDir);

	float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
	vec3 specular = (material.specular * spec) * light.specular  * attenuation;

	vec3 result = (ambient + diffuse + specular);

	FragColor = texture(texture_diffuse1, texCoord) * vec4(result, 1.0);
}