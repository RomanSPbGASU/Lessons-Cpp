// L10.3.1.1.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "L10.3.1.1.h"

#define MAX_LOADSTRING 100

// ���������� ����������:
HINSTANCE hInst;								// ������� ���������
TCHAR szTitle[MAX_LOADSTRING];					// ����� ������ ���������
TCHAR szWindowClass[MAX_LOADSTRING];			// ��� ������ �������� ����

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ���������� ��� �����.
	MSG msg;
	HACCEL hAccelTable;

	// ������������� ���������� �����
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_L10311, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ��������� ������������� ����������:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L10311));

	// ���� ��������� ���������:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  �������: MyRegisterClass()
//
//  ����������: ������������ ����� ����.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L10311));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_L10311);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   �������: InitInstance(HINSTANCE, int)
//
//   ����������: ��������� ��������� ���������� � ������� ������� ����.
//
//   �����������:
//
//        � ������ ������� ���������� ���������� ����������� � ���������� ����������, � �����
//        ��������� � ��������� �� ����� ������� ���� ���������.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �������: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����������:  ������������ ��������� � ������� ����.
//
//  WM_COMMAND	- ��������� ���� ����������
//  WM_PAINT	-��������� ������� ����
//  WM_DESTROY	 - ������ ��������� � ������ � ���������.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	//���������� � ���������
	HDC hdc = GetDC(hWnd);
	COLORREF color[] = { RGB(255, 0, 0), RGB(0, 0, 0), RGB(255, 255, 255) };
	HPEN hPen = CreatePen(PS_SOLID, 1, color[0]);
	COORD point[] = { { 300, 100 }, { 900, 100 }, { 100, 200 }, { 700, 200 },
	{ 300, 400 }, { 900, 400 }, { 100, 500 }, { 700, 500 } };
	int high = point[4].Y - point[0].Y;
	int width_top;
	int high_right = point[7].Y - point[3].Y;
	int inv_lines[3][2] = { { 4, 0 },{ 6, 4 },{ 4, 5 } }; //��������������� ������ ��� ���������� �������
	int lines[9][2] = { { 2, 0 },{ 3, 1 },{ 0, 1 },{ 2, 3 },
	{ 2, 6 },{ 6, 7 },{ 7, 5 },{ 5, 1 },{ 3, 7 } }; //��������������� ������ ��� �������� �������

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// ��������� ����� � ����:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//����������� �����
		SelectObject(hdc, hPen);
		for (int j = 0; j < high; j++)
		{
			MoveToEx(hdc, point[0].X, point[0].Y + j, NULL);
			LineTo(hdc, point[1].X, point[1].Y + j);
			MoveToEx(hdc, point[2].X, point[2].Y + j, NULL);
			LineTo(hdc, point[3].X, point[3].Y + j);
		}
		width_top = point[1].X - point[0].X;
		for (int j = 0; j < width_top; j++)
		{
			MoveToEx(hdc, point[2].X + j, point[2].Y, NULL);
			LineTo(hdc, point[0].X + j, point[0].Y);
		}
		for (int j = 0; j < high_right; j++)
		{
			MoveToEx(hdc, point[3].X, point[3].Y + j, NULL);
			LineTo(hdc, point[1].X, point[1].Y + j);
		}
		//������ ��������� (����������) �������
		hPen = CreatePen(PS_DASH, 1, color[2]);
		SelectObject(hdc, hPen);
		for (int j = 0; j < 3; j++)
		{
			MoveToEx(hdc, point[inv_lines[j][0]].X, point[inv_lines[j][0]].Y, NULL);
			LineTo(hdc, point[inv_lines[j][1]].X, point[inv_lines[j][1]].Y);
		}
		//������ ������� �������
		hPen = CreatePen(PS_SOLID, 0.9, color[1]);
		SelectObject(hdc, hPen);
		for (int j = 0; j < 9; j++)
		{
			MoveToEx(hdc, point[lines[j][0]].X, point[lines[j][0]].Y, NULL);
			LineTo(hdc, point[lines[j][1]].X, point[lines[j][1]].Y);
		}
		//������� ����, ����������� ��������
		DeleteObject(hPen);
		// ����� ���������
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���������� ��������� ��� ���� "� ���������".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
