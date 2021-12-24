#include "UOG_MAIL.h"
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
int a = 0;
using namespace std;
int UOG_MAIL::uog_mail_system(char sid[20])
{
	char ch;
	do
	{
		system("cls");
		cout << "\t\t\t  ********************************************" << endl;
		cout << "\t\t\t  |     *WELLCOME TO UOG MAIL SYSTEM*        |" << endl;
		cout << "\t\t\t  ********************************************" << endl;
		cout << "\t\t\t************************************************" << endl;
		cout << "\t\t\t|" << " INBOX MAIL             \t Press 1       |" << endl;
		cout << "\t\t\t|" << " CHECK SEND MAIL        \t Press 2       |" << endl;
		cout << "\t\t\t|" << " SEND MAIL TO AN OTHER  \t Press 3       |" << endl;
		cout << "\t\t\t|" << " Back                   \t Press 4       |" << endl;
		cout << "\t\t\t************************************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			inbox_mail(sid);
			break;
		case'2':
			send_mail(sid);
			break;
		case'3':
			SEND_MAIL_TO_AN_OTHER(sid);
			break;
		case'4':
			return 0;
			break;
		}
		cout << "do you again y/n" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
void UOG_MAIL::SEND_MAIL_TO_AN_OTHER(char sid1[20])
{
	char s;
	string sms;
	int i = 0, n = 0;
	cout << "Enter Reciver mail" << endl;
	cin >> reciver_id;
	strcpy_s(sender_id, sid1);
	cout << "sender id  " << sender_id << endl;
	cout << "write mail " << endl << endl;
	do {
		s = _getch();
		if (s == ' ')
		{
			sms += s;
		}
		else if (s == '\r')
		{
			break;
		}
		else
		{
			sms += s;
		}
		cout << s;
		n++;
	} while (n != 100);

	cout << endl << endl;
	strcpy_s(massage, sms.c_str());
	write_mail_data();
}
void UOG_MAIL::send_mail(char id[20])
{
	int n = 0;
	char send[20];
	ifstream fin;
	fin.open("mail.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		if (!strcmp(id, sender_id))
		{
			a = 1;
			show_mail();
			n = 1;

		}
		fin.read((char*)this, sizeof(*this));
	}
	if (n == 0)
		cout << "no data " << endl;
	fin.close();
}
void UOG_MAIL::inbox_mail(char id[20])
{
	int n = 0;
	char send[20];
	ifstream fin;
	fin.open("mail.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		if (!strcmp(id, reciver_id))
		{
			a = 2;
			show_mail();
			n = 1;

		}

		fin.read((char*)this, sizeof(*this));
	}
	if (n == 0)
		cout << "no data " << endl;
	fin.close();
}
void UOG_MAIL::write_mail_data()
{
	ofstream fout;
	fout.open("mail.txt", ios::app);
	fout.write((char*)this, sizeof(*this));
	fout.close();
}
void UOG_MAIL::show_mail()
{
	if (a == 1)
	{
		cout << "\t\t\t******************************************************" << endl;
		cout << "\t\t\tTO    " << reciver_id << "@uog.edu.pk" << endl << endl;
		cout << "\t\t\tMASSAGE :" << endl;
		cout << "\t\t\t" << massage;
		cout << endl << endl;
		cout << "\t\t\t******************************************************" << endl;
	}
	if (a == 2)
	{
		cout << "\t\t\t******************************************************" << endl;
		cout << "\t\t\tFROM   " << sender_id <<"@uog.edu.pk"<< endl << endl;
		cout << "\t\t\tMASSAGE :" << endl;
		cout << "\t\t\t" << massage;
		cout << endl << endl;
		cout << "\t\t\t******************************************************" << endl;
	}
}