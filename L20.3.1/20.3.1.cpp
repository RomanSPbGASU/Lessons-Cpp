#include "Distance.h"
#include <queue>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);

	queue<char*> arr1;		// библиотечная очередь строк char
	queue<float> arr2;		// библиотечная очередь элементов типа float
	queue<Distance> arr3;	// библиотечная очередь элементов типа Distance

								  arr1.push("Понедельник"); cout << arr1.back() << endl;
								  arr1.push("Вторник"); cout << arr1.back() << endl;
	cout << arr1.front() << endl; arr1.pop();
								  arr1.push("Среда"); cout << arr1.back() << endl;
	cout << arr1.front() << endl; arr1.pop();
	cout << arr1.front() << endl; arr1.pop();

								  arr2.push(77.77); cout << arr2.back() << endl;
								  arr2.push(88.88); cout << arr2.back() << endl;
								  arr2.push(99.99); cout << arr2.back() << endl;
	cout << arr2.front() << endl; arr2.pop();
								  arr2.push(111.11); cout << arr2.back() << endl;
	cout << arr2.front() << endl; arr2.pop();
	cout << arr2.front() << endl; arr2.pop();
	cout << arr2.front() << endl; arr2.pop();

								  arr3.push(25.1648); cout << arr3.back() << endl;
								  arr3.push(144.2518); cout << arr3.back() << endl;
	cout << arr3.front() << endl; arr3.pop();
								  arr3.push(4.9914); cout << arr3.back() << endl;
	cout << arr3.front() << endl; arr3.pop();
	cout << arr3.front() << endl; arr3.pop();

	system("pause");
}