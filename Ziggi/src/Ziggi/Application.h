#pragma once

#include"Core.h"

namespace Ziggi {
	class ZIGGI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}