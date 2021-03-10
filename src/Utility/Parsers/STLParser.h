#pragma once
#include "../IO.h"
#include "../../Core/Math/Vec3.h"
#include "../../Core/Mesh.h"
namespace crynn
{
	/// <summary>
	/// Encapsulates vertices and normals loaded from an STL file.
	/// </summary>
	class STLData
	{
	public:
		//Returns a boolean indicating if this STLData object contains no data.
		bool Empty() const { return vertices.empty() && normals.empty(); }

		size_t VertexCount() { return vertices.size(); }
		size_t NormalCount() { return normals.size(); }

		//Returns the vertices in an OpenGL supported format.
		//This function is relatively slow and should only be called when constructing objects.
		GLfloat* GetVertices() { return vertices.data(); }

		std::vector<float> vertices;
		std::vector<float> normals;
	};

	/// <summary>
	/// A class providing static functions to assist with loading Stereolithography files (STL)
	/// </summary>
	class STLParser
	{
	public:
		static std::shared_ptr<STLData> Load(const char* path);
	};
}