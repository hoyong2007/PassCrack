#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

char key[27] = "abcdefghijklmnopqrstuvwxyz";

void crypt(char *s) {

	int len, i;
	char key[27] = { "abcdefghijklmnopqrstuvwxyz" };
	char key1[54], key2[54], dkey[54], ds[54];
	len = strlen(s);

	// ��ȣȭ 
	for (i = 0; i<len; i++)   // key1 = string ^ �ʱ� key (�ʱ� Ű�� string ��ȣȭ)
		key1[i] = s[i] ^ key[i];
	key1[i] = NULL;

	for (i = 0; i<len; i++)
		key2[i] = key[i] ^ key1[i]; // key2 = �ʱ� key ^ key (��ȣȭ�� string���� �ʱ� Ű ��ȣȭ)
	key2[i] = NULL;

	strcat(key1, key2); // key1 + key2 

	len = strlen(key1);

	for (i = 0; i<len; i++) // ������ ���� : �ƽ�Ű���̺� ���� �ʰ��ż� %s�� �����ϸ� ���� �ٱ��� -> %c �� ����.. (�ӽù���)
		printf("%d", key1[i]);

	/*
	for(int i=0;i<len;i++){
	key1[i] = s[i]^len;
	}
	printf("key1 : %s\n",key1);

	for(int i=0;i<len;i++){
	key2[i] = key[26-i]^len;
	}
	printf("key2 : %s\n",key2);

	strcat(key1,key2);

	len = strlen(key1);
	for(int i=0;i<len;i++)
	printf("%d",key1[i]);
	*/

	// ��ȣȭ 

	for (int i = 0; i<len; i++) // �ʱ� Ű = key1 ^ key2
		dkey[i] = key1[i] ^ key2[i];

	for (int i = 0; i<len; i++) // string = �ʱ� key ^ key1
		ds[i] = dkey[i] ^ key1[i];

	printf("%s", ds);
}

int main2() {

	char buf_old[100];
	char buf_new[100];

	scanf("%s", buf_old);
	crypt(buf_old);

	return 0;
}