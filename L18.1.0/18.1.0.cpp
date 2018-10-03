#include <Windows.h>
#include "copy.h"
#include <fstream>
using namespace std;

void main()
{
	copyapp("F101.txt", "Уралсиб.txt");
	copyapp("F123.txt", "Уралсиб.txt");
	copyapp("F134.txt", "Уралсиб.txt");
	copyapp("F135.txt", "Уралсиб.txt");
	system("pause");
}