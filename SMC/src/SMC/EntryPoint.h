#pragma once

#ifdef SMC_PLATFORM_WINDOWS

extern SMC::Application* SMC::CreateApplication();

int main(int argc, char** argv)
{
	printf("SMC Engine Starting...\n");
	auto app = SMC::CreateApplication();
	app->Run();
	delete app;
}

#endif
