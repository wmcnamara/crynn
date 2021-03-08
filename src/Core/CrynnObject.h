#pragma once
#include <memory>
#include <unordered_map>
#include <atomic>
#include "EventListener.h"
#include "Transform.h"

namespace crynn
{
	using OBJID = uint64_t;

	class CrynnObject : public EventListener, public Transform
	{
	public:
		CrynnObject();
		virtual ~CrynnObject() = default;

		CrynnObject(const CrynnObject& other);

		Transform& GetTransform() { return *reinterpret_cast<Transform*>(this); }
		inline bool operator== (CrynnObject& other) const { return ID == other.ID; }

		OBJID GetID() { return ID; }

		friend class Scene;
	private:
		OBJID ID = 0;
		static OBJID GenerateID();
	};
}