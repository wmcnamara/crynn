#include "Crynn.h"
#include <string>
#include "Core/Physics/Rigidbody.h"
#include "Core/Rendering/Light.h"
#include "Utility/Shapes.h"
#include <vector>

using namespace crynn;

int main()
{
	Engine engine(800, 600, "Test");

	engine.SetClearColor(.2f, .2f, .2f, 1.0f);

	Camera cam(Vec3(0, 0, -6), Projection::Perspective);
	cam.SetPosition(Vec3(0, 2, 5));

	LightColorData data;
	data.diffuse = Vec3(0.4, 0, 0);

	PointLight light(data, 30.0f);
	light.SetAttenuationRange(20.0f);
	light.SetIntensity(10.0f);
	light.SetPosition(Vec3(-8, 20, 7));

	Shader shader("Shaders/Standard.shader");

	MaterialData matData;
	matData.ambient = Vec3(0.2);
	matData.diffuse = Vec3(1.2);
	matData.specular = Vec3(0.3);
	matData.shininess = 16;

	Material mat = Material(matData, shader);

	Model model("Assets/floor.fbx");

	Transform tr;
	tr.Rotate(Vec3(1.0f, 0.0f, 0.0f) * 90.0f);
	tr.SetScale(Vec3(5.0f));

	float yRot = 0;
	const float defaultSpeed = 6.0f;
	const float fastSpeed = 12.0f;

	MeshRenderer renderer(model, mat, tr);
	const float sensitivity = -3.0f;
	Application::OnUpdate.AddHandler([&](float dt)
		{
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
			Vec2 mouse = Input::GetMouseDelta() * dt * sensitivity;
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