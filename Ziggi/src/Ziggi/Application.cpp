#include "zgpch.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Ziggi {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window -> SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		ZG_CORE_TRACE("{0}",e);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.8f, 0.3f, 0.4f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}