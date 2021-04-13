#pragma once
#include "Physics.h"

namespace crynn
{
	using RigidbodyDef = q3BodyDef;
	using BoxDef = q3BoxDef;

	class Rigidbody
	{
	public:
		//Constructs a rigidbody. The transform paramater should be the transform of the object you're simulating. It also acts as default values.
		Rigidbody(q3BodyType bodyT, Transform& transform);
 		virtual ~Rigidbody();

		//Adds a box collider to the rigidbody.
		//Offset is a positional offset from the center of the rigidbody. This is not in worldspace, it is local to the rigidbody, and likely the object.
		//Extents is the length width and height of the box
		//Rotation is the rotation matrix you would like to set as the default rotation.
		void AddBox(Vec3 offset, Vec3 extents, Mat3 rotation = Mat3(1.0f));

		//Updates the current rigidbody transform data into the tracked transform
		void UpdateTransformData();
	private:
		unsigned int eventID = 0;
		q3Body* body;
		Transform& m_transform;
	};
}