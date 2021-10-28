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

		Box(Vec3 _pos, Vec3 _extents, Mat3 _defaultRot = Mat3(1.0f)) : 
			position(_pos), 
			extents(_extents), 
			defaultRotation(_defaultRot) {}
	};

	class Engine;

	class Rigidbody
	{
	public:
		//Constructs a rigidbody. The transform paramater should be the transform of the object you're simulating. It also acts as default values.
		//defaultBox is the default collision object.
		Rigidbody(q3BodyType bodyT, Transform& transform, Box defaultBox, std::shared_ptr<Engine> engine);
 		virtual ~Rigidbody();

		//Adds a box collider to the rigidbody.
		//Offset is a positional offset from the center of the rigidbody. This is not in worldspace, it is local to the rigidbody, and likely the object.
		//Extents is the length width and height of the box
		//Rotation is the rotation matrix you would like to set as the default rotation.
		void AddBox(const Box& box);

		//Updates the current rigidbody transform data into the tracked transform
		void UpdateTransformData();

		//Adds a force to the rigidbody in the direction forceVector.
		//The vector should represent a world space direction
		//forceVector is not a unit vector. To apply a larger force, simply multiply the vector by a larger number before passing it.
		//Example: AddForce(someVector * 10);
		void AddForceWorld(Vec3 worldForceVector);

	
	private:
		unsigned int m_eventID = 0;

		q3Body* m_body;
		Transform& m_transform;

		std::shared_ptr<Engine> m_engine;
	};
}