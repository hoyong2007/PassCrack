#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vm.h"

#pragma warning(disable:4996)

char buf_new_global[100];
char passwd_txt[128];
char passwd_enc[128];

int is_password_exist() // find password.txt 
{
	FILE *f;
	f = fopen("password.txt", "r");
	if (f == NULL) {
		return 0; // password.txt doesn't exist -> init function progress
	}
	else {
		fclose(f);
		return 1; // password.txt already exist -> main function progress
	}
}


void load_password() //초기 암호파일 생성 
{
	if (is_password_exist()) {
		FILE *f;
		f = fopen("password.txt", "w+");
		strcpy(passwd_txt, "sejong_security_2017!");

		/*
		enc passwd_txt
		*/

		fprintf(f, passwd_enc);
		fclose(f);
	}
	else {
		FILE *f;
		f = fopen("password.txt", "r");
		fscanf(f, "%s", passwd_enc);
		fclose(f);
	}
	return;
}


int auth_password()
{
	FILE *f;
	char buf_input[100];
	char buf_get[100];

	printf("input your password : ");
	scanf("%s", passwd_txt);

	f = fopen("password.txt", "r+");
	fscanf(f, "%s", buf_get);

	if (strcmp(buf_input, buf_get) == 0)
		return 1;
	else
		return 0;
}

int auth_rule(char *s)
{
	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i<strlen(s); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')//숫자
			a++;
		else if (s[i] >= 'a' && s[i] <= 'z')//영어 소문자 
			b++;
		else if (s[i] >= 'A' && s[i] <= 'Z')//영어 대문자 
			b++;
		else if (s[i] == '<' || s[i] == '>' || s[i] == '?' || s[i] == '!' || s[i] == '_') //특수문자 
			c++;
	}

	if (a && b && c && strlen(s)>=8)
		return 1;
	else
		return 0;
}

void Validate()
{
	if (auth_password() == 0) {
		printf("Invaild password, Try again...\n");
		return;
	}
	else
		printf("Login success\n");
}

void Change()
{
	if (auth_password() == 0) {
		printf("Invaild password, Try again...\n");
		return;
	}
	printf("input new password : ");

	scanf("%s", passwd_txt);

	if (auth_rule(passwd_txt) == 0) {
		printf("Try again, you must follow the making criteria\n\n");
		printf("it is at least 8 characters long\n");
		printf("it contains at least one letter\n");
		printf("it contains at least one digit\n");
		printf("it contains at least one of these four characters : <,>,_,?,!\n");
		passwd_txt[0] = '\0';
		return;
	}
	return;
}

void Quit()
{
	FILE *f;

	f = fopen("password.txt", "w+");

	printf("contents : %s\n", passwd_enc);
	fprintf(f, "%s", passwd_enc);

	fclose(f);
	exit(0);
}

int main()
{
	char cmd;
	load_password();
	while (1) {

		printf("Sejong Password Manager:\n\n");
		printf("A. Change Password\n");
		printf("B. Validate Password\n");
		printf("C. Quit\n\n");
		printf("Enter your choice: ");

		scanf("%c", &cmd);

		switch (cmd) {

		case 'A': Change(); break;
		case 'B': Validate(); break;
		case 'C': Quit(); break;

		default: printf("Invaild Input, Try again…\n"); break;
		}
		getchar();
	}
	return 0;
}