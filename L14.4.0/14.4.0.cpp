#include <Windows.h>
#include <iostream>
#include "Stack.h" // ��� Stack
#include "sect.h" // ��� _fullscreen
using namespace std;

int main() // �� �� �������. �� ������� ����� ����� "������� ������ �� 10 ���������...", � ����� "��������� ��� �������� ������� � ����..."
{
	_fullscreen();
	Stack circlestack;
	for (short i = 0; i < 10; i++)
	{
		circlestack.add({ 683, 344 }, 30 * i, RGB(25 * i, 25 * i, 25 * i));
	}
	circlestack.display();
	//for (short i = 0; i < 10; i++) //���� �� ��������
	//{
	//	char text[] = "10";
	//	PrintInCoord({ 683, 344 }, text);
	//}
	cin.get();
}