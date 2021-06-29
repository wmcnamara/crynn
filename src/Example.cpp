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
	cam.SetPosition(Vec3(0, 2, 0));

	LightColorData data;
	data.diffuse = Vec3(0.4, 0, 0);

	PointLight light(data, 30.0f);
	light.SetAttenuationRange(20.0f);
	light.intensity = 10.0f;
	light.SetPosition(Vec3(-8, 20, 7));

	Shader shader("Shaders/Standard.vert", "Shaders/Standard.frag");

	MaterialData matData;
	matData.ambient = Vec3(0.2);
	matData.diffuse = Vec3(1.2);
	matData.specular = Vec3(0.3);
	matData.shininess = 16;

	Material mat = Material(matData, shader);

	Model model("Assets/backpack/backpack.obj");

	/*
	std::shared_ptr<TestGUI> gui = std::make_shared<TestGUI>();
	std::shared_ptr<TestMesh> mesh = std::make_shared<TestMesh>();
	std::shared_ptr<TestSkybox> box = std::make_shared<TestSkybox>();

	Renderer::AddToRenderList(gui);
	Renderer::AddToRenderList(mesh);
	Renderer::AddToRenderList(box);

	Renderer::Render();
	*/

	Transform tr;
	tr.SetScale(Vec3(0.5f, 0.5f, 0.5f));
	tr.Rotate(Vec3(1, 0, 0)  * -90.0f);

	float yRot = 0;
	const float defaultSpeed = 6.0f;
	const float fastSpeed = 12.0f;

#define SENSITIVTY -3.0f
	Application::OnUpdate.AddHandler([&](float dt)
		{
			//light.SetPosition(Vec3(10 * sin(dt), 0, 3 * cos(dt)));

			const float SPEED = Input::GetKey(KeyCode::LSHIFT) ? fastSpeed : defaultSpeed;

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