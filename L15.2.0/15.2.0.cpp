#include "Distance.h"

int main()
{
	SetConsoleOutputCP(1251);

	Distance dist1, dist3, dist4; // �������� �������� dist1 � dist3
	Distance dist2(13, 6.5); // �������� ������� dist2 � ��� �������������

	dist1.get_dist(); // ��������� ������ � dist1
	dist3 = dist1 + dist2;
	dist4 = dist1 + dist2 + dist3;

	cout << "\ndist1 = "; dist1.show_dist(); // ����� ���� �� �����
	cout << "\ndist2 = "; dist2.show_dist();
	cout << "\ndist3 = "; dist3.show_dist();
	cout << "\ndist4 = "; dist4.show_dist();
	cout << endl << endl;
	system("pause");
}