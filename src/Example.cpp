#include "Crynn.h"
#include <string>
#include "Core/Physics/Rigidbody.h"
#include "Core/Rendering/Light.h"
#include "Utility/Shapes.h"
#include <vector>

using namespace crynn;

q3Body* AddDefaultPlaneCollider()
{
	q3BodyDef bodyDef;
	q3Body* body = Physics::GetScene()->CreateBody(bodyDef);

	q3BoxDef boxDef; // See q3Box.h for settings details
	q3Transform tr; // Contains position and orientation, see q3Transform.h for details
	q3Identity(tr);
	tr.position = Vec3(0, 1, 0);

	// Create a box at the origin with width, height, depth = (1.0, 1.0, 1.0)
	// and add it to a rigid body. The transform is defined relative to the owning body
	boxDef.Set(tr, q3Vec3(100.0, 1.0, 100.0));
	body->AddBox(boxDef);

	return body;
}

int main()
{
	Engine engine(800, 600, "Test");

	engine.SetClearColor(.2f, .2f, .2f, 1.0f);

	Camera cam(Vec3(0, 0, -6), Projection::Perspective);

	Model model("Assets/backpack/backpack.obj");
	Model floor("Assets/floor.fbx");

	Shader shader("Shaders/Standard.vert", "Shaders/Standard.frag");

	LightColorData data;
	data.diffuse = Vec3(0.4, 0, 0);

	PointLight light(data, 30.0f);
	light.SetPosition(Vec3(-2, 3, 1));

	MaterialData matData;
	matData.ambient = Vec3(0.2);
	matData.diffuse = Vec3(1.2);
	matData.specular = Vec3(0.3);
	matData.shininess = 16;

	Material mat = Material(matData, shader);

	Transform transform;	
	transform.SetPosition(Vec3(2.0f, 2.0f, 2.0f));
	transform.Rotate(Vec3(0, 1, 0) * 180.0f);

	Transform floorTransform;
	floorTransform.Scale(Vec3(20.0f, 20.0f, 20.0f));
	floorTransform.Rotate(Vec3(90, 0, 180));
	//floorTransform.Rotate(Vec3(1, 0, 0) * -90.0f);
	
	MeshRenderer renderer(model, mat, transform);
	MeshRenderer renderer2(floor, mat, floorTransform);

	q3Body* body = AddDefaultPlaneCollider();


	float yRot = 0;
#define SPEED 6.0f
#define SENSITIVTY -3.0f
	Application::OnUpdate.AddHandler([&](float dt)
	{
		//light.SetPosition(Vec3(10 * sin(dt), 0, 3 * cos(dt)));

		if (Input::GetKey(KeyCode::W))
		{
			cam.Translate(cam.GetForwardVector() * -SPEED * dt);
		}
		if (Input::GetKey(KeyCode::S))
		{
			cam.Translate(cam.GetForwardVector() * SPEED * dt);
		}

		if (Input::GetKey(KeyCode::D))
		{
			cam.Translate(cam.GetRightVector() * -SPEED * dt);
		}

		if (Input::GetKey(KeyCode::A))
		{
			cam.Translate(cam.GetRightVector() * SPEED * dt);
		}

		if (Input::GetKey(KeyCode::E))
		{
			cam.Translate(cam.GetUpVector() * SPEED * dt);
		}
		static bool locked = false;
		if (Input::GetKeyDown(KeyCode::ESC)) 
		{
			locked = !locked;

			if (locked)
				Input::LockMouse();
			else
				Input::UnlockMouse();

		}
		Vec2 mouse = Input::GetMouseDelta() * dt * SENSITIVTY;
		yRot += mouse.y;	

		cam.Rotate(Vec3(0, 1, 0) * mouse.x);

		Vec3 rot = cam.GetRotationEuler();
		rot.x = yRot;
		cam.SetRotation(rot);

		if (Input::GetKey(KeyCode::Z))
		{
			cam.Translate(cam.GetUpVector() * -SPEED * dt);
		}
	});

	engine.Run();
}