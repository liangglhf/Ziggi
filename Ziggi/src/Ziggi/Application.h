#pragma once

#include "Core.h"
#include "Window.h"
#include "Ziggi/LayerStack.h"
#include "Ziggi/Events/Event.h"
#include "Ziggi/Events/ApplicationEvent.h"

namespace Ziggi {
	class ZIGGI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}