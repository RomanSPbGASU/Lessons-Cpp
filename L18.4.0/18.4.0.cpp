#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <limits.h>
using namespace std;

void read_f(char*);															// чтение данных из файла
void write_f(char*, char*);													// ввод данных в конец файла из файла
void write_f(char*);														// ввод данных с клавиатуры
void getfilename(char*);													// возвращает имя файла введённое пользователем
int selectmet();															// выбор метода ввода
int continueinput();														// запрос продолжать ли ввод

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* file = "list.txt", *file_1 = "list_1.txt";						// Имена внешних файлов

	cout << "Начальный список..." << endl << endl;
	read_f(file);															// вывод на экран начального списка из файла list.txt
	do
	{
		if (selectmet() == 1)
			write_f(file);													// если ввели 1, то ввод с клавиатуры
		else
		{
			char filename[80];
			getfilename(filename);
			cout << "Дополнительный список из файла " << filename << "..." << endl << endl;
			read_f(filename);
			write_f(file, filename);										// если ввели 2, то ввод из файла
		}
		cout << "Обновлённый список..." << endl << endl;
		read_f(file);
	} while (continueinput());
	system("pause");
}

void read_f(char*filename)
{
	fstream myfile(filename, ios::in | ios::_Nocreate);						// создание объекта класса fstream и инициализация его файлом, указываемым filename
	if (myfile.is_open() == 0) cout << "Ошибка открытия файла" << endl;		// проверка правильности открытия файла
	else
	{
		cout << myfile.rdbuf() << endl;										// вывод буфера потока myfile на экран
	}
	myfile.close();
}

void write_f(char*filename1, char*filename2)
{
	fstream myfile1(filename1, ios::app);									// открытие первого файла для чтения
	fstream myfile2(filename2, ios::in | ios::_Nocreate);					// открытие второго файла для чтения
	char endchar;															// последний символ в файле
	myfile1 << endl << myfile2.rdbuf();										// запись буфера потока, инициализированного вторым файлом в первый (в конец)
	myfile1.close();														// закрытие файлов
	myfile2.close();
}

void write_f(char*filename)
{
	int number; char surname[80], name[80]; float salary;
	cout << "Введите номер сотрудника: "; cin >> number;
	cout << "Введите фамилию сотрудника: "; cin >> surname;
	cout << "Введите имя сотрудника: "; cin >> name;
	cout << "Введите оклад сотрудника: "; cin >> salary;
	fstream myfile(filename, ios::app);										// открыли файл для чтения
	myfile << endl << number << " " << surname << " "
		<< setw(15 - strlen(surname)) << left << name << " " 
		<< fixed << setprecision(2) << salary;
	myfile.close();
}
void getfilename(char* filename)
{
	cout << "Введите полное имя файла: ";
	cin >> filename;
}

int selectmet()
{
	cout << "Выберите вариант ввода данных: 1 - c клавиатуры"
		<< endl << setw(45) << right << "2 - из файла:	";
	int answer;
	cin >> answer;														// считали введённые символы (до пробела)
	return answer;
}

int continueinput()
{
	cout << "Продолжаем ввод? (д/н): ";
	char answer;
	cin >> answer;
	if (answer == 'д') return 1;
	else return 0;
}
