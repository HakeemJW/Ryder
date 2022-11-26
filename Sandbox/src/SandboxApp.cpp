#include <Ryder.h>

class Sandbox : public Ryder::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Ryder::Application* Ryder::CreateApplication()
{
	return new Sandbox();
}

