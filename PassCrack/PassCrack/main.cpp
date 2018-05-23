#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "vm.h"

#pragma warning(disable:4996)

char passwd_txt[257];
char passwd_enc[257];
char passwd_pst[257];
char SELECT_BYTECODE[20000] = { 0 };
Custom_CPU *vm;

void oaep_enc(char *passwd_txt, char *passwd_enc);
void oaep_dec(char *passwd_txt, char *passwd_enc);
void custom_table_encode(char *s);
void encrypt(char *data, int sel);
void decrypt(char *data, char *dst, int sel);


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
	GR ret = 0;
	FILE *f;

	memset(passwd_txt, 0, 257);
	memset(passwd_enc, 0, 257);
	memset(passwd_pst, 0, 257);
	if (!is_password_exist()) {
		f = fopen("password", "wb");
		strcpy(passwd_txt, "sejong_security_2017!");
		custom_table_encode(passwd_txt);
		oaep_enc(passwd_txt, passwd_enc);
		status = vm->execute(SELECT_BYTECODE);
		ret = vm->get_result();
		passwd_enc[256] = (5 * (rand() % 40)) + (ret % 5);
		encrypt(passwd_enc, passwd_enc[256]%5);
		memcpy(passwd_pst, passwd_enc, 257);
		fwrite(passwd_pst, sizeof(char), 257, f);
		fclose(f);
	}
	else {
		f = fopen("password", "rb");
		fread(passwd_pst, sizeof(char), 257, f);
		fclose(f);
	}
	return;
}


void load_bytecode()
{
	FILE *f;
	char *ptr = (char*)SELECT_BYTECODE;
	int ret, len = 0;
	f = fopen("Select_bytecode", "rb");
	while (1) {
		ret = fread(ptr, 1, 1024, f);
		if (ret <= 0)
			break;
		len += ret;
		ptr = ptr + ret;
	};
	fclose(f);	
}


int auth_rule(char *s)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	for (int i = 0; i<strlen(s); i++)
	{
		if (s[i] >= 48 && s[i] <= 57)//숫자
			a++;
		else if (s[i] >= 97 && s[i] <= 122)//영어 소문자 
			b++;
		else if (s[i] >= 65 && s[i] <= 90)//영어 대문자 
			b++;
		else if (s[i] == 60 || s[i] == 62 || s[i] == 63 || s[i] == 33 || s[i] == 95) //특수문자 
			c++;
		else
			d++;
	}

	if (a>0 && b>0 && c>0 && d == 0 && strlen(s) >= 8)
		return 1;
	else
		return 0;
}

int check_passwd(char *passwd) {
	char passwd_tmp[256];
	custom_table_encode(passwd);
	decrypt(passwd_pst, passwd_enc, passwd_pst[256]%5);
	oaep_dec(passwd_tmp, passwd_enc);
	if (!memcmp(passwd, passwd_tmp, 128))
		return 1;
	else
		return 0;
}

void Validate_Password()
{
	memset(passwd_txt, 0, 257);
	printf("input your password : ");
	scanf("%128s", passwd_txt);

	if (check_passwd(passwd_txt)) 
		printf("Password Correct!\n");
	else
		printf("Wrong Password\n");
	memset(passwd_txt, 0, 257);
}

void Change_Password()
{
	GR ret = 1;
	int status;

	while (ret) {
		memset(passwd_txt, 0, 257);
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
		if (check_passwd(passwd_txt)) {
			printf("Same password\n");
			return;
		}
		else {
			oaep_enc(passwd_txt, passwd_enc);
			status = vm->execute(SELECT_BYTECODE);
			ret = vm->get_result();
			passwd_enc[256] = (5 * (rand() % 40)) + (ret % 5);
			encrypt(passwd_enc, passwd_enc[256]%5);
			memcpy(passwd_pst, passwd_enc, 257);
			break;
		}
	}
}

void Quit()
{
	FILE *f;

	f = fopen("password", "wb");

	fwrite(passwd_pst, sizeof(char), 257, f);

	fclose(f);
	delete vm;
}

int main()
{
	char cmd = 0;
	vm = new Custom_CPU();
	load_password();
	load_bytecode();
	if (vm == NULL) {
		printf("vm allocation error\n");
		return -1;
	}
	srand(time(NULL));

	while (cmd != 'C') {
		printf("Sejong Password Manager:\n\n");
		printf("A. Change Password\n");
		printf("B. Validate Password\n");
		printf("C. Quit\n\n");
		printf("Enter your choice: ");
		cmd = 0;
		while (cmd<'A' || cmd>'C')
			scanf("%c", &cmd);

		switch (cmd) {
		case 'A': 
			Change_Password();
			break;
		case 'B':
			Validate_Password();
			break;
		case 'C': 
			Quit(); 
			break;
		default: 
			printf("Invaild Input, Try again…\n");
			break;
		}
	}
	return 0;
}