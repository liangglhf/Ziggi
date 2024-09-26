#pragma once

#include "zgpch.h"

#include "Ziggi/Core.h"
#include "Ziggi/Events/Event.h"

namespace Ziggi {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string title = "Ziggi Engine",
					unsigned int width=1280,
					unsigned int height=720)
			: Title(title), Width(width), Height(height){}
	};

	// Interface representing a desktop system based Window
	class ZIGGI_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window sttributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}