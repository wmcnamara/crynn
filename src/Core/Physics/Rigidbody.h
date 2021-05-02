#pragma once
#include "Physics.h"
#include <vector>

namespace crynn
{
	using RigidbodyDef = q3BodyDef;
	using BoxDef = q3BoxDef;

	/*
		Represents an oriented bounding box for a rigidbody.
	*/
	struct Box 
	{
		Vec3 position = Vec3(0, 0, 0); //Offset relative to rigidbody. NOT relative to world. This should generally be Vec3(0, 0, 0) to have it centered on your object.
		Vec3 extents = Vec3(1, 1, 1); //XYZ size of the bounding box.
		Mat3 defaultRotation = Mat3(1.0f); //identity matrix
	};

	class Rigidbody
	{
	public:
		//Constructs a rigidbody. The transform paramater should be the transform of the object you're simulating. It also acts as default values.
		//defaultBox is the default collision object.
		Rigidbody(q3BodyType bodyT, Transform& transform, const Box& defaultBox);
 		virtual ~Rigidbody();

		//Adds a box collider to the rigidbody.
		//Offset is a positional offset from the center of the rigidbody. This is not in worldspace, it is local to the rigidbody, and likely the object.
		//Extents is the length width and height of the box
		//Rotation is the rotation matrix you would like to set as the default rotation.
		void AddBox(const Box& box);

		//Updates the current rigidbody transform data into the tracked transform
		void UpdateTransformData();
	private:
		unsigned int eventID = 0;

		q3Body* body;
		Transform& m_transform;
	};
}