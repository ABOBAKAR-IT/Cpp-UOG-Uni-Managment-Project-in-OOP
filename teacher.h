#pragma once
#include "student.h"
#include"UOG_MAIL.h"
class teacher : protected student 
{
    protected:
	char t_name[20], tf_name[20], t_address[20], t_gender[20], t_DOB[20], t_mobile_no[20], qualification[20];
	char t_subject[20], t_id[20], t_uog_mail[25], t_password[20];//Teacher data
	UOG_MAIL MAIL;
    private:
	void teacher_insert_data();
	void teacher_search_data();
	void teacher_update_data();
	void teacher_delete_data();
	void teacher_full_Display_data();
	void write_teacher_data();
	void read_teacher_data();
	void edit_student_data();
public:
	int teacher_management();
	int t_check_login(char id[12], char pwsd[12]);

};

