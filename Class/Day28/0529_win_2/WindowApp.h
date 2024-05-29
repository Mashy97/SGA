#pragma once
#include <Windows.h>
class WindowApp
{
public:
    WindowApp(HINSTANCE hInstance);
    ~WindowApp();
    bool Initialize();
    int Run();

private:
    HINSTANCE hInstance;
    HWND hWnd;
    LPCWSTR className = L"WindowClass";

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    bool RegisterWindowClass();
    bool CreateAppWindow(int nCmdShow);
};
