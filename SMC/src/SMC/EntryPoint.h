#pragma once

#ifdef SMC_PLATFORM_WINDOWS

extern SMC::Application* SMC::CreateApplication();

int main(int argc, char** argv)
{
	SMC::Log::Init();
	SMC::Log::GetCoreLogger()->warn("SMC Engine Started.");
	SMC::Log::GetClientLogger()->info("Hello from SMC Client.");

	auto app = SMC::CreateApplication();
	app->Run();
	delete app;
}

#endif
