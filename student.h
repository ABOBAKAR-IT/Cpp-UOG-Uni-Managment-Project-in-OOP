#pragma once
#include"UOG_MAIL.h"
class student 
{
	struct subject_marks
	{
		float QUIZ[4];
		float ASSIGNMENT[4];
		float MID;
		float FINAL;
		float presentaton;
		int ATTENDENCE;
		float TOTAL_MARKS;
		float MARKS;
		char GRADE[4];
	};
	subject_marks subject[6];
	
	char s_name[20], f_name[20], address[20], gender[20], DOB[20], mobile_no[20], inter_marks[20];
	char clas[20], roll_no[20], uog_mail[25], password[20];//Student data
	float GPA = 0.0, CGPA = 0.0;
	UOG_MAIL MAIL;
	void student_insert_data();
		void student_search_data();
		void student_update_data();
		void student_delete_data();
	void student_full_Display_data();
	void write_student_data();
	void read_student_data();
	void course_data(int N);
	void U_GPA();
	void show_GPA();
protected:
	int edit_student_subject_data(int s);
public:
	student();
	int student_management();
	int student_login(char id[20], char pwsd[20]);
};

