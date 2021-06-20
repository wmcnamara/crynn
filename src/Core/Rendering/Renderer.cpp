#include "Renderer.h"

void Renderer::AddToRenderQueue(const std::shared_ptr<Renderable> renderable)
{
	m_renderQueue.push(renderable);
}

void Renderer::Render()
{
	while (!m_renderQueue.empty()) 
	{
		m_renderQueue.top()->Render();
		m_renderQueue.pop();
	}
}

Renderable::Renderable(RenderPriority priority) : m_renderPriority(priority) { }

bool Renderable::operator<(const Renderable& other)
{
	int thisRenderPriority = std::underlying_type<RenderPriority>::type(m_renderPriority);
	int otherRenderPriority = std::underlying_type<RenderPriority>::type(other.m_renderPriority);

	return thisRenderPriority > otherRenderPriority;
}				  

bool Renderable::operator>(const Renderable& other)
{
	int thisRenderPriority = std::underlying_type<RenderPriority>::type(m_renderPriority);
	int otherRenderPriority = std::underlying_type<RenderPriority>::type(other.m_renderPriority);

	return thisRenderPriority < otherRenderPriority;
}
