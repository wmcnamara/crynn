#pragma once
#include <queue>
#include <memory>

enum struct RenderPriority 
{
	Skybox = 0, //Rendered first
	Mesh = 1, //Rendered second. Most common.
	GUI = 2 //Rendered last on top of everything else
};

//The base class for any type that needs to make render calls.
class Renderable : std::enable_shared_from_this<Renderable>
{
public:
	Renderable(RenderPriority priority);

	bool operator < (const Renderable& other);
	bool operator > (const Renderable& other);

protected:
	//This function is called by the renderer when it will be drawn to the screen.
	//You must override this and provide a render implementation. 
	//It should contain the raw glDraw function that performs the render
	virtual void Render() const = 0;

private:
	RenderPriority m_renderPriority = RenderPriority::Mesh;

	friend class Renderer;
};

class Renderer
{
public:
	void AddToRenderQueue(const std::shared_ptr<Renderable> renderable);

protected:
	//Renders every object in the render queue and clears the queue
	void Render();

	std::priority_queue<std::shared_ptr<Renderable>> m_renderQueue;
};