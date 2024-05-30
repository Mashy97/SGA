#include <iostream>
#include <string>
#include <Windows.h>
typedef int (*math_func)(int, int);


int main() {

	// library open ( dll 파일을 사용하여 읽어오기 )
	HINSTANCE hinstLib = LoadLibrary(L"WinAppDll.dll");
	if (!hinstLib)
	{
		std::cout << "Not found WinAppDll.dll" << std::endl;
		return 1;
	}

	math_func add = (math_func)GetProcAddress(hinstLib, "Add");
	math_func sub = (math_func)GetProcAddress(hinstLib, "Sub");

	if (!add) {
		std::cout << "Not found add" << std::endl;
		return 1;
	}

	if (!sub) {
		std::cout << "Not found sub" << std::endl;
		return 1;
	}

	int temp_1 = add(150, 100);
	int temp_2 = sub(250, 50);

	std::cout << temp_1 << " " << temp_2 << std::endl;
	return 0;

}