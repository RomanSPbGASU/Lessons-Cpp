#include "moneylist.h"
#include "planlist.h"
#include "nameslist.h"
#include <Windows.h>

int main()
{
	{
		SetConsoleOutputCP(1251);

		char*file_1 = "NAMES.txt", *file_2 = "PLAN.txt", *file_3 = "101F.txt";

		nameslist n1;																// �������� ��������� �������� �� �������� NAMES, PLAN � 101F
		planlist p1;
		moneylist m1;
		time_t dt = time(NULL);

		int number_b = n1.all_names(file_1);										// ���������� ������ ������ � ������� ���������� ������� � ����� NAMES.txt
		cout << "��������� " << number_b << " ������� �� ����� " << file_1 << endl;
		int number_p = p1.all_names(file_2);										// ���������� ������ ������ � ������� ���������� ������� � ����� PLAN.txt
		cout << "��������� " << number_p << " ������� �� ����� " << file_2 << endl;
		int number_r = m1.all_names(file_3);										// ���������� ������  � ������� ���������� ������� � ����� 101F.txt
		cout << "��������� " << number_r << " ������� �� ����� " << file_3 << endl;
		cout << "����� ����������: " << -(dt -= time(NULL)) << endl;

		int regn;
		string num_sc;
		cout << "\n������� ���. ����� �����: "; cin >> regn;
		if (n1.get_single(regn) == "\0")
		{
			system("pause");
			return(0);
		}

		cout << "\n������� ����� �����: "; cin >> num_sc;
		if (p1.get_single(num_sc) == "\0")
		{
			system("pause");
			return(0);
		}

		cout << "\n�������� ������� �� ����� �" << num_sc << " \"" << p1.get_single(num_sc) << " \"" << endl;

		cout << "\n��� ����� �" << regn << " " << n1.get_single(regn) << endl;

		cout << setw(7) << right << "����" << setw(22) << "�����, ���. ���." << endl;
		m1.display_single(regn, num_sc, "RES.txt");
		cout << endl;
	}
	system("pause");
}
