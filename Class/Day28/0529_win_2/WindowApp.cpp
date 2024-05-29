#include "WindowApp.h"

WindowApp* g_pApp = nullptr;

// 생성자
WindowApp::WindowApp(HINSTANCE hInstance) : hInstance(hInstance), hWnd(NULL){
    g_pApp = this;
}

// 소멸자
WindowApp::~WindowApp(){

}

// 윈도우 클래스 등록
bool WindowApp::RegisterWindowClass(){

    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = className;

    return RegisterClassEx(&wc) != 0;
}

// 윈도우 생성
bool WindowApp::CreateAppWindow(int nCmdShow){

    hWnd = CreateWindowEx(0,
        className,
        L"0529 Window Class",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 400,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (!hWnd){
        return false;
    }

    ShowWindow(hWnd, nCmdShow);
    return true;
}

// 초기화
bool WindowApp::Initialize(){

    if (!RegisterWindowClass()){
        return false;
    }

    return CreateAppWindow(SW_SHOW);
}

// 메시지 루프
int WindowApp::Run(){

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

// 정적 윈도우 프로시저 함수
LRESULT CALLBACK WindowApp::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

    if (g_pApp){
        return g_pApp->HandleMessage(hWnd, message, wParam, lParam);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

// 메시지 핸들링
LRESULT WindowApp::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

    HDC hdc;
    PAINTSTRUCT ps;

    switch (message){
    case WM_SIZE:
        InvalidateRect(hWnd, NULL, TRUE);
        return 0;
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));
        EndPaint(hWnd, &ps);
        return 0;
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
