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
	printf("===========캘린더 메뉴==============\n");
	printf("------------------------------------\n");
	printf("1. 초기화\n");
	printf("2. 이번 달 일정 추가\n");
	printf("3. 이번 달 일정 탐색\n");
	printf("4. 이번 달 일정 변경\n");
	printf("5. 캘린더 종료\n");
	printf("------------------------------------\n");
	printf("항목을 입력하세요 : ");

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
			printf("초기화 완료!!\n\n");
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

	printf("날짜 : ");
	gets_s(buffer, MAX);
	strcpy(p->date, buffer);

	printf("일정,시간 1 : ");
	gets_s(buffer, MAX);
	strcpy(p->schedule1, buffer);

	printf("일정,시간 2 : ");
	gets_s(buffer, MAX);
	strcpy(p->schedule2, buffer);

	printf("일정,시간 3 : ");
	gets_s(buffer, MAX);
	strcpy(p->schedule3, buffer);

	printf("추가되었습니다!\n\n");
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
		printf("정보가 없습니다.\n\n");
	}
	while (1)
	{
		if (p == NULL)
			break;

		printf("날짜 : %s\n", p->date);
		printf("일정,시간 1 : %s\n\n", p->schedule1); 
		printf("일정,시간 2 : %s\n\n", p->schedule2);
		printf("일정,시간 3 : %s\n\n", p->schedule3);
		p = p->link;

	}
	menu();

}
void Change() 
{
	printf("변경할 날짜를 입력하세요 : ");
	getchar();
	gets_s(buffer, MAX);
	p = head;

	while (1)
	{
		char n;

		if (p == NULL)
		{
			printf("찾는 날짜가 없습니다.\n\n");
			break;
		}
		if (strcmp(buffer, p->date) != 0)
		{
			p = p->link;
		}
		else
		{
			printf("변경할 일정을 입력하세요 : ");
			gets_s(buffer, MAX);
			strcpy(p->schedule1, buffer);

			gets_s(buffer, MAX);
			strcpy(p->schedule2, buffer);

			gets_s(buffer, MAX);
			strcpy(p->schedule3, buffer);
			

			

			printf("변경 완료!\n\n");
			break;
		}

	}

	menu();
}