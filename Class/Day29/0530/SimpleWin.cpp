#include <Windows.h>
#include "WindowApp.h"
#include "..\WinAppDll\math.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	WindowApp app(hInstance);

	if (!app.Initialize(L"Not Simple Window", Add(250,250), Sub(1000,500)))	// WindowApp, WinAppDll을 참조하여 
																			// Initialize 및 Add, Sub 사용
	{
		return 1;
	}

	return app.Run();
}
