#include "Distance.h"

void main()
{
	SetConsoleOutputCP(1251);

	Distance dist1, dist3; // создание объектов dist1 и dist3
	Distance dist2(13, 6.5); // создание объекта dist2 и его инициализация

	dist1.get_dist(); // получение данных о dist1

	cout << "\ndist1 = "; dist1.show_dist(); // вывод длин на экран
	cout << "\ndist2 = "; dist2.show_dist();
	cout << "\nПосле добавления: ";

	dist3 = dist1 += dist2;
	cout << "\ndist1 = "; dist1.show_dist();
	cout << "\ndist3 = "; dist3.show_dist();
	cout << endl << endl;
	system("pause");
}