#include <windows.h> // ������������ ����, ���������� ������� API

// �������� ������� - ������ int main() � ���������� ����������:
int WINAPI WinMain(HINSTANCE hInstance, // ���������� ���������� ����������
	HINSTANCE hPrevInstance, // � Win32 �� ������������
	LPSTR lpCmdLine, // ����� ��� ������� ���� � ������ ��������� ������
	int nCmdShow) // ����� ����������� ����
{
	// ������� ������ ���� � ������� "��" �� �����
	MessageBox(NULL, L"������, ����!!!", L"���������", MB_OK);
	return NULL; // ���������� �������� �������
}