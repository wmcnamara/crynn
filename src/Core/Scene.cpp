#include "Scene.h"

namespace crynn 
{
	SceneNode::SceneNode(
		std::vector<std::shared_ptr<SceneNode>> children,
		std::shared_ptr<SceneNode> parent) : m_children(children), m_parent(parent)
	{}

	SceneNode::SceneNode(const SceneNode& other)
	{
		//Copy m_children from other into this object
		for (std::shared_ptr<SceneNode> ptr : other.m_children)
			m_children.push_back(std::make_shared<SceneNode>(*ptr));
		
		m_parent = other.m_parent;
	}

	void SceneNode::AddChild(std::shared_ptr<SceneNode> child)
	{
		child->ReparentTo(std::make_shared<SceneNode>(shared_from_this()));
		m_children.push_back(child);
	}

	void SceneNode::ReparentTo(std::shared_ptr<SceneNode> parent)
	{
		m_parent = parent;
		parent->m_children.push_back(shared_from_this());
	}
}