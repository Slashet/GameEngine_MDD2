#pragma once


#include "core.h"



namespace MDD2 
{
	class MDD2_API Application
	{
		public:
			Application();
			virtual ~Application();
		
			void Run();

	};


	Application* CreateApplication();
}


