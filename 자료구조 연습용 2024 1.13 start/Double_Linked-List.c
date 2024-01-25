#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct NODE
{
	char data[64];
	struct NODE* Pre;
	struct NODE* Next;

} NODE;

NODE* pHead;
NODE* pTail;
int g_size;
int Is_empty()
{
	if (g_size == 0)
	{
		return 1;
	}
	else return 0;
}
void Init_List()
{
	pHead = (NODE*)malloc(sizeof(NODE));// malloc�� ��ȯ ���� ()���� ũ���� �ּ�
	pTail = (NODE*)malloc(sizeof(NODE));
	memset(pHead, 0, sizeof(NODE)); // ����ü�ȿ� �ִ� ������� �ʱ�ȭ ����
	memset(pTail, 0, sizeof(NODE));
	pHead->Next = pTail;
	pTail->Pre = pHead;
	g_size = 0;
}
void InsertHead(char* szdata)
{
	NODE *pNODE = (NODE*)malloc(sizeof(NODE));
	memset(pNODE, 0, sizeof(NODE));
	strcpy_s(pNODE->data, sizeof(pNODE->data), szdata);

	// pNODE �� �յ� ���� ����
	pNODE->Pre = pHead;
	pNODE->Next = pHead->Next;
	
	pHead->Next->Pre = pNODE; //�ճ�带 pNODE�� ����
	pHead->Next = pNODE; // ����带 pNODE�� ����
	g_size++;

}

void InsertTail(char* szdata)
{
	NODE* pNODE = (NODE*)malloc(sizeof(NODE));
	memset(pNODE, 0, sizeof(NODE));
	strcpy_s(pNODE->data, sizeof(pNODE->data), szdata);

	// pNODE �� �յ� ���� ����
	pNODE->Pre = pTail->Pre;
	pNODE->Next = pTail;

	pTail->Pre->Next = pNODE; //�ճ�带 pNODE�� ����
	pTail->Pre= pNODE; // ���ϳ�带 pNODE�� ����
	g_size++;
}

void Print_List()
{
	if (Is_empty())
	{
		return printf("List is emptied\n");
	}
	
	NODE* pNODE = pHead->Next;
	printf(" HEAD ->");
	for(int i=0; i<g_size; i++)
	{
		printf(" %s -> ", pNODE->data);
		pNODE = pNODE->Next;
	}
	printf(" TAIL \n");
}

NODE* Find_data(char * szdata)
{
	if (Is_empty()) 
	{
		printf("List is emptied \n");
		return 0;
	}
	NODE* pNODE = pHead->Next;
	
	for (int i = 0; i < g_size; i++)
	{
		if (strcmp(pNODE->data, szdata) == 0) { // ã�� ���
			printf("finding data : %s\n", szdata);
			return pNODE;
		}
		else pNODE = pNODE->Next; //pNODE->data���� �ٸ����
	}
	printf("��ã��\n");
	return 0; // ������ �ٵ��� �ƾ� ��ã�� ���


}

void Delete_data(char*szdata)
{
	NODE* pNODE = Find_data(szdata);
	if (pNODE == 0) return 0;
	else
	{
		pNODE->Pre->Next = pNODE->Next;
		pNODE->Next->Pre = pNODE->Pre;
		printf("Deleted Data : %s \n", szdata);
		g_size--;
		free(pNODE);
	}

}
void Delete_all_list()
{
	if (Is_empty()) {
		return printf("List is emptied\n");
	}

	NODE* pNODE = pHead->Next;
	for (int i = 0; i < g_size; i++)
	{
		printf("��絥���� ������ %d\n", i+1);
		pNODE = pNODE->Next;
		free(pNODE->Pre);
		
	}
	memset(pHead, 0, sizeof(NODE)); // ����ü�ȿ� �ִ� ������� �ʱ�ȭ ����
	memset(pTail, 0, sizeof(NODE));
	pHead->Next = pTail;
	pTail->Pre = pHead;
	g_size = 0; // ���⼭ g_size�� �ϳ��� �����°� ������ �ƴϸ� for�� ������ 0���� �ٷ� �ʱ�ȭ�ϴ°�?
	return 0;
}


int main()
{
	Init_List();
	
	InsertHead("NODE 1");
	InsertTail("NODE 2");
	InsertTail("NODE 3");
	InsertTail("NODE 4");
	printf("%d \n", g_size);
	Delete_all_list();
	Print_List();
	Delete_all_list();



	return 0;
}

