#pragma once
#include <memory>
#include <unordered_map>
#include "EventListener.h"
#include "Transform.h"

namespace crynn
{
	class CrynnObject : public EventListener, public Transform
	{
	public:
		CrynnObject();
		virtual ~CrynnObject() = default;

		CrynnObject(const CrynnObject& other);
		CrynnObject& operator=(const CrynnObject& other);

		Transform& GetTransform() { return *reinterpret_cast<Transform*>(this); }
		inline bool operator== (CrynnObject& other) const { return ID == other.ID; }

		int& GetID() { return ID; }

		friend class Scene;
	private:
		int ID = 0;
		static int GenerateID();
	};
}