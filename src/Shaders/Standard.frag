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

void main()
{	
	vec3 lightPos = vec3(1, 5, 1);
	vec3 lightColor = vec3(1.0, 0.0, 0.0);

	//ambient
	vec3 ambient = material.ambient * lightColor;

	//diffuse
	vec3 norm = normalize(normal);
	vec3 lightToFragDir = normalize(lightPos - fragPos);
	float diff = max(dot(norm, lightToFragDir), 0.0);
	vec3 diffuse = lightColor * (diff * material.diffuse); //red

	//specular
	vec3 viewDir = normalize(cameraPos - fragPos);
	vec3 reflection = reflect(-viewDir, norm);
	float spec = pow(max(dot(viewDir, reflection), 0.0), material.shininess);
	vec3 specular = (material.specular * spec) * lightColor;

	vec3 result = (ambient + diffuse + specular);

	FragColor = texture(texture_diffuse1, texCoord) * vec4(result, 1.0);
}