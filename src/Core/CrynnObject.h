#pragma once
#include <memory>
#include <unordered_map>
#include "EventListener.h"
#include "Transform.h"

namespace Crynn
{
	class CrynnObject : public EventListener, public Transform
	{
	public:
		CrynnObject();
		int GetID() const { return ID; }
	private:
		int ID = 0;
		static int GenerateID();

		friend class EventListener;
	};
}