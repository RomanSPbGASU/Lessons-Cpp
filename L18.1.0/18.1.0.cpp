#include <Windows.h>
#include "copy.h"
#include <fstream>
using namespace std;

void main()
{
	copyapp("F101.txt", "�������.txt");
	copyapp("F123.txt", "�������.txt");
	copyapp("F134.txt", "�������.txt");
	copyapp("F135.txt", "�������.txt");
	system("pause");
}