#pragma once

#ifdef RY_PLATFORM_WINDOWS

extern Ryder::Application* Ryder::CreateApplication();

int main(int argc, char** argv)
{
	Ryder::Log::Init();
	RY_CORE_WARN("Initialized Log");
	RY_CLIENT_INFO("Hello");
	auto app = Ryder::CreateApplication();
	app->Run();
	delete app;
}
#endif
