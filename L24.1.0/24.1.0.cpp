#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

map<int, string> read_names(const char *filename)
{
	ifstream names_stream(filename);
	map<int, string> data;
	int number;
	string name;
	while (names_stream)
	{
		names_stream >> number;
		names_stream.get();
		getline(names_stream, name, ';');
		data[number] = name;
	}
	sort(data.begin(), data.end(), less<>());
	return data;
}

void write_names(const char *filename, map<int, string> data)
{
	ofstream names_ofstream(filename);
	ostream_iterator< map<int, string> > names_iter(names_ofstream, "/n");
	copy(data.begin(), data.end(), names_iter);
}

int main()
{
	SetConsoleOutputCP(1251);

	const char	*input_file =		"NAMES.txt", 
				*output_file_name = "NAMES_name.txt",
				*output_file_numb =	"NAMES_numb.txt";

	map<string, int> mapNames;
	map<int, string> mapNumb;

	read_names(input_file, mapNames);

	cout << "Загружено " << mapNames.size() << " записей " << " из файла " << input_file << endl;
	
	/*...*/

	write_names(output_file_numb, mapNumb);

	cout << "Записано " << mapNumb.size() << " записей в файл" << output_file_numb << endl;
	cout << "Записано " << mapNames.size() << " записей в файл" << output_file_name << endl;
	write_names(output_file_name, mapNames);

	system("pause");
}