#include <Windows.h>
#include "Distance.h"
#include "Queue.h"

int main()
{
	SetConsoleOutputCP(1251);
	Queue<char*> arr1;							// очередь из строк char
	Queue<float> arr2;							// очередь типа float
	Queue<Distance> arr3;						// очередь типа Distance

	arr1.put("Понедельник");
	arr1.put("Вторник");
	arr1.get();
	arr1.put("Среда");
	arr1.get();
	arr1.get();

	arr2.put(77.77);
	arr2.put(88.88);
	arr2.put(99.99);
	arr2.get();
	arr2.put(111.11);
	arr2.get();
	arr2.get();
	arr2.get();

	arr3.put(25.1648);
	arr3.put(144.2518);
	arr3.get();
	arr3.put(4.9914);
	arr3.get();
	arr3.get();

	system("pause");
}