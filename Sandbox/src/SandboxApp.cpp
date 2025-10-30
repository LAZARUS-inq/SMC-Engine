#include <SMC.h>

class Sandbox : public SMC::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

SMC::Application* SMC::CreateApplication()
{
	return new Sandbox();
}