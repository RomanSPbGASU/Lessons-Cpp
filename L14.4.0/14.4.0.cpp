#include <Windows.h>
#include <iostream>
#include "Stack.h" // дл€ Stack
#include "sect.h" // дл€ _fullscreen
using namespace std;

int main() // не по заданию. Ќе понимаю зачем нужно "создать массив из 10 элементов...", а потом "поместить все элементы массива в стек..."
{
	_fullscreen();
	Stack circlestack;
	for (short i = 0; i < 10; i++)
	{
		circlestack.add({ 683, 344 }, 30 * i, RGB(25 * i, 25 * i, 25 * i));
	}
	circlestack.display();
	//for (short i = 0; i < 10; i++) //пока не работает
	//{
	//	char text[] = "10";
	//	PrintInCoord({ 683, 344 }, text);
	//}
	cin.get();
}