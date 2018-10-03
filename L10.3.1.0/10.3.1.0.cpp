#include <Windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM); // прототип функции - оконной процедуры

// Основная функция - аналог int main() в консольном приложении:
int WINAPI WinMain(HINSTANCE hInstance, //дескриптор экземпляра приложения
	HINSTANCE hPrevInstance, // в Win32 не используется
	LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
	int nCmdShow) // режим отображения окна
{
		HWND hwnd;
		MSG msg;
		WNDCLASS w; // создание переменной типа класса окна
	memset(&w,0,sizeof(WNDCLASS));
		w.style = CS_HREDRAW | CS_VREDRAW; // установка типа окна
		w.lpfnWndProc = WndProc;
		w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // установка фона окна - белый цвет
	w.lpszClassName = L"Мой класс"; // указатель на имя класса окна
	RegisterClass(&w); // регистрация класса окна
	hwnd = CreateWindow(L"Мой класс", L"Параллелепипед", WS_OVERLAPPEDWINDOW, // создаем окно
		250, 0, 800, 400, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow); // прорисовка окна
	UpdateWindow(hwnd); // обновление содержимого окна
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) // оконная процедура
{
	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}