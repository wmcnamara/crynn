#pragma once
#include "glad/glad.h"
#include "Shader.h"
#include "../EventListener.h"
#include "../Math/Math.h"


namespace crynn
{
	//Defines the intensities of each shading property
	//It is recommended that you play around with these values.
	struct MaterialData 
	{
		Vec3 ambient;
		Vec3 diffuse;
		Vec3 specular;
		float shininess = 32;
	};

	/// <summary>
	/// A material wraps rendering settings in a simple to use data structure.
	/// It contains a shader, and a set of configurable rendering options.
	/// 
	/// To access data from this class inside a shader, declare a struct called Materials, with the 
	/// 
	/// ambient
	/// diffuse
	/// specular
	/// shininess
	/// members as seen in this class. Then create a uniform instance of this called material.
	/// 
	/// uniform Material material;
	/// 
	/// The variables will be set by this class.
	/// An example can be found in the Shaders/Standard.frag file
	/// </summary>
	class Material
	{
	public:
		//Constructs a material with the desired MaterialData and shader.
		//Rendering materials will set uniforms in the shader you pass here.
		Material(MaterialData data, const Shader& shader);
		~Material() = default;

		MaterialData properties;

	private:
		//Binds m_shader and sets the uniforms for MaterialData.
		//This should be called just before rendering the object.
		void SetUniforms() const;

		const Shader& m_shader;
		friend class MeshRenderer;
	};
}