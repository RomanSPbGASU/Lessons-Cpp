#include "moneylist.h"
#include "planlist.h"
#include "nameslist.h"
#include <Windows.h>

int main()
{
	{
		SetConsoleOutputCP(1251);

		char*file_1 = "NAMES.txt", *file_2 = "PLAN.txt", *file_3 = "101F.txt";

		nameslist n1;																// создание связанных ссписков по таблицам NAMES, PLAN и 101F
		planlist p1;
		moneylist m1;
		time_t dt = time(NULL);

		int number_b = n1.all_names(file_1);										// заполнение списка банков и подсчёт количества записей в файле NAMES.txt
		cout << "Загружено " << number_b << " записей из файла " << file_1 << endl;
		int number_p = p1.all_names(file_2);										// заполнение списка планов и подсчёт количества записей в файле PLAN.txt
		cout << "Загружено " << number_p << " записей из файла " << file_2 << endl;
		int number_r = m1.all_names(file_3);										// заполнение списка  и подсчёт количества записей в файле 101F.txt
		cout << "Загружено " << number_r << " записей из файла " << file_3 << endl;
		cout << "Время выполнения: " << -(dt -= time(NULL)) << endl;

		int regn;
		string num_sc;
		cout << "\nВведите рег. номер банка: "; cin >> regn;
		if (n1.get_single(regn) == "\0")
		{
			system("pause");
			return(0);
		}

		cout << "\nВведите номер счёта: "; cin >> num_sc;
		if (p1.get_single(num_sc) == "\0")
		{
			system("pause");
			return(0);
		}

		cout << "\nДенежные остатки на счёте №" << num_sc << " \"" << p1.get_single(num_sc) << " \"" << endl;

		cout << "\nДля банка №" << regn << " " << n1.get_single(regn) << endl;

		cout << setw(7) << right << "Дата" << setw(22) << "Сумма, тыс. руб." << endl;
		m1.display_single(regn, num_sc, "RES.txt");
		cout << endl;
	}
	system("pause");
}
