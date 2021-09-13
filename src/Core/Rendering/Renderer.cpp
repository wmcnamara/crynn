#include "Renderer.h"
#include "../Camera.h"

namespace crynn
{
	const crynn::Material& Renderable::GetMaterial()
	{
		return m_material;
	}

	Renderable::Renderable(Material& material, Renderer& renderer) : m_material(material), m_renderer(renderer) { std::cout << "Renderer initialised\n"; }

	void Renderer::RenderScene()
	{
		m_skyboxRenderLayer.DrawRenderLayer();
		m_meshRenderLayer.DrawRenderLayer();
		m_guiRenderLayer.DrawRenderLayer();
	}

	void MeshRenderLayer::DrawRenderLayer()
	{
	//	SortRenderLayer();

		glEnable(GL_DEPTH_TEST);

		for (const auto renderable : m_renderables)
			renderable->Render();
	}

	void MeshRenderLayer::SortRenderLayer()
	{
		//Sort based on distance to camera for additive blending
		//This is also called the "Painters algorithm"
		//std::weak_ptr<Camera> camera_ptr = Camera::GetCurrentCamera()->GetPosition();
		//Vec3 cameraPos = Camera::GetCurrentCamera()->GetPosition();

		//	auto CompareRenderableDistance = [&cameraPos](Renderable* a, Renderable* b)
		{
		//	float distToA = glm::distance(cameraPos, a->GetPosition());
		//	float distToB = glm::distance(cameraPos, b->GetPosition());

		//	return distToA < distToB;
		};
		
		//std::sort(m_renderables.begin(), m_renderables.end(), CompareRenderableDistance);
	}

	void SkyboxRenderLayer::DrawRenderLayer()
	{
		glDisable(GL_DEPTH_TEST);

		for (const auto renderable : m_renderables)
			renderable->Render();

		glEnable(GL_DEPTH_TEST);
	}

	void SkyboxRenderLayer::SortRenderLayer()
	{
		//Skybox render layers dont need to be sorted.
	}

	void GuiRenderLayer::DrawRenderLayer()
	{

	}

	void GuiRenderLayer::SortRenderLayer()
	{

	}

	void Renderer::EnableDepthTest()
	{
		glEnable(GL_DEPTH_TEST);
	}

	void Renderer::DisableDepthTest()
	{
		glDisable(GL_DEPTH_TEST);
	}

	void Renderer::OnRender()
	{
		RenderScene();
	}

	SkyboxRenderLayer& Renderer::GetSkyboxRenderLayer()
	{
		return m_skyboxRenderLayer;
	}

	MeshRenderLayer& Renderer::GetMeshRenderLayer()
	{
		return m_meshRenderLayer;
	}

	GuiRenderLayer& Renderer::GetGuiRenderLayer()
	{
		return m_guiRenderLayer;
	}

	void RenderLayer::Add(Renderable* renderable)
	{
		m_renderables.insert(renderable);
	}

	void RenderLayer::Remove(Renderable* renderable)
	{
		m_renderables.erase(renderable);
	}

}