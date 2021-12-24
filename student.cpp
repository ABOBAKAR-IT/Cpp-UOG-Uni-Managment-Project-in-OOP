#include "student.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cstring>
#include<Windows.h>
#include"time_table.h"
using namespace std;
student::student()
{
	
	this->s_name[20] =  'a' ; this->f_name[20] =  'a'; this->address[20] =  'a' ; this->gender[20] =  'a' ; this->DOB[20] = 'a' ; this->mobile_no[20] = 'a' ; this->inter_marks[20] = 'a' ;
	this->clas[20] =  'a' ; this->roll_no[20] =  'a' ; this->uog_mail[25] =  'a' ; this->password[20] =  'a' ;//Student data
	 GPA = 0.0, CGPA = 0.0;
	 for (int i = 0; i < 6; i++)
		 for (int j = 0; j < 4; j++)
		 {
			 subject[i].QUIZ[j] = 0;
			 subject[i].ASSIGNMENT[j] = 0;
		 }
	 for (int i = 0; i < 6; i++)
	 {
		 subject[i].FINAL = 0;
		 subject[i].MID = 0;
		 subject[i].presentaton = 0;
		 subject[i].ATTENDENCE=0;
		 subject[i].TOTAL_MARKS = 0;
		 subject[i].GRADE[4] = ' ';
	 }
}
int student::student_management()
{
	char ch;
	do {
		system("cls");
		cout << "\t\t  **********************************************" << endl;
		cout << "\t\t  | *WELLCOME TO UOG STUDENT MANEGMENT SYSTEM* |" << endl;
		cout << "\t\t  **********************************************" << endl;
		cout << "\t\t\t************************************" << endl;
		cout << "\t\t\t|" << " Student Insert Data Press 1      |" << endl;
		cout << "\t\t\t|" << " Student Search Data Press 2      |" << endl;
		cout << "\t\t\t|" << " Student Update Data Press 3      |" << endl;
		cout << "\t\t\t|" << " Student Delete Data Press 4      |" << endl;
		cout << "\t\t\t|" << " Student Full Display Data Press 5|" << endl;
		cout << "\t\t\t|" << " BACK Press 6                     |" << endl;
		cout << "\t\t\t************************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";
		
		cin >> ch;
		
		switch (ch)
		{
		case '1':
			student_insert_data();
			break;
		case '2':
			 student_search_data();
			break;
		case '3':
			 student_update_data();
			break;
		case '4':
			 student_delete_data();
			 break;
		case '5':
		{
			read_student_data();
			break; 
		}
		case '6':
		{
			
			return 0;
		}
		
		default :
			cout << "Wrong entery"<<endl;

		}

		cout << "Do You Want Again UOG STUDENT MANEGMENT SYSTEM n/y" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}//End function
void student::student_insert_data()
{
	static int c;
	int n;
	ifstream f;
	f.open("count.txt", ios::in); 
	f >> c;
	n = c;
	f.close();
	cout << n << endl;
	cout << "    Enter Student Name" << endl<<"    ";
	cin >> s_name;
	cout << "    Enter Student Father Name" << endl << "    ";
	cin >> f_name;
	cout << "    Enter Student Address" << endl << "    ";
	cin >> address;
	cout << "    Enter Student Gender" << endl << "    ";
	cin >> gender;
	cout << "    Enter Student Date of Birth" << endl << "    ";
	cin >> DOB;
	cout << "    Enter Student Inter Marks" << endl << "    ";
	cin >> inter_marks;
	cout << "    Enter Student Mobile number" << endl << "    ";
	cin >> mobile_no;
	cout << "    Enter Student Class" << endl << "    ";
	cin >> clas;
	string t_roll = "19014156-";
	char u_mail[11] = { '@','u','o','g','.','e','d','u','.','p','k' };
	static int t_rol[3] = { 0,0,0 };
	if (c < 9)
	{
		t_rol[2]=++c;
		t_rol[1]=0;
	}
	else
	{
		++c;
		t_rol[1]=c/10;
		t_rol[2]=c%10;
	}
	for (int i = 0; i < 3; i++)
		t_roll += t_rol[i] + '0';
strcpy_s(roll_no,t_roll.c_str());
	cout <<"   "<< s_name << " Roll Number   " << roll_no << endl;
	string smail;
	cin.ignore();
	for(int i=0;i<12;i++)
	smail += roll_no[i];
	for (int i = 0; i < 11; i++)
	smail += u_mail[i];
	strcpy_s(uog_mail, smail.c_str());	
	cout <<"   "<< s_name << " UOG Mail   " << uog_mail << endl;
	strcpy_s(password, roll_no);
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 4; j++)
	{
		subject[i].QUIZ[j]=0;
		subject[i].ASSIGNMENT[j]=0;
	}
	for (int i = 0; i < 6; i++)
	{
		subject[i].FINAL=0;
		subject[i].MID=0;
		subject[i].presentaton=0;
		subject[i].ATTENDENCE;
	}
	
	cout << "Do you want to save n/y" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		write_student_data();
	student_full_Display_data();

}//End function
void student::student_full_Display_data()
{
	cout << "\t\t*********************************************************************************" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Student Name\t" << setw(15) << s_name << "\t\tFather Name\t" << setw(15) << f_name << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Date of Birth\t" << setw(15) << DOB << "\t\tGender\t\t" << setw(15) << gender << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Mobile Nomber\t" << setw(15) << mobile_no << "\t\tAddress\t\t" << setw(15) << address << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Inter Marks\t" << setw(15) << inter_marks << "\t\tDepartment\t" << setw(15) << clas << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Roll Nomber\t" << setw(15) << roll_no << "\t\tUni mail\t" << setw(15) << uog_mail << " |" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " GPA\t\t" << setw(15) << GPA << "\t\tCGPA\t\t" << setw(15) << CGPA << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Password\t" << setw(15) << password << "\t\t\t\t\t\t\t|" << endl;
	cout << "\t\t*********************************************************************************" << endl;
}//end function
void student::write_student_data()
{
	int n;
	ofstream fout, t;
	ifstream fin;
	fout.open("student.txt", ios::app);
	fout.write((char*)this, sizeof(*this));
	fout.close();
	fin.open("count.txt", ios::in);
	fin >> n;
	n++;
	fin.close();
	t.open("count.txt");
	t << n;
	t.close();
}//End function
void student::read_student_data()
{
	ifstream fin;
	fin.open("student.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{  
	
	student_full_Display_data();
		fin.read((char*)this, sizeof(*this));
	}
	fin.close();
}//End function
void student::student_search_data()
{
	int n = 0;
	string rol;
	cout << "    Enter Student ID or Roll No" << endl<<"    ";
	cin >> rol;
	ifstream fin;
	fin.open("student.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		if (rol == roll_no)
		{
			student_full_Display_data();
			n++;
		}
		fin.read((char*)this, sizeof(*this));
	}
	if (n==0)
		cout << "Wrong Roll No" << endl;
	fin.close();
}//End function
void student::student_update_data()
{
	int c = 0;
	char ch;
	cout << "    Enter Roll No" << endl<<endl<<"   ";
	string n;
	cin >> n;
	fstream f;
	f.open("student.txt", ios::in | ios::out | ios::ate);
	f.seekg(0);
	f.read((char*)this, sizeof(*this));
	while (!f.eof())
	{
		if (n == roll_no)
		{
			c++;
			do {
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t| Enter Student Name          Press 1   | " << endl;
				cout << "\t\t| Enter Student Father Name   Press 2   | " << endl;
				cout << "\t\t| Enter Student Address       Press 3   | " << endl;
				cout << "\t\t| Enter Student Gender        Press 4   | " << endl;
				cout << "\t\t| Enter Student Date of Birth Press 5   | " << endl;
				cout << "\t\t| Enter Student Mobile number Press 6   | " << endl;
				cout << "\t\t| Enter Student Department    Press 7   | " << endl;
				cout << "\t\t| Enter Student New Password  Press 8   | " << endl;
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t\t" << "Press any key to continue ::  ";
				
				
				cin >> ch;
				switch (ch)
				{
				case '1':
					cout << "\t\tEnter Student Name" << endl<<"\t\t";
					cin >> s_name;
					break;
				case '2':
					cout << "\t\tEnter Student Father Name" << endl << "\t\t";
					cin >> f_name;
					break;
				case '3':
					cout << "\t\tEnter Student Address" << endl << "\t\t";
					cin >> address;
					break;
				case '4':
					cout << "\t\tEnter Student Gender" << endl << "\t\t";
					cin >> gender;
					break;
				case '5':
					cout << "\t\tEnter Student Date of Birth" << endl << "\t\t";
					cin >> DOB;
					break;
				case '6':
					cout << "\t\tEnter Student Mobile number" << endl << "\t\t";
					cin >> mobile_no;
					break;
				case '7':
					cout << "\t\tEnter Student Department" << endl << "\t\t";
					cin >> clas;
					break;
				case '8':
					cout << "\t\t Enter Student New Password " << endl << "\t\t";
					cin >> password;
					break;
				default:
					cout << "Wrong Entery" << endl;
				}
				cout << "\t\tDo You Want Again Student Update Data n/y" << endl;
				cin >> ch;
			} while (ch=='y' || ch == 'Y');

			int t = 0,siz=0,n=0;
			n=f.tellp();
			siz = sizeof(*this);
			t = n - siz;
			f.seekp(t);
			f.write((char*)this, sizeof(*this));
			break;
		}
		f.read((char*)this, sizeof(*this));
	}
	if(c==0)
		cout << "Wrong Roll No" << endl;
	f.close();
}//End function
void student::student_delete_data()
{
	int c=0;
	cout << "\t\tEnter Roll No" << endl << "\t\t";
	string n;
	cin >> n;
	ifstream fin;
	ofstream fout;
	fin.open("student.txt", ios::in);
	fout.open("temp.txt", ios::app);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		if (n != roll_no)
		{
			fout.write((char*)this, sizeof(*this));
			
		}
		if (n == roll_no)
		{
			cout << "\t\t" << n << " Data Delete" << endl;
			c = 2;
		}
		fin.read((char*)this, sizeof(*this));
	}
	if (c == 0)
		cout <<"\t\t"<<n<< "  No Data In File" << endl;
	fin.close();
	fout.close();
	remove("student.txt");
	rename("temp.txt", "student.txt");
}//End function
int student::student_login(char id[20], char pwsd[20])
{
	time_table tt;
	int n = 0;
	ifstream fin;
	fin.open("student.txt", ios::in);
	fin.read((char*)this, sizeof(*this));
	while (!(fin.eof()))
	{
		if (!(strcmp(id,roll_no)))
			if(!( strcmp(pwsd,password)))
		{
			n = 10;
			break;
		}
		fin.read((char*)this, sizeof(*this));
	}
	fin.close();

	if (n == 10)
	{
		char ch;
		do{
		system("cls");
		cout << "\t\t  ***********************************************" << endl;
		cout << "\t\t  |    *WELLCOME TO UOG LMS  "<< s_name <<" * \t|" << endl;
		cout << "\t\t  ***********************************************" << endl;
		cout << "\t\t\t***********************************" << endl;
		cout << "\t\t\t|" << " COURSE LIST  \t\t Press 1  |" << endl;
		cout << "\t\t\t|" << " GPA          \t\t Press 2  |" << endl;
		cout << "\t\t\t|" << " TIME TABLE   \t\t Press 3  |" << endl;
		cout << "\t\t\t|" << " MAIL         \t\t Press 4  |" << endl;
		cout << "\t\t\t|" << " Exit         \t\t Press 5  |" << endl;
		cout << "\t\t\t***********************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{   labal:
			system("cls");
			cout << "\t\t*********************************************" << endl;
			cout << "\t\t|  *              COURSE LIST               |" << endl;
			cout << "\t\t*********************************************" << endl;
			cout << "\t\t\t**********************************" << endl;
			cout << "\t\t\t|" << " OOP          \t\tPress 1   |" << endl;
			cout << "\t\t\t|" << " IS           \t\tPress 2   |" << endl;
			cout << "\t\t\t|" << " DLD          \t\tPress 3   |" << endl;
			cout << "\t\t\t|" << " ENGLISH      \t\tPress 4   |" << endl;
			cout << "\t\t\t|" << " ACCOUNTING   \t\tPress 5   |" << endl;
			cout << "\t\t\t|" << " ISLAMYAT     \t\tPress 6   |" << endl;
			cout << "\t\t\t**********************************" << endl << endl << endl;
			cout << "\t\t\t" << "Press any key to continue ::  ";
			cin >> ch;
			int nn = ch - '0';
			if (nn > 6)
			{
				cout << "\t\t\t RONG ENTERY" << endl;
				Sleep(1000);
				goto labal;
			}
			else
			course_data(nn);
		}
			break;
		case '2':
			U_GPA();
			break;
		case '3':
			tt.read_time_table_data();
			break;
		case '4':
			MAIL.uog_mail_system(roll_no);
			break;
		case '5':
			return 0;
			break;
		default:
			cout << "\t\tWrong entery" << endl;

		}
		 
		cout << "\t\tDo You Want Again UOG LMS Main Page n/y" << endl << "\t\t";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	}
	else
	{
		cout << "\t\tWrong ID Try Again \n";
	}
}
int student::edit_student_subject_data(int s)
{

	char ch;
	cout << "\t\tEnter Roll No" << endl << "\t\t";
	string n;
	cin >> n;
	fstream f;
	f.open("student.txt", ios::in | ios::out | ios::ate);
	f.seekg(0);
	f.read((char*)this, sizeof(*this));
	while (!f.eof())
	{
		if (n == roll_no)
		{
		   do {
			   system("cls");
			   cout << "\t\t************************************************" << endl;
				cout << "\t\t| Enter Student QUIZ MARKS           Press 1  |" << endl;
				cout << "\t\t| Enter Student ASSIGNMENT Number    Press 2  |" << endl;
				cout << "\t\t| Enter Student PRESENTATION         Press 3  |" << endl;
				cout << "\t\t| Enter Student MID                  Press 4  |" << endl;
				cout << "\t\t| Enter Student FINAL                Press 5  |" << endl;
				cout << "\t\t| Enter Student Attendence           Press 6  |" << endl;
				cout << "\t\t| BACK                               Press 7  |" << endl;
				cout << "\t\t************************************************" << endl;
				cout << "\t\t\t" << "Press any key to continue ::  " << endl<< "\t\t";
				cin >> ch;
				switch (ch)
				{
				case '1':
				{   do {
					system("cls");
					cout << "\t\tEnter 1 QUIZ MARKS Press 1" << endl;
					cout << "\t\tEnter 2 QUIZ MARKS Press 2" << endl;
					cout << "\t\tEnter 3 QUIZ MARKS Press 3" << endl;
					cout << "\t\tEnter 4 QUIZ MARKS Press 4" << endl;
					cout << "\t\tPress any key to continue ::  " << "\t\t";
					cin >> ch;
					switch (ch)
					{
					case '1':
						cout << "Enter 1 QUIZ MARKS" << endl << "\t\t";
						cin >> subject[s].QUIZ[0];
						break;
					case '2':
						cout << "Enter 2 QUIZ MARKS" << endl << "\t\t";
						cin >> subject[s].QUIZ[1];
						break;
					case '3':
						cout << "\t\tEnter 3 QUIZ MARKS" << endl << "\t\t";
						cin >> subject[s].QUIZ[2];
						break;
					case '4':
						cout << "\t\tEnter 4 QUIZ MARKS" << endl << "\t\t";
						cin >> subject[s].QUIZ[3];
						break;
					}//switch end
					cout << "\t\tDo you want again Edit QUIZ MARKS n/y" << endl << "\t\t";
					cin >> ch;
				} while (ch == 'y' || ch == 'Y');//do end
				break;
				}//case 1 end
				case '2':
				{
					do{
						system("cls");
					cout << "\t\tEnter 1 ASSIGNMENT MARKS Press 1" << endl;
					cout << "\t\tEnter 2 ASSIGNMENT MARKS Press 2" << endl;
					cout << "\t\tEnter 3 ASSIGNMENT MARKS Press 3" << endl;
					cout << "\t\tEnter 4 ASSIGNMENT MARKS Press 4" << endl;
					cout << "\t\tPress any key to continue ::  ";
					cin >> ch;
					switch (ch)
					{
					case '1':
						cout << "\t\tEnter 1 ASSIGNMENT MARKS" << endl << "\t\t";
						cin >> subject[s].ASSIGNMENT[0];
						break;
					case '2':
						cout << "\t\tEnter 2 ASSIGNMENT MARKS" << endl << "\t\t";
						cin >> subject[s].ASSIGNMENT[1];
						break;
					case '3':
						cout << "\t\tEnter 3 ASSIGNMENT MARKS" << endl << "\t\t";
						cin >> subject[s].ASSIGNMENT[2];
						break;
					case '4':
						cout << "\t\tEnter 4 ASSIGNMENT MARKS" << endl << "\t\t";
						cin >> subject[s].ASSIGNMENT[3];
						break;
					}//switch end
					cout << "\t\tDo you want again Edit ASSIGNMENT MARKS n/y" << endl << "\t\t";
					cin >> ch;
					} while (ch == 'y' || ch == 'Y');//do end
					break;
				}//case 2 end
				case '3':
				{
					cout << "\t\tEnter Student PRESENTATION marks" << endl << "\t\t";
					cin >> subject[s].presentaton;
					break;
				}
				case'4':
				{
					cout << "\t\tEnter Student MID marks" << endl << "\t\t";
					cin >> subject[s].MID;
					break;
				}
				case'5':
				{
					cout << "\t\tEnter Student FINAL marks" << endl << "\t\t";
					cin >> subject[s].FINAL;
					break;
				}
				case'6':
				{
					cout << "\t\tEnter Student Attendence" << endl << "\t\t";
					cin >> subject[s].ATTENDENCE;
					break;
				}
				case'7':
				{
					return 0;
					break;
				}
				}// first switch end
				cout << "\t\tDo you want again Edit Student Data n/y" << endl << "\t\t";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');//do end

			int t = 0, siz = 0, n = 0;
			n = f.tellp();
			siz = sizeof(*this);
			t = n - siz;
			f.seekp(t);
			f.write((char*)this, sizeof(*this));
			break;
		}//if end
		f.read((char*)this, sizeof(*this));
	}//while end
	f.close();
}//end funtion 
void student::course_data(int N)
{
	N = N - 1;
	
	cout << "\t|****************************************************************************************************" << endl;
	cout <<setiosflags(ios::left)<<"\t|" << setw(20) <<roll_no<< setw(20)<<"|   ASSIGNMENT" << setw(20) <<"|       QUIZ" << setw(20) << "|   PRESENTATION " << setw(10) << " | MID " << setw(10) << " | FINAL |" << endl;
	cout << "\t|---------------------------------------------------------------------------------------------------|" << endl;
	cout << setiosflags(ios::left)<<"\t|" << setw(20) <<" "<< setw(5) << "| A1 " << setw(5) << "| A2 |" << setw(5) << " A3 |" << setw(5) << " A4 |" << setw(5) << " Q1 |" << setw(5) << " Q2 |" << setw(5) << " Q3 |" << setw(5) << " Q4 |" << setw(20) <<"      P1 " << setw(10) << "|  M1  " << setw(10) << "|  F1   |" << endl;
	cout << setiosflags(ios::left)<<"\t|" << setw(20) << "Aggregate Weightage" << setw(5) << "| 10 " << setw(5) << "| 10 |" << setw(5) << " 10 |" << setw(5) << " 10 |" << setw(5) << " 10 |" << setw(5) << " 10 |" << setw(5) << " 10 |" << setw(5) << " 10 |" << setw(20) << "      10 " << setw(10) << "|  25  " << setw(10) << "|  50   |" << endl;
	cout << setiosflags(ios::left)<<"\t|" << setw(20) << "Aggregate Marks" << "| " << setw(3) <<subject[N].ASSIGNMENT[0] << "| " << setw(3) << subject[N].ASSIGNMENT[1] <<"| " << setw(3)<< subject[N].ASSIGNMENT[2] <<"| " << setw(3)<< subject[N].ASSIGNMENT[3] <<"| " << setw(3)<<subject[N].QUIZ[0]<<"| " << setw(3) <<subject[N].QUIZ[1]<<"| " << setw(3) <<subject[N].QUIZ[2]<<"| " << setw(3) << subject[N].QUIZ[3] <<"|     " << setw(15)<< subject[N].presentaton << "| " << setw(8) <<subject[N].MID<<"| " << setw(6) << subject[N].FINAL <<"|" << endl;
	cout << "\t|---------------------------------------------------------------------------------------------------|" << endl;
	cout << setiosflags(ios::left) << "\t|" << setw(20) << "Student Attendence" << setw(5) << subject[N].ATTENDENCE <<"\t\t\t\t\t\t\t\t\t    |"<< endl;
	cout << "\t|---------------------------------------------------------------------------------------------------|" << endl;
}
void student::U_GPA ()
{
	
	float ass[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 }, qz[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 }, Credit_Hours[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 }, TOTAL_Credit_Hours=0.0;
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << endl;
		for (int j = 0; j < 4; j++)
		{
			
			ass[i] = ass[i] + subject[i].ASSIGNMENT[j];
			qz[i]  = qz[i] + subject[i].QUIZ[j];
		}
		
		ass[i] = (ass[i] * 10) / 40;
		qz[i]  = (qz[i] * 5) / 40;
		subject[i].TOTAL_MARKS = ass[i] + qz[i] + subject[i].presentaton + subject[i].MID + subject[i].FINAL;
	
		if (subject[i].TOTAL_MARKS <= 100.0 && subject[i].TOTAL_MARKS >= 84.5)
		{
			string gr = "A+";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else	if (subject[i].TOTAL_MARKS <= 84.0 && subject[i].TOTAL_MARKS >= 79.5)
		{
			string gr = "A";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else	if (subject[i].TOTAL_MARKS <= 79.0 && subject[i].TOTAL_MARKS >= 74.5)
		{
			string gr = "B+";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else	if (subject[i].TOTAL_MARKS <= 74.0 && subject[i].TOTAL_MARKS >= 69.5)
		{
			string gr = "B";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else	if (subject[i].TOTAL_MARKS <= 69.0 && subject[i].TOTAL_MARKS >= 64.5)
		{
			string gr = "B-";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else	if (subject[i].TOTAL_MARKS <= 64.0 && subject[i].TOTAL_MARKS >= 59.5)
		{
			string gr = "C+";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else	if (subject[i].TOTAL_MARKS <= 59.0 && subject[i].TOTAL_MARKS >= 54.5)
		{
			string gr = "C";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else	if (subject[i].TOTAL_MARKS <= 54.0 && subject[i].TOTAL_MARKS >= 49.5)
		{
			string gr = "D";
			strcpy_s(subject[i].GRADE, gr.c_str());
		}
		else
		{
			if (subject[i].TOTAL_MARKS < 49.5 && subject[i].TOTAL_MARKS > 10)
			{
				string gr = "F";
				strcpy_s(subject[i].GRADE, gr.c_str());
			}
			else
			{
				string gr = "0";
				strcpy_s(subject[i].GRADE, gr.c_str());
			}
		}
		if (subject[i].GRADE=="A+")
		{
			Credit_Hours[i] = 4.0 * 4.0;
		}
		else if (subject[i].GRADE == "A")
		{
			Credit_Hours[i] = 3.7 * 4.0;
		}
		else if (subject[i].GRADE == "B+")
		{
			Credit_Hours[i] = 3.4 * 4.0;
		}
		else if (subject[i].GRADE == "B")
		{
			Credit_Hours[i] = 3.0 * 4.0;
		}
		else if (subject[i].GRADE == "B-")
		{
			Credit_Hours[i] = 2.5 * 4.0;
		}
		else if (subject[i].GRADE == "C+")
		{
			Credit_Hours[i] = 2.0 * 4.0;
		}
		else if (subject[i].GRADE == "C")
		{
			Credit_Hours[i] = 1.5 * 4.0;
		}
		else if (subject[i].GRADE == "D")
		{
			Credit_Hours[i] = 1.0 * 4.0;
		}
		else 
		{
			Credit_Hours[i] = 0.0 * 4.0;
		}

		TOTAL_Credit_Hours += Credit_Hours[i];
		
	}//OUTER FOR LOOP
	GPA = TOTAL_Credit_Hours * 4 / 72;
	CGPA = GPA;
	show_GPA();
}//FUNCTION END
void student::show_GPA()
{
	cout << "\t\t\t ****************************************************************************" << endl;
	cin.ignore();
	cout <<"\t\t\t "<< setiosflags(ios::left) << setw(15) << "| COURSE CODE " << setw(25) << "| SUBJECT "           << setw(6) << "| MARKS " << setw(8) << " | GRADE" << setw(10) << "    | Credit Hours |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| IT106  "      << setw(25) << "|  OOP  "                      << "| " << setw(6)  << setprecision(2) << subject[0].TOTAL_MARKS << " | " << setw(8)  << subject[0].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| IT363  "      << setw(25) << "|  Information Systems   "     << "| " << setw(6)  << setprecision(2) << subject[1].TOTAL_MARKS << " | " << setw(8)  << subject[1].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| IT151  "      << setw(25) << "|  DLD  "                      << "| " << setw(6)  << setprecision(2) << subject[2].TOTAL_MARKS << " | " << setw(8)  << subject[2].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| ENG102 "      << setw(25) << "|  ENGLISH  "                  << "| " << setw(6)  << setprecision(2) << subject[3].TOTAL_MARKS << " | " << setw(8)  << subject[3].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| MGT205 "      << setw(25) << "|  Accounting   "              << "| " << setw(6)  << setprecision(2) << subject[4].TOTAL_MARKS << " | " << setw(8)  << subject[4].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| ISL100 "      << setw(25) << "|  Islamic Studies  "          << "| " << setw(6)  << setprecision(2) << subject[5].TOTAL_MARKS << " | " << setw(8)  << subject[5].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t ****************************************************************************" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(10) << "| GPA      " << setw(30) << GPA << setw(20) << "| CGPA" << setw(14) << CGPA <<" |"<< endl;
	cout << "\t\t\t ****************************************************************************" << endl;
}
