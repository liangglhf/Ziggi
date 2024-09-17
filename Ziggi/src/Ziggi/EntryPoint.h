#pragma once

#ifdef ZG_PLATFORM_WINDOWS

extern Ziggi::Application* Ziggi::CreateApplication();

int main(int argc, char** argv)
{
	Ziggi::Log::Init();
	ZG_CORE_WARN("Initialized Log!");
	int a = 5;
	ZG_INFO("Hello! Var={0}", a);

	auto app = Ziggi::CreateApplication();
	app->Run();
	delete app;
}

#endif