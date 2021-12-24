#include "time_table.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
int time_table::time_table_managment()
{
	char ch;
	do {
		system("cls");
		cout << "\t\t  ***************************************************" << endl;
		cout << "\t\t  |   *WELLCOME TO UOG TIME TABLE MANEGMENT SYSTEM* |" << endl;
		cout << "\t\t  ***************************************************" << endl;
		cout << "\t\t\t  ************************************" << endl;
		cout << "\t\t\t  |" << "  INSERT TIME TABLE       Press 1 |" << endl;
		cout << "\t\t\t  |" << "  TIME TABLE Display Data Press 2 |" << endl;
		cout << "\t\t\t  |" << "  Back                    Press 3 |" << endl;
		cout << "\t\t\t  ************************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			insert_time_table_data();
			break;
		case '2':
			read_time_table_data();
			break;
		case '3':
			return 0;
			break;
		default:
			cout << "Wrong entery" << endl;
		}

		cout << "Do You Want Back  TIME TABLE MANEGMENT SYSTEM n/y" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
		
}
void time_table::insert_time_table_data()
{
	cout << "Enter Time Table Data" << endl;
	for(int i=0;i<5;i++)
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter " << day[i] << " Lecture " << 1 + j << endl;
			cin >> lacture[i][j];
		}
	cout << "Do you want to save n/y" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	write_time_table_data();
	show_time_table();
}
void time_table::edit_time_table()
{





}
void time_table::show_time_table()
{
	cout << "\t\t ***********************************************************************************" << endl
		<< setiosflags(ios::left) << "\t\t | " << setw(10) << "DAY" << " | " << setw(20)
		<< "LECTURE 1" << " | " << setw(20) << "LECTURE 2" << " | " << setw(20) 
		<< "LECTURE 3" << " | " << endl;
	cout << "\t\t ***********************************************************************************" << endl;
	for (int i = 0; i< 5; i++) 
	{
		cout << setiosflags(ios::left) << "\t\t | " << setw(10) << day[i] << " | " << setw(20)
			<< lacture[i][0] << " | " << setw(20) << lacture[i][1] << " | " << setw(20) 
			<< lacture[i][2] << " | " << endl;
		cout << " \t\t ***********************************************************************************" << endl;
	}
	
}      
void time_table::write_time_table_data()
{
	ofstream fout;
	fout.open("time_table.txt", ios::out);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++)
		{
			strcpy_s(lac, lacture[i][j].c_str());
		fout << lac<<" ";
	    }
	fout.close();
}
void time_table::read_time_table_data()
{ 
	string s[15];
	int n = 0;
	ifstream fin;
	
	fin.open("time_table.txt", ios::in);
	{
		while (!fin.eof())
		{
			fin >> s[n];
			n++;
		}
	}
	n = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++)
		{
			lacture[i][j] = s[n];
			n++;
		}
	show_time_table();
}
