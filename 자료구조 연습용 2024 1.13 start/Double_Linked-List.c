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
	pHead = (NODE*)malloc(sizeof(NODE));// malloc의 반환 값은 ()안의 크기의 주소
	pTail = (NODE*)malloc(sizeof(NODE));
	memset(pHead, 0, sizeof(NODE)); // 구조체안에 있는 멤버들을 초기화 해줌
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

	// pNODE 를 앞뒤 노드와 연결
	pNODE->Pre = pHead;
	pNODE->Next = pHead->Next;
	
	pHead->Next->Pre = pNODE; //앞노드를 pNODE에 연결
	pHead->Next = pNODE; // 헤드노드를 pNODE에 연결
	g_size++;

}

void InsertTail(char* szdata)
{
	NODE* pNODE = (NODE*)malloc(sizeof(NODE));
	memset(pNODE, 0, sizeof(NODE));
	strcpy_s(pNODE->data, sizeof(pNODE->data), szdata);

	// pNODE 를 앞뒤 노드와 연결
	pNODE->Pre = pTail->Pre;
	pNODE->Next = pTail;

	pTail->Pre->Next = pNODE; //앞노드를 pNODE에 연결
	pTail->Pre= pNODE; // 테일노드를 pNODE에 연결
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
		if (strcmp(pNODE->data, szdata) == 0) { // 찾은 경우
			printf("finding data : %s\n", szdata);
			return pNODE;
		}
		else pNODE = pNODE->Next; //pNODE->data값이 다른경우
	}
	printf("못찾음\n");
	return 0; // 루프를 다돌고 아애 못찾은 경우


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
		printf("모든데이터 삭제중 %d\n", i+1);
		pNODE = pNODE->Next;
		free(pNODE->Pre);
		
	}
	memset(pHead, 0, sizeof(NODE)); // 구조체안에 있는 멤버들을 초기화 해줌
	memset(pTail, 0, sizeof(NODE));
	pHead->Next = pTail;
	pTail->Pre = pHead;
	g_size = 0; // 여기서 g_size를 하나씩 내리는게 나은지 아니면 for이 끝나고 0으로 바로 초기화하는게?
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

