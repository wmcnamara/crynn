#pragma once
#include <set>
#include "Material.h"
#include "../CrynnObject.h"
#include "RenderConfig.h"

namespace crynn 
{
	class Renderer;

	//The base class for any type that needs to make render calls.
	class Renderable : public CrynnObject
	{
	public:
		virtual ~Renderable() = default;

		const Material& GetMaterial();
		//void SetMaterial(Material& material);

		//This function is called by the renderer when it will be drawn to the screen.
		//It should contain the raw glDraw functions that performs the render
		virtual void Render() const = 0;

		virtual void AddToRenderLayer() = 0; //Removes this object from its corresponding render layer.
		virtual void RemoveFromRenderLayer() = 0; //Removes this object from its corresponding render layer.
	protected:
		Renderable(Material& material, Renderer& renderer);
		Material& m_material;

		Renderer& m_renderer;
	};

	//Base class for all render layers.
	//A render layer encapsulates information for sorting and rendering specific groups of objects.
	class RenderLayer 
	{
	public:
		RenderLayer() = default;
		virtual ~RenderLayer() = default;

		void Add(Renderable* renderable);
		void Remove(Renderable* renderable);
	protected:
		virtual void DrawRenderLayer() = 0; //Sorts the render layer, and then draws each renderable.
		virtual void SortRenderLayer() = 0; //Sorts the render layer draw order

		std::set<Renderable*> m_renderables;

	private:
		friend class Renderer;
	};

	//Drawn in between skybox and GUI.
	//Reads and writes to depth buffer
	//Sorted based on distance to camera to assist with additive blending.
	class MeshRenderLayer final : public RenderLayer
	{
	public:		
		void DrawRenderLayer() override;

	protected:
		void SortRenderLayer() override;
	};

	//Drawn last, over all other objects.
	//Does not read the depth buffer.
	class GuiRenderLayer : public RenderLayer
	{
	public:
		void DrawRenderLayer() override;

	protected:
		void SortRenderLayer() override;
	};

	//The skybox render layer is drawn first
	//Does not write to the depth buffer.
	class SkyboxRenderLayer final : public RenderLayer
	{
	public:
		void DrawRenderLayer() override;

	protected:
		void SortRenderLayer() override;
	};

	class Renderer : EventListener
	{
	public:
		//Renders each render layer and clears the queue
		void RenderScene();

		void EnableDepthTest();
		void DisableDepthTest();

		void OnRender() override;

		SkyboxRenderLayer& GetSkyboxRenderLayer();
		MeshRenderLayer& GetMeshRenderLayer();
		GuiRenderLayer& GetGuiRenderLayer();
	protected:
		SkyboxRenderLayer m_skyboxRenderLayer;
		MeshRenderLayer m_meshRenderLayer;
		GuiRenderLayer m_guiRenderLayer;

	};
}
