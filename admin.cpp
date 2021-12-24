#include "admin.h"
#include "teacher.h"
#include "student.h"
#include "time_table.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cstring>
#include<Windows.h>
using namespace std;
void admin::check_login(char id[12], char pwsd[12])
{
	char d_id[12] = { '7','7','7' };
	char d_pwsd[12] = { '7','7','7' };
	int n = 0;
	ifstream fin;
	fin.open("admin.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		if (!(strcmp(id, t_id)))
			if (!(strcmp(pwsd, t_password)))
		{
			n = 10;
			break;
		}
		fin.read((char*)this, sizeof(*this));
	}
	fin.close();
	if (n == 10)
	{
		cout << "WELCOME TO UOG LMS " << a_name << endl;
		Sleep(1000);
		uni_manegment_systam();
	}
	else if (!(strcmp(id, d_id) ))
		if(!(strcmp(pwsd, d_pwsd)))
	{
			system("cls");
			cout << endl << endl;
			cout << "\t\t      **********************************************" << endl;
			cout << "\t\t      |      *WELLCOME TO UOG LMS DEVELOPORS*      |" << endl;
			cout << "\t\t      **********************************************" << endl<<endl;
			cout << "\t\t      **********************************************" << endl;
			cout << "\t\t      |      *RANA ABOBAKAR*   *19014156-022*      |" << endl;
			cout << "\t\t      **********************************************" << endl;
			cout << "\t\t      |      *ABDUL RAFAY*     *19014156-007*      |" << endl;
			cout << "\t\t      **********************************************" << endl;
			cout << "\t\t      |      *ABDULLAH MUSHTAQ* *19014156-012*     |" << endl;
			cout << "\t\t      **********************************************" << endl;
			cout << "Pree Anu Key\n";
			_getch();
		uni_manegment_systam();
	}
	else
	{
			cout << "\t\tWrong ID Try Again \n";
		
	}
}// end function
int admin::uni_manegment_systam()
{
	char ch;
 do{
	student s;
	time_table t;
	system("cls");
	cout << "\t\t      **********************************************" << endl;
	cout << "\t\t      | *WELLCOME TO UOG LMS MANEGMENT SYSTEM*     |" << endl;
	cout << "\t\t      **********************************************" << endl;
	cout << "\t\t\t*****************************************" << endl;
	cout << "\t\t\t|" << " TEACHER MANEGMENT SYSTEM    Press 1   |" << endl;
	cout << "\t\t\t|" << " STUDENT MANEGMENT SYSTEM    Press 2   |" << endl;
	cout << "\t\t\t|" << " ADMIN MANEGMENT SYSTEM      Press 3   |" << endl;
	cout << "\t\t\t|" << " TIME TABLE MANEGMENT SYSTEM Press 4   |" << endl;
	cout << "\t\t\t|" << " MAIL SYSTEM                 Press 5   |" << endl;
	cout << "\t\t\t|" << " Exit                        Press 6   |" << endl;
	cout << "\t\t\t*****************************************" << endl << endl << endl;
	cout << "\t\t\t" << "Press any key to continue ::  ";
	cin >> ch;
	switch (ch)
	{
	case '1':
		teacher_management();
		break;
	case '2':
		s.student_management();
		break;
	case '3':
		admin_managment();
		break;
	case '4':
		t.time_table_managment();
		break;
	case '5':
		UOG_MAIL m;
		m.uog_mail_system(a_id);
		break;
	case '6':
		return 0;
	default:
		cout << "Wrong entery" << endl;
	} 
	cout << "\t\tDo You Want Again UOG LMS MANEGMENT SYSTEM n/y" << endl;
	cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}//end function
int admin::admin_managment()
{
	char ch;
	do {
		system("cls");
		cout << "\t\t  **********************************************" << endl;
		cout << "\t\t  |  *WELLCOME TO UOG ADMIN MANEGMENT SYSTEM*  |" << endl;
		cout << "\t\t  **********************************************" << endl;
		cout << "\t\t\t**********************************" << endl;
		cout << "\t\t\t|" << " Admin Insert Data  Press 1     |" << endl;
		cout << "\t\t\t|" << " Admin Search Data  Press 2     |" << endl;
		cout << "\t\t\t|" << " Admin Update Data  Press 3     |" << endl;
		cout << "\t\t\t|" << " Admin Display Data Press 4     |" << endl;
		cout << "\t\t\t|" << " Back               Press 5     |" << endl;
		cout << "\t\t\t**********************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			admin_insert_data();
			break;
		case '2':
			admin_search_data();
			break;
		case '3':
			admin_update_data();
			break;
		case '4':
			read_admin_data();
			break;
		case '5':
			return 0;
			break;
		default:
			cout << "Wrong entery" << endl;
		}
		cout << "Do you want again edit Adman data n/y" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}//end function
void admin::admin_insert_data()
{
	static int c;
	int n;
	ifstream f;
	f.open("a_count.txt", ios::in);
	f >> c;
	n = c;
	f.close();
	
	cout << n << endl;
	if (n == 2)
	{
		cout << "\t\tMaximam Number of Admin Is 2 Not Enter Again Admin " << endl;
		cout << "press Any Key\n";
		_getch();
	}
	else
	{
		cout << "\t\tEnter Admin Name" << endl << "\t\t";
		cin >> a_name;
		cout << "\t\tEnter Admin Father Name" << endl << "\t\t";
		cin >> af_name;
		cout << "\t\tEnter Admin Address" << endl << "\t\t";
		cin >> a_address;
		cout << "\t\tEnter Admin Gender" << endl << "\t\t";
		cin >> a_gender;
		cout << "\t\tEnter Admin Date of Birth" << endl << "\t\t";
		cin >> a_DOB;
		cout << "\t\tEnter Admin Qualification" << endl << "\t\t";
		cin >> a_qualification;
		cout << "\t\tEnter Admin Mobile number" << endl << "\t\t";
		cin >> a_mobile_no;

		string a_roll = "admin-";
		char u_mail[11] = { '@','u','o','g','.','e','d','u','.','p','k' };
		static int a_rol[3] = { 0,0,0 };
		if (c < 9)
		{
			a_rol[2] = ++c;
			a_rol[1] = 0;
		}
		else
		{
			++c;
			a_rol[1] = c / 10;
			a_rol[2] = c % 10;
		}
		for (int i = 0; i < 3; i++)
			a_roll += a_rol[i] + '0';
		strcpy_s(a_id, a_roll.c_str());

		cout << "\t\t" << a_name << " ID " << a_id << endl;
		string smail;
		cin.ignore();
		for (int i = 0; i < 9; i++)
			smail += a_id[i];
		for (int i = 0; i < 9; i++)
			smail += u_mail[i];
		strcpy_s(a_uog_mail, smail.c_str());
		cout << "\t\t" << a_name << " UOG Mail " << a_uog_mail << endl;
		strcpy_s(a_password, a_id);
		cout << "\t\tDo you want to save n/y" << endl << "\t\t";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			write_admin_data();
	}
	
	admin_full_Display_data();
}//end function
void admin::write_admin_data()
{
	int n;
	ofstream fout, t;
	ifstream fin;
	fout.open("admin.txt", ios::app);
	fout.write((char*)this, sizeof(*this));
	fout.close();
	fin.open("a_count.txt", ios::in);
	fin >> n;
	n++;
	fin.close();
	t.open("a_count.txt");
	t << n;
	t.close();
}//End function
void admin::read_admin_data()
{
	ifstream fin;
	fin.open("admin.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		admin_full_Display_data();
		fin.read((char*)this, sizeof(*this));
	}
	fin.close();
}//End function
void admin::admin_search_data()
{
	int n = 0;
	string rol;
	cout << "\t\tEnter Admin ID " << endl << "\t\t";
	cin >> rol;
	ifstream fin;
	fin.open("admin.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		if (rol == a_id)
		{
			admin_full_Display_data();
			n++;
		}
		fin.read((char*)this, sizeof(*this));
	}
	fin.close();
	if (n==0)
		cout << "Wrong Id" << endl;
}//End function
void admin::admin_update_data()
{
	int c = 0;
	char ch;
	cout << "Enter Admin ID" << endl;
	string n;
	cin >> n;
	fstream f;
	f.open("admin.txt", ios::in | ios::out | ios::ate);
	f.seekg(0);
	f.read((char*)this, sizeof(*this));
	while (!f.eof())
	{
		if (n == a_id)
		{
			c++;
			do {
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t| Enter Admin Name          Press 1    | " << endl;
				cout << "\t\t| Enter Admin Father Name   Press 2    | " << endl;
				cout << "\t\t| Enter Admin Address       Press 3    | " << endl;
				cout << "\t\t| Enter Admin Gender        Press 4    | " << endl;
				cout << "\t\t| Enter Admin Date of Birth Press 5    | " << endl;
				cout << "\t\t| Enter Admin Mobile number Press 6    | " << endl;
				cout << "\t\t| Enter Admin Department    Press 7    | " << endl;
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t\t" << "Press any key to continue ::  ";
				cin >> ch;
				switch (ch)
				{
				case '1':
					cout << "\t\tEnter Admin Name" << endl << "\t\t";
					cin >> a_name;
					break;
				case '2':
					cout << "\t\tEnter Admin Father Name" << endl << "\t\t";
					cin >> af_name;
					break;
				case '3':
					cout << "\t\tEnter Admin Address" << endl << "\t\t";
					cin >> a_address;
					break;
				case '4':
					cout << "\t\tEnter Admin Gender" << endl << "\t\t";
					cin >> a_gender;
					break;
				case '5':
					cout << "\t\tEnter Admin Date of Birth" << endl << "\t\t";
					cin >> t_DOB;
					break;
				case '6':
					cout << "\t\tEnter Admin Mobile number" << endl << "\t\t";
					cin >> t_mobile_no;
					break;
				case '7':
					cout << "\t\tEnter Admin Qualification" << endl;
					cin >> a_qualification;
					break;
				default:
					cout << "wrong Entery" << endl;
				}
				cout << "\t\tDo You Want Again Student Update Data n/y" << endl;
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');
			int t = 0, siz = 0, n = 0;
			n = f.tellp();
			siz = sizeof(*this);
			t = n - siz;
			f.seekp(t);
			f.write((char*)this, sizeof(*this));
			break;
		}
		f.read((char*)this, sizeof(*this));
	}
	f.close();
	if (c==0)
		cout << "Wrong Id" << endl;
}//End function
void admin::admin_full_Display_data()
{
	cout << "\t\t*********************************************************************************" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Admin Name\t " << setw(15) << a_name << "\tFather Name\t" << setw(15) << af_name << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Date of Birth\t " << setw(15) << a_DOB << "\tGender\t\t" << setw(15) << a_gender << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Mobile Nomber\t " << setw(15) << a_mobile_no << "\tAddress\t\t" << setw(15) << a_address << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Qualification\t " << setw(15) << a_qualification << "\tUni mail\t" << setw(15) << a_uog_mail << " \t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " ID\t\t " << setw(15) << a_id << " Password\t " << setw(15) << a_password << "\t\t|" << endl;
	cout << "\t\t*********************************************************************************" << endl;
}//end function

