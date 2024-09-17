#include<Ziggi.h>

class Sandbox :public Ziggi::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Ziggi::Application* Ziggi::CreateApplication()
{
	return new Sandbox();
}