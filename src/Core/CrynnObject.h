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
		CrynnObject(const CrynnObject& other);
		CrynnObject& operator=(const CrynnObject& other);

		Transform& GetTransform() { return *reinterpret_cast<Transform*>(this); }
		inline bool operator== (CrynnObject& other);

		int GetID() const { return ID; }

		friend class Scene;
	private:
		int ID = 0;
		void* operator new(size_t size);
		void operator delete(void* obj);

		static int GenerateID();
	};
}