#include<iostream>
#include<stdlib.h>
#include"admin.h"
#include"student.h"
#include"teacher.h"
#include "conio.h"
#include"string"
#include"cstring"
using namespace std;
int main()
{
	int n=0;
	string p;
	system("color cf");
	admin a;
	teacher t;
	student s;
lab:
	
	char ID[20], PASWD[20],ch;
	cout << "\t\t###################################################" << endl;
	cout << "\t\t|   *WELCOME TO UOG Learning Management System*   |" << endl;
	cout << "\t\t###################################################" << endl;
	cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "\t\t\t\t|   Enter UOG ID      |" << endl;
	cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%" << endl << "\t\t\t\t";
	cin >> ID;
	cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "\t\t\t\t|   Enter PASSWORD    |" << endl;
	cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%" << endl<<endl << "\t\t\t\t";
	do
	{
		ch = _getch();
		if (ch == '\r')
		{
	    	n=100;
		}
		else
		{
			p += ch;
			n++;
			cout << "*";
		}

	} while (n<19);
	cout << endl;
		strcpy_s(PASWD, p.c_str());
	switch (ID[0])
	{
	case'a':
		a.check_login( ID,  PASWD);
		break;
	case't':
		t.t_check_login(ID, PASWD);
		break;
	case'1':
		s.student_login(ID, PASWD);
		break;
	case'7':
		a.check_login(ID, PASWD);
		break;
	default:
	{
		system("cls");
		cout << " You Enter Rong ID and PASSWORD \nTry Again\n" << endl;
		goto lab;

	}
	}
}
