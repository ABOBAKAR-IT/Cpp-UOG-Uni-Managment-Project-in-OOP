#pragma once
#include<string>
#include<cstring>
using namespace std;
class time_table
{
protected:
	string lacture[5][3];
	string	day[5] = { {"MONDAY"},{"TUESDAY"},{"WEDNESDAY"},{"THERESDAY"},{"FRIDAY"} };
	char lac[20];
	void insert_time_table_data();
	void edit_time_table();
	void show_time_table();
	void write_time_table_data();
public:
    int time_table_managment();
	void read_time_table_data();
};
