#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
	char szData[64];
	struct NODE* next;

} NODE;

NODE* g_pHead = NULL;


int Isempty() {

	if (g_pHead==0)
		return 1; // True == 1
	return 0;
}

/*연결 리스트 전체 데이터 출력*/
void Print_List(void) {
	NODE* pHead = g_pHead;
	while (pHead != NULL) {
		printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
		pHead = pHead->next;
	}

}
int InsertNewNode(char* pszData) {
	NODE* pNode = (NODE*)malloc(sizeof(NODE)); // 노드를 하나 만듦 , 동적할당 해서
	memset(pNode, 0, sizeof(NODE));  //함수 메모리 초기화 함수 굳이 안써도 되는데 있으면 좋다고함

	strcpy_s(pNode->szData,sizeof(pNode->szData), pszData); //들어온 데이터를 노드 안에 넣음 

	if (g_pHead == NULL) //헤드에 아무것도 없는 상태 즉 노드가 하나도 없는 상태
		g_pHead = pNode;
	else {
		pNode->next = g_pHead; // g_pHead가 가르키는 것이 기존노드니까 그걸 생성된 노드한테 옮겨줌
		g_pHead = pNode; // pHead가 가르키는 것을 생성된 노드로 바꿔줌
	}
	return 1;
}

// stack add 함수 

// stack pop 함수 맞긴한 것같은데 정확하지는 않을 듯
void stack_pop() {
	NODE* tmp = g_pHead;
	if (tmp != NULL)
	{
		printf("%s의 값이 pop 되었습니다\n", tmp->szData);
		g_pHead = tmp->next;
		free(tmp);
	}
	else printf("스택이 비어있습니다.");


}

// 전부다 삭제하는 코드
void ReleaseList(void) {
	NODE* pTmp = g_pHead;
	while (pTmp != NULL) {
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;
		printf("Delete:  [%p] %s\n", pDelete, pDelete->szData);
		free(pDelete);

	}
	g_pHead = NULL; // 반드시 해줘야하는 코드 
}

int FindData(char* pszData) {
	NODE* pTmp = g_pHead;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0) //둘이 같으면 
			return 1;
		pTmp = pTmp->next;
	}
}

int DeleteData(char* pszData) {
	NODE* pTmp = g_pHead;
	NODE* pPrev = NULL; // 없애기 위해서 노드포인터를 하나만들어줌
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0) {
			
			//삭제
			printf("DeleteData():  %s\n", pTmp->szData);
			if (pPrev != NULL) // 첫번쨰 노드가 아닐 때
				pPrev->next = pTmp->next;// ->는 간접멤버 연산자로 포인터->멤버  포인터가 가르키는 구조체의 멤버의 접근 할 수 있도록 한다.
			else {
				// 삭제할 데이터가 첫 번째 일대
				g_pHead = pTmp->next;
				
			}

			free(pTmp);
			return 1;
		}
		pPrev = pTmp;

		pTmp = pTmp->next;
	}
}

int main() {

	InsertNewNode("TEST01");
	InsertNewNode("TEST02");
	InsertNewNode("TEST03");
	Print_List();
	
	
	
	return 0;

}