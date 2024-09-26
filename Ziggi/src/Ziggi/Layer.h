#pragma once

#include "Ziggi/Core.h"
#include "Ziggi/Events/Event.h"

namespace Ziggi {

	class ZIGGI_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void UnAttach(){}
		virtual void UnDetach(){}
		virtual void OnUpdate(){}
		virtual void OnEvent(Event& event){}

		inline const std::string& Getname()const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}