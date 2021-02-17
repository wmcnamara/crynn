#pragma once
#include <vector>
#include <memory>
#include "Transform.h"
#include "CrynnObject.h"

namespace crynn
{
	class SceneNode : CrynnObject, std::enable_shared_from_this<SceneNode>
	{
	public:		
		SceneNode() = default;
		SceneNode(std::shared_ptr<SceneNode> parent) : m_parent(parent) {}
		SceneNode
		(
			std::vector<std::shared_ptr<SceneNode>> children,
			std::shared_ptr<SceneNode> parent
		);

		SceneNode(const SceneNode& other);

		void AddChild(std::shared_ptr<SceneNode> child);
		void ReparentTo(std::shared_ptr<SceneNode> parent);

		CrynnObject& GetCrynnObj() { return *reinterpret_cast<CrynnObject*>(this); }

		bool operator==(std::shared_ptr<SceneNode> other) { return GetCrynnObj() == other->GetCrynnObj(); }
	private:
		std::vector<std::shared_ptr<SceneNode>> m_children;
		std::shared_ptr<SceneNode> m_parent = nullptr;
	};

	class SceneGraph
	{
	public:
		SceneGraph() {}

		SceneGraph(const SceneGraph& other) = delete;
		SceneGraph(const SceneGraph&& other) = delete;

		inline std::shared_ptr<SceneNode> GetHead() { return m_head; }
	private:
		std::shared_ptr<SceneNode> m_head = std::make_shared<SceneNode>();
	};

	class Scene
	{
	public:
		///Creates an empty scene node object
		static std::shared_ptr<SceneNode> MkNode() { return std::make_shared<SceneNode>(graph.GetHead()); }
		static inline SceneGraph graph = SceneGraph();
	};
};