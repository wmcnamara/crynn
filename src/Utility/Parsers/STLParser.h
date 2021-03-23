#pragma once
#include "../Defines.h"
#include "../IO.h"

namespace crynn
{
	/// <summary>
	/// Encapsulates vertices and normals loaded from an STL file.
	/// </summary>
	class STLData
	{
	public:
		//Returns a boolean indicating if this STLData object contains no data.
		NODISCARD bool Empty() const { return vertices.empty() && normals.empty(); }

		//Returns the number of vertex elements loaded from the model. 
		NODISCARD size_t VertexCount() const { return vertices.size(); }

		//Returns the number of normal vector elements loaded from the model.
		NODISCARD size_t NormalCount() const { return normals.size(); }

		//Returns the vertices in an OpenGL supported format.
		NODISCARD GLfloat* GetVertices() { return vertices.data(); }

		//Returns the normals in an OpenGL supported format.
		NODISCARD GLfloat* GetNormals() { return normals.data(); }
		
		/*
		//Computes an array that can be passed to a mesh with the vertices and normals aligned correctly.
		//Combines vertices and normals together

		//Data is aligned as such:
		//vertex x, y, z, normal x, y, z, etc.
		//Example vertex memory layout: 1.0f, 2.0f, 1.0f, 0.5f, 0.5f, 0.5f, 
		//6 floats per vertex
		*/
		[[nodiscard("This function returns an std::vector with the data. Do not discard the return value.")]]
		std::vector<GLfloat> ComputeGLFormat() const;

		STLData() = default;
		~STLData() = default;

		STLData (const STLData& other) = default;
		STLData& operator=(const STLData& other) = default;

		STLData (STLData&& other) = default;
		STLData& operator=(STLData&& other) = default;
	private:
		std::vector<float> vertices;
		std::vector<float> normals;

		friend class STLParser;
	};

	using STLDataPtr = std::shared_ptr<STLData>;

	/// <summary>
	/// A class providing static functions to assist with loading Stereolithography files (STL)
	/// </summary>
	class STLParser
	{
	public:
		//Loads an ASCII STL file into an STLDataPtr object.
		//WILL NOT LOAD BINARY STL.
		static STLDataPtr Load(const char* path);
	};
}