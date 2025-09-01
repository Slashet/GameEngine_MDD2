#pragma once


#ifdef MDD_PLATFORM_WINDOWS


extern MDD2::Application* MDD2::CreateApplication();

int main(int argc, char** argv) {


	auto app = MDD2::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

