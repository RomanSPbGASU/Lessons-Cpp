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
int intin();																// требует вводить только целое число
float floatin();															// требует вводить только число

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
	fstream myfile1(filename1, ios::in);									// открытие первого файла для чтения
	fstream myfile2(filename2, ios::in | ios::_Nocreate);					// открытие второго файла для чтения
	char endchar;															// последний символ в файле
	myfile1.seekg(-1, ios::end);											// поставим указатель за 1 символ до конца файла
	myfile1.get(endchar);													// считаем последний символ
	myfile1.close();														// закрытие файла
	myfile1.open(filename1, ios::app);										// открытие первого файла для записи в конец
	if (endchar != '\n') myfile1 << endl;									// если в конце файла нет перевода строки, то перейти на новую строку
	myfile1 << myfile2.rdbuf();												// запись буфера потока, инициализированного вторым файлом в первый (в конец)
	myfile1.close();														// закрытие файлов
	myfile2.close();
}

void write_f(char*filename)
{
	int number; char surname[80], name[80]; float salary;
	cout << "Введите номер сотрудника: "; number = intin();
	cout << "Введите фамилию сотрудника: "; cin >> surname;
	cout << "Введите имя сотрудника: "; cin >> name;
	cout << "Введите оклад сотрудника: "; salary = floatin();
	fstream myfile(filename, ios::in);										// открыли файл для чтения
	char endchar;															// последний символ в файле
	myfile.seekg(-1, ios::end);												// поставим указатель за 1 символ до конца файла
	myfile.get(endchar);													// считаем последний символ
	myfile.close();															// закрытие файла
	myfile.open(filename, ios::app);										// открытие файла для записи в конец
	if (endchar != '\n') myfile << endl;									// если в конце файла нет перевода строки, то перейти на новую строку
	myfile << number << " " << surname << " "
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
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// получили Handle вывода консоли
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// получили информацию о экране консоли
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// получили текущую позицию курсора в консоли
	COORD CursorPosition;
	int answer;
	int inputsize;															// количество введённых символов
	char ch;
	while (1)
	{
		while (cin.peek() == '\n')											// если нажали Enter не введя символ
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// выставляет курсор в правильное положение
			cin.ignore(1);													// .peek() позволяет просмотреть следующий символ без считывания (здесь используется для разрешения пользователю начать ввод)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// получили размер буфера ввода
		cin >> answer;														// считали введённые символы (до пробела)
		if (answer == 1 || answer == 2) break;
		cin.clear();														// на случай, если предыдущий ввод завершился с ошибкой
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в позицию перед введённым символом
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// перекрывает введённые символы пробелами
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в правильное положение
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() возвращает количество элементов, которые готовы к чтению из буфера
	}
	return answer;
}

int continueinput()
{
	cout << "Продолжаем ввод? (д/н): ";
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// получили Handle вывода консоли
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// получили информацию о экране консоли
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// получили текущую позицию курсора в консоли
	COORD CursorPosition;
	char answer;
	int inputsize;															// количество введённых символов
	char ch;
	while (1)
	{
		while (cin.peek() == '\n')											// если нажали Enter не введя символ
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// выставляет курсор в правильное положение
			cin.ignore(1);													// .peek() позволяет просмотреть следующий символ без считывания (здесь используется для разрешения пользователю начать ввод)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// получили размер буфера ввода
		cin >> answer;														// считали введённые символы (до пробела)
		if (answer == 'д' || answer == 'н') break;
		cin.clear();														// на случай, если предыдущий ввод завершился с ошибкой
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в позицию перед введённым символом
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// перекрывает введённые символы пробелами
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в правильное положение
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() возвращает количество элементов, которые готовы к чтению из буфера
	}
	if (answer == 'д') return 1;
	else return 0;
}

int intin()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// получили Handle вывода консоли
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// получили информацию о экране консоли
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// получили текущую позицию курсора в консоли
	COORD CursorPosition;
	int answer;
	short inputsize;
	while (1)
	{
		while (cin.peek() == '\n')											// если нажали Enter не введя символ
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// выставляет курсор в правильное положение
			cin.ignore(1);													// .peek() позволяет просмотреть следующий символ без считывания (здесь используется для разрешения пользователю начать ввод)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// получили размер буфера ввода
		cin >> answer;														// считали введённые символы (до пробела)
		if (!cin.fail()) break;
		cin.clear();														// на случай, если предыдущий ввод завершился с ошибкой
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в позицию перед введённым символом
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// перекрывает введённые символы пробелами
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в правильное положение
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() возвращает количество элементов, которые готовы к чтению из буфера
	}
	short buffersize = cin.rdbuf()->in_avail();								// размер буфера ввода
	SetConsoleCursorPosition(ConsoleHandle, 								// выставляет курсор в позицию после считанного ответа
	{ CorrectCursorPosition.X + inputsize - buffersize, CorrectCursorPosition.Y });
	for (int i = 0; i < buffersize - 1; i++) cout << " ";					// затирает "мусор"
	cin.ignore(cin.rdbuf()->in_avail());									// отчищает буфер
	cout << endl;
	return answer;
}

float floatin()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// получили Handle вывода консоли
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// получили информацию о экране консоли
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// получили текущую позицию курсора в консоли
	COORD CursorPosition;
	float answer;
	short inputsize;
	while (1)
	{
		while (cin.peek() == '\n')											// если нажали Enter не введя символ
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// выставляет курсор в правильное положение
			cin.ignore(1);													// .peek() позволяет просмотреть следующий символ без считывания (здесь используется для разрешения пользователю начать ввод)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// получили размер буфера ввода
		cin >> answer;														// считали введённые символы (до пробела)
		if (!cin.fail()) break;
		cin.clear();														// на случай, если предыдущий ввод завершился с ошибкой
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в позицию перед введённым символом
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// перекрывает введённые символы пробелами
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// выставляет курсор в правильное положение
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() возвращает количество элементов, которые готовы к чтению из буфера
	}
	short buffersize = cin.rdbuf()->in_avail();								// размер буфера ввода
	SetConsoleCursorPosition(ConsoleHandle,									// выставляет курсор в позицию после считанного ответа
	{ CorrectCursorPosition.X + inputsize - buffersize, CorrectCursorPosition.Y });
	for (int i = 0; i < buffersize - 1; i++) cout << " ";					// затирает "мусор"
	cin.ignore(cin.rdbuf()->in_avail());									// отчищает буфер
	cout << endl;
	return answer;
}