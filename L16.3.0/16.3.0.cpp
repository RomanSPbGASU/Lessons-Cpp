#include "publication.h"
#include "book.h"
#include "tape.h"
#include <Windows.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	book Tales;
	tape Stories;

	Tales.getdata();
	Stories.getdata();

	Tales.putdata();
	Stories.putdata();
	system("pause");
}