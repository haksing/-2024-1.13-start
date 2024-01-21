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

/*���� ����Ʈ ��ü ������ ���*/
void Print_List(void) {
	NODE* pHead = g_pHead;
	while (pHead != NULL) {
		printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
		pHead = pHead->next;
	}

}
int InsertNewNode(char* pszData) {
	NODE* pNode = (NODE*)malloc(sizeof(NODE)); // ��带 �ϳ� ���� , �����Ҵ� �ؼ�
	memset(pNode, 0, sizeof(NODE));  //�Լ� �޸� �ʱ�ȭ �Լ� ���� �Ƚᵵ �Ǵµ� ������ ���ٰ���

	strcpy_s(pNode->szData,sizeof(pNode->szData), pszData); //���� �����͸� ��� �ȿ� ���� 

	if (g_pHead == NULL) //��忡 �ƹ��͵� ���� ���� �� ��尡 �ϳ��� ���� ����
		g_pHead = pNode;
	else {
		pNode->next = g_pHead; // g_pHead�� ����Ű�� ���� �������ϱ� �װ� ������ ������� �Ű���
		g_pHead = pNode; // pHead�� ����Ű�� ���� ������ ���� �ٲ���
	}
	return 1;
}

// stack add �Լ� 

// stack pop �Լ� �±��� �Ͱ����� ��Ȯ������ ���� ��
void stack_pop() {
	NODE* tmp = g_pHead;
	if (tmp != NULL)
	{
		printf("%s�� ���� pop �Ǿ����ϴ�\n", tmp->szData);
		g_pHead = tmp->next;
		free(tmp);
	}
	else printf("������ ����ֽ��ϴ�.");


}

// ���δ� �����ϴ� �ڵ�
void ReleaseList(void) {
	NODE* pTmp = g_pHead;
	while (pTmp != NULL) {
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;
		printf("Delete:  [%p] %s\n", pDelete, pDelete->szData);
		free(pDelete);

	}
	g_pHead = NULL; // �ݵ�� ������ϴ� �ڵ� 
}

int FindData(char* pszData) {
	NODE* pTmp = g_pHead;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0) //���� ������ 
			return 1;
		pTmp = pTmp->next;
	}
}

int DeleteData(char* pszData) {
	NODE* pTmp = g_pHead;
	NODE* pPrev = NULL; // ���ֱ� ���ؼ� ��������͸� �ϳ��������
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0) {
			
			//����
			printf("DeleteData():  %s\n", pTmp->szData);
			if (pPrev != NULL) // ù���� ��尡 �ƴ� ��
				pPrev->next = pTmp->next;// ->�� ������� �����ڷ� ������->���  �����Ͱ� ����Ű�� ����ü�� ����� ���� �� �� �ֵ��� �Ѵ�.
			else {
				// ������ �����Ͱ� ù ��° �ϴ�
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