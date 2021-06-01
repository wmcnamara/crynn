#version 330 core
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
};

uniform Light light;  

void main()
{	
	//ambient
	vec3 ambient = material.ambient * light.ambient;

	//diffuse
	vec3 norm = normalize(normal);
	vec3 lightToFragDir = normalize(light.position - fragPos);
	float diff = max(dot(norm, lightToFragDir), 0.0);
	vec3 diffuse = light.diffuse * (diff * material.diffuse); //red

	//specular
	vec3 viewDir = normalize(cameraPos - fragPos);
	vec3 reflection = reflect(-viewDir, norm);
	vec3 lightDir = normalize(light.position - fragPos);

	vec3 halfwayDir = normalize(lightDir + viewDir);

	float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
	vec3 specular = (material.specular * spec) * light.specular;

	vec3 result = (ambient + diffuse + specular);

	FragColor = texture(texture_diffuse1, texCoord) * vec4(result, 1.0);
}