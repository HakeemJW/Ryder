#pragma once

#ifdef RY_PLATFORM_WINDOWS

extern Ryder::Application* Ryder::CreateApplication();

int main(int argc, char** argv)
{
	printf("Starting Ryder Engine");
	auto app = Ryder::CreateApplication();
	app->Run();
	delete app;
}
#endif
