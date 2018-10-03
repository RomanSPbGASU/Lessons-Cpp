#include "moneylist.h"

moneylist::moneylist()
{
	first = NULL;
}

int moneylist::all_names(char* filename)
{
	fstream myfile(filename, ios::in);
	int count = 0;
	money *current = new money;						// ��������� �� ������� �������
	first = current;
	while (myfile)
	{
		myfile >> current->REGN;					// ���������� ����� �������
		myfile.get();
		getline(myfile, current->PLAN, ';');
		getline(myfile, current->NUM_SC, ';');
		getline(myfile, current->A_P, ';');
		myfile >> current->VR;
		myfile.get();
		myfile >> current->VV;
		myfile.get();
		myfile >> current->VITG;
		myfile.get();
		myfile >> current->ORA;
		myfile.get();
		myfile >> current->OVA;
		myfile.get();
		myfile >> current->OITGA;
		myfile.get();
		myfile >> current->ORP;
		myfile.get();
		myfile >> current->OVP;
		myfile.get();
		myfile >> current->OITGP;
		myfile.get();
		myfile >> current->IR;
		myfile.get();
		myfile >> current->IV;
		myfile.get();
		myfile >> current->IITG;
		myfile.get();
		getline(myfile, current->DT, ';');
		current->DT.resize(10);
		myfile >> current->PRIZ;
		current->next = new money;					// ��������� ������ ��� ����� �������
		current = current->next;					// ������� ��������� � ������ ��������
		if (!myfile)
		{
			current->next = NULL;
			break;
		}
		count++;
	}
	return count;

}

void moneylist::display()								// ����� �� ������ � ����� ������� (120
{
	money *current = first;
	while (current)
	{
		cout << current->REGN << " " 
			<< current->PLAN << " " 
			<< current->NUM_SC << " " 
			<< current->A_P << " " 
			<< current->VR << " " 
			<< current->VV << " " 
			<< current->VITG << " " 
			<< current->ORA << " " 
			<< current->OVA << " " 
			<< current->OITGA << " " 
			<< current->ORP << " " 
			<< current->OVP << " " 
			<< current->OITGP << " " 
			<< current->IR << " " 
			<< current->IV << " " 
			<< current->IITG << " " 
			<< current->DT << " "
			<< current->PRIZ << endl;
		current = current->next;
	}
}

void moneylist::display_single(double regnumber, string scnumber, char * filename)
{
	fstream myfile(filename, ios::out);
	money * current = first;
	while (1)
	{
		if ((current->REGN == regnumber) && (current->NUM_SC == scnumber))
		{
			  cout << current->DT << setw(6) << " " << setw(7) << fixed << setprecision(0) << current->IITG << endl;
			myfile << current->DT << setw(6) << " " << setw(7) << fixed << setprecision(0) << current->IITG << endl;
		}
		current = current->next;
		if (current->next == NULL)
		{
			break;
		}
	}
}

moneylist::~moneylist()
{
	money* current = first;							// ���������� ��������� �� ������ �������
	while (current != NULL)						// ����� �� ���������� ���������� ��������
	{
		money* temp = current;						// ��������� ��������� �� ������ �������
		current = current->next;					// �������� ������ �� ��������� �������
		delete temp;								// ������� ������� �������
	}
	cout << "�������� ������� ������� 101F" << endl;
}

