#pragma once
class UOG_MAIL
{

	char sender_id[20], reciver_id[20];
	char massage[100];

	void write_mail_data();
	void send_mail(char id[20]);
	void inbox_mail(char id[20]);
	void SEND_MAIL_TO_AN_OTHER(char sid[20]);
	void show_mail();
public:
	int uog_mail_system(char sid[20]);
};

