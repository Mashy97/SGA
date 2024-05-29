#include <Windows.h>
#include <string>
#include "WindowApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	WindowApp app(hInstance);

	if (!app.Initialize())
	{
		return 1;
	}

	return app.Run();
}
