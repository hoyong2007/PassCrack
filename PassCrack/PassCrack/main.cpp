#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "vm.h"

#pragma warning(disable:4996)

char passwd_txt[128];
char passwd_enc[128];
char random_str[128];
void *CHANGE_BYTECODE = NULL;
void *VALIDATE_BYTECODE = NULL;
Custom_CPU *vm;

int validate_();
char* Change_();

int is_password_exist() // find password.txt 
{
	FILE *f;
	f = fopen("password", "r");
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
	int status;
	char *ret = (char*)0xDEADBEEF;

	memset(passwd_txt, 0, 128);
	memset(passwd_enc, 0, 128);
	if (!is_password_exist()) {
		FILE *f;
		f = fopen("password", "w+");
		strcpy(passwd_txt, "sejong_security_2017!");

		status = vm->execute(CHANGE_BYTECODE);
		if (!status) {
			printf("Somehing Wrong in vm\n");
			return;
		}
		ret = (char*)vm->get_result();

		if (ret == NULL) {
			printf("Error on setting password\n");
			return;
		}
		else {
			printf("Set password as default passwd.\n");
			memcpy(passwd_enc, ret, 128);
		}

		fwrite(passwd_enc, sizeof(char), 128, f);
		fclose(f);
	}
	else {
		FILE *f;
		f = fopen("password", "r");
		fread(passwd_enc, sizeof(char), 128, f);
		fclose(f);
	}
	return;
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
	int ret;
	int status;

	memset(passwd_txt, 0, 128);
	printf("input your password : ");
	scanf("%128s", passwd_txt);
	validate_();
	status = vm->execute(VALIDATE_BYTECODE);
	if (!status) {
		printf("Somehing Wrong in vm\n");
		return;
	}

	ret = vm->get_result();
	if (ret)
		printf("Password Correct!\n");
	else
		printf("Wrong password\n");
}

void Change()
{
	char *ret = (char*)0xDEADBEEF;
	int status;

	while (ret) {
		memset(passwd_txt, 0, 128);
		printf("Input new password : ");
		scanf("%128s", passwd_txt);

		if (auth_rule(passwd_txt) == 0) {
			printf("Try again, you must follow the making criteria\n\n");
			printf("it is at least 8 characters long\n");
			printf("it contains at least one letter\n");
			printf("it contains at least one digit\n");
			printf("it contains at least one of these four characters : <,>,_,?,!\n");
			passwd_txt[0] = '\0';
			return;
		}
		Change_();
		for (int i = 0; i<128; i++)
			random_str[i] = rand() % 128;

		status = vm->execute(CHANGE_BYTECODE);
		if (!status) {
			printf("Somehing Wrong in vm\n");
			return;
		}
		ret = (char*)vm->get_result();
		if (ret == NULL)
			printf("Same as previous password. Enter a new password.\n");
		else
			printf("Password Change Complete.\n");
	}
	memcpy(passwd_enc, ret, 128);
}

void Quit()
{
	FILE *f;

	f = fopen("password.txt", "w+");

	printf("contents : %s\n", passwd_enc);
	fwrite(passwd_enc, sizeof(char), 128, f);

	fclose(f);
	delete vm;
}

int main()
{
	char cmd = 0;
	load_password();
	vm = new Custom_CPU();
	srand(time(NULL));

	while (cmd != 'C') {
		printf("Sejong Password Manager:\n\n");
		printf("A. Change Password\n");
		printf("B. Validate Password\n");
		printf("C. Quit\n\n");
		printf("Enter your choice: ");

		scanf("%c", &cmd);

		switch (cmd) {
		case 'A': 
			Change();
			break;
		case 'B':
			Validate(); 
			break;
		case 'C': 
			Quit(); 
			break;
		default: 
			printf("Invaild Input, Try again…\n");
			break;
		}
		getchar();
	}
	return 0;
}