#include <Windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM); // �������� ������� - ������� ���������

// �������� ������� - ������ int main() � ���������� ����������:
int WINAPI WinMain(HINSTANCE hInstance, //���������� ���������� ����������
	HINSTANCE hPrevInstance, // � Win32 �� ������������
	LPSTR lpCmdLine, // ����� ��� ������� ���� � ������ ��������� ������
	int nCmdShow) // ����� ����������� ����
{
		HWND hwnd;
		MSG msg;
		WNDCLASS w; // �������� ���������� ���� ������ ����
	memset(&w,0,sizeof(WNDCLASS));
		w.style = CS_HREDRAW | CS_VREDRAW; // ��������� ���� ����
		w.lpfnWndProc = WndProc;
		w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ��������� ���� ���� - ����� ����
	w.lpszClassName = L"��� �����"; // ��������� �� ��� ������ ����
	RegisterClass(&w); // ����������� ������ ����
	hwnd = CreateWindow(L"��� �����", L"��������������", WS_OVERLAPPEDWINDOW, // ������� ����
		250, 0, 800, 400, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow); // ���������� ����
	UpdateWindow(hwnd); // ���������� ����������� ����
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) // ������� ���������
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