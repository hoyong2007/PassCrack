#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vm.h"

#pragma warning(disable:4996)

char buf_new_global[100];

int find() // find password.txt 
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

	/* --> file name search algorithm for find password.txt (long ver.)

	struct _finddata_t fd;
	long handle;
	int result = 1;

	char buf[100];
	getcwd(buf, 100);

	handle = _findfirst("*.txt",&fd);

	if(handle == -1){
	printf("error1\n");
	return 0;
	}

	while(result != -1){
	if(fd.name == "password.txt"){
	printf("file already exist\n");
	return 0;
	}
	else{
	printf("place for init()\n");
	return 1;
	}
	result = _findnext(handle,&fd);
	}
	return 0;
	*/
}

void init() //초기 암호파일 생성 
{

	if (find() == 1)
		return;

	FILE *f;
	f = fopen("password.txt", "w+");
	fprintf(f, "sejong_security_2017!");
	fclose(f);
}

int auth_password()
{
	FILE *f;
	char buf_input[100];
	char buf_get[100];

	printf("input your password : ");
	scanf("%s", buf_input);

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

	//   printf("DBG %s\n",s);

	for (int i = 0; i<strlen(s); i++)
	{

		if (s[i] >= 48 && s[i] <= 57)//숫자
			a++;

		else if (s[i] >= 97 && s[i] <= 122)//영어 소문자 
			b++;

		else if (s[i] >= 65 && s[i] <= 90)//영어 대문자 
			b++;

		else if (s[i] == 60 || s[i] == 62 || s[i] == 63 || s[i] == 21 || s[i] == 95) //특수문자 
			c++;
	}

	if (a>0 && b>0 && c>0 && strlen(s) >= 8)
		return 1;
	else
		return 0;
}

void validate()
{

	if (auth_password() == 0) {
		printf("Invaild password, Try again...\n");
		return;
	}
	else
		printf("Login success\n");
}

void change()
{

	if (auth_password() == 0) {
		printf("Invaild password, Try again...\n");
		return;
	}
	printf("input new password : ");

	scanf("%s", buf_new_global);

	if (auth_rule(buf_new_global) == 0) {
		printf("Try again, you must follow the making criteria\n\n");
		printf("it is at least 8 characters long\n");
		printf("it contains at least one letter\n");
		printf("it contains at least one digit\n");
		printf("it contains at least one of these four characters : <,>,_,?,!\n");
		buf_new_global[0] = '\0';
		return;
	}
	return;
}

void terminate()
{
	FILE *f;

	f = fopen("password.txt", "w+");

	printf("contents : %s\n", buf_new_global);
	fprintf(f, "%s", buf_new_global);

	fclose(f);
	exit(0);
}

int main()
{
	char cmd;
	init();
	while (1) {

		printf("Sejong Password Manager:\n\n");
		printf("A. Change Password\n");
		printf("B. Validate Password\n");
		printf("C. Quit\n\n");
		printf("Enter your choice: ");

		scanf("%c", &cmd);

		switch (cmd) {

		case 'A': change(); break;
		case 'B': validate(); break;
		case 'C': terminate(); break;

		default: printf("Invaild Input, Try again…\n"); break;
		}
		getchar();
	}
	return 0;
}