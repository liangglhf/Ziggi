#include "zgpch.h"
#include <Ziggi.h>

class ExampleLayer :public Ziggi::Layer
{
public:
	ExampleLayer()
		:Layer("Example"){}
	
	void OnUpdate() override
	{
		ZG_INFO("ExampleLayer::UpDate");
	}

	void OnEvent(Ziggi::Event& event) override
	{
		ZG_TRACE("{0}", event);
	}
};

class Sandbox :public Ziggi::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

Ziggi::Application* Ziggi::CreateApplication()
{
	return new Sandbox();
}