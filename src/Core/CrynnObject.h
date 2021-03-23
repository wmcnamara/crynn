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
		CrynnObject& operator=(const CrynnObject& other);

		CrynnObject(CrynnObject&& other) noexcept;
		CrynnObject& operator=(CrynnObject&& other) noexcept;

		Transform& GetTransform() { return *this; }

		inline bool operator== (CrynnObject& other) const { return ID == other.ID; }
		bool Compare(CrynnObject& other) const { return ID == other.ID; }

		OBJID GetID() { return ID; }

		friend class Scene;
	private:
		OBJID ID = 0;
		static OBJID GenerateID();
	};
}