#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define _CRT_SECURE_NO_WARNINGS

typedef struct Node {
	
	char date[MAX];
	char tel[MAX];
	char schedule1[MAX];
	char schedule2[MAX];
	char schedule3[MAX];
	struct Node* link;
} Node;

Node* p = NULL;
Node* prev = NULL;
Node* head = NULL;
Node* next = NULL;

char buffer[MAX];

void menu();
void AllClear();
void Add();
void Search();
void Change();


int main()
{
	menu();

}
void menu()
{
	printf("===========Ķ���� �޴�==============\n");
	printf("------------------------------------\n");
	printf("1. �ʱ�ȭ\n");
	printf("2. �̹� �� ���� �߰�\n");
	printf("3. �̹� �� ���� Ž��\n");
	printf("4. �̹� �� ���� ����\n");
	printf("5. Ķ���� ����\n");
	printf("------------------------------------\n");
	printf("�׸��� �Է��ϼ��� : ");

	int num;
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
		AllClear();
		break;
	case 2:
		Add();
		break;
	case 3:
		Search();
		break;
	case 4:
		Change();
		break;
	case 5:
		exit(0);
		break;

	}
}
void AllClear()  
{
	p = head;
	while (1)
	{
		if (p == NULL)
		{
			printf("�ʱ�ȭ �Ϸ�!!\n\n");
			head = NULL;
			break;
		}
		next = p->link;
		free(p);
		p = next;
	}

	menu();
}
void Add() 
{
	getchar();
	p = (Node*)malloc(sizeof(Node));
	p->link = NULL;

	printf("��¥ : ");
	gets_s(buffer, MAX);
	strcpy(p->date, buffer);

	printf("����,�ð� 1 : ");
	gets_s(buffer, MAX);
	strcpy(p->schedule1, buffer);

	printf("����,�ð� 2 : ");
	gets_s(buffer, MAX);
	strcpy(p->schedule2, buffer);

	printf("����,�ð� 3 : ");
	gets_s(buffer, MAX);
	strcpy(p->schedule3, buffer);

	printf("�߰��Ǿ����ϴ�!\n\n");
	if (head == NULL)
		head = p;
	else
		prev->link = p;
	prev = p;
	menu();

}
void Search() 
{

	p = head;
	if (head == NULL)
	{
		printf("������ �����ϴ�.\n\n");
	}
	while (1)
	{
		if (p == NULL)
			break;

		printf("��¥ : %s\n", p->date);
		printf("����,�ð� 1 : %s\n\n", p->schedule1); 
		printf("����,�ð� 2 : %s\n\n", p->schedule2);
		printf("����,�ð� 3 : %s\n\n", p->schedule3);
		p = p->link;

	}
	menu();

}
void Change() 
{
	printf("������ ��¥�� �Է��ϼ��� : ");
	getchar();
	gets_s(buffer, MAX);
	p = head;

	while (1)
	{
		char n;

		if (p == NULL)
		{
			printf("ã�� ��¥�� �����ϴ�.\n\n");
			break;
		}
		if (strcmp(buffer, p->date) != 0)
		{
			p = p->link;
		}
		else
		{
			printf("������ ������ �Է��ϼ��� : ");
			gets_s(buffer, MAX);
			strcpy(p->schedule1, buffer);

			gets_s(buffer, MAX);
			strcpy(p->schedule2, buffer);

			gets_s(buffer, MAX);
			strcpy(p->schedule3, buffer);
			

			

			printf("���� �Ϸ�!\n\n");
			break;
		}

	}

	menu();
}