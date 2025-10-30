#pragma once

#include "Core.h"

namespace SMC {

	class SMC_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


