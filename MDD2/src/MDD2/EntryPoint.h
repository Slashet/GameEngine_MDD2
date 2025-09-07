#pragma once


#ifdef MDD_PLATFORM_WINDOWS


extern MDD2::Application* MDD2::CreateApplication();

int main(int argc, char** argv) 
{
	MDD2::Log::Init();

	MDD2_CORE_WARN("MDD2 Engine Initialized!");
	MDD2_INFO("Welcome to MDD2!");

	auto app = MDD2::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

