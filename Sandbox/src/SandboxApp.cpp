#include <MDD2.h>


class SandboxApp : public MDD2::Application
{
	public:
	SandboxApp() {}
	~SandboxApp() {}
};




MDD2::Application* MDD2::CreateApplication() {
	return new SandboxApp();
}