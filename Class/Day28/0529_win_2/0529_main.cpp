#include <Windows.h>
#include <string>

using namespace std;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lparam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"Simple Windows";
	//윈도우 클래스 등록
	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	//wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);


	RegisterClass(&wc);
	

	// 윈도우 생성
	HWND hwnd = CreateWindowEx(
	0,
	CLASS_NAME,
	L"심플 윈도우 프로그램",
	WS_OVERLAPPEDWINDOW,
	// 윈도우 생성 위치
	0, 0,
	640, 480,
	NULL,
	NULL,
	hInstance,
	NULL
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	// 메세지 루프 처리
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lparam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int num;
	wstring wstr;

	switch (uMsg)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));

		num = 30;
		wstr = L"number = " + to_wstring(num);
		SetTextAlign(hdc, TA_CENTER);
		SetTextColor(hdc, RGB(255, 0, 0));
		Ellipse(hdc, 50, 50, 200, 200);
		TextOut(hdc, 100, 100, wstr.c_str(), (int)wstr.size());

		//POINT points[] = { {200, 450},{250, 500},{300,550}, {150, 400},{500, 550} };
		//Polygon(hdc, points, 5);

		EndPaint(hwnd, &ps);
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lparam);
	}
}

