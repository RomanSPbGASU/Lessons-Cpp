#include <iostream>
#include <iomanip>
#include "stock.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	stock sec[3] =	{ {"Газпром", "акция", 50, 141.56f},
					{"Сбербанк", "акция", 135, 101.87f},
					{"Газпром", "облигация", 214, 1001.26f} };
	stock buy[3] =	{ { "Газпром", "акция", 50, 137.89f }, //в задании сказано, что массивы buy и sell должны иметь по 3 элемента
					{ "Сбербанк", "акция", 115, 98.09f },
					{"Газпром", "облигация", 0, 0} };
	stock sell[3] = { { "Газпром", "акция", 0, 0 },
					{ "Сбербанк", "акция", 150, 101.62f },
					{ "Газпром", "облигация", 114, 1002.68f } };
//рисуем таблицу
	cout << " " << setw(20) << left << "Наименование ЦБ" << setw(12) << left << "Тип ЦБ"
		<< setw(15) << left << "Количество" << setw(12) << left << "Цена ЦБ" << setw(20)
		<< right << "Стоимость позиции" << endl 
		<< "\n" << setw(50) << right << "НАЧАЛЬНОЕ СОСТОЯНИЕ ПОРТФЕЛЯ" << endl << endl;
	const int posnumber = 3; //потому, что количество элементов массива известно
	for (int i = 0; i < posnumber; i++)
		sec[i].show_investment();
	stock fict(NULL, NULL, 0, 0); //фиктивный объект (не знаю, как сделать без него)
	int count = sizeof(sec) / sizeof(stock);
	cout << "\n " << setw(32) << left << "Общая стоимость портфеля" 
		<< setw(15) << setw(47) << right << setprecision(2) << fixed << fict.portfolio_cost(sec, count) << endl;
	cout << "\n" << setw(40) << right << "ПОКУПКИ" << endl << endl;
	for (int i = 0; i < posnumber; i++)
		buy[i].show_investment();
	cout << "\n" << setw(40) << right << "ПРОДАЖИ" << endl << endl;
	for (int i = 0; i < posnumber; i++)
		sell[i].show_investment();
	cout << "\n" << setw(50) << right << "КОНЕЧНОЕ СОСТОЯНИЕ ПОРТФЕЛЯ" << endl << endl;
	for (int i = 0; i < posnumber; i++)
	{
		sec[i].recalc_investment(buy[i], sell[i]); //можно добавить проверку на совпадение эмитента и типа ЦБ для каждой позиции
		sec[i].show_investment();
	}
	cout << "\n " << setw(32) << left << "Общая стоимость портфеля"
		<< setw(15) << setw(47) << right << setprecision(2) << fixed << fict.portfolio_cost(sec, count) << endl;
	cin.get();
}
