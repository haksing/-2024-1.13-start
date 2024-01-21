#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Node
{
    char data[64]; 
    struct Node* next;



} Node;

Node p_Head = { 0 };
Node* p_tail = NULL;

int Isempty()
{
    if (p_Head.next == 0)
        return 1; // 비어있다면 
    else return 0; // 노드가 있다면

}

void InsertHeadNode(char* szData) { // 왜 포인터로 받아야할까? 
    Node* pNode = (Node*)malloc(sizeof(Node));
    strcpy_s(pNode->data, sizeof(pNode->data), szData);

    if (Isempty()) { //비어있으면
        p_Head.next = pNode;
        p_tail = pNode;
    }
    else //안비어 있음
    {
        pNode->next = p_Head.next;
        p_Head.next = pNode;
    }
}

void InsertailNode(char* szData) {
    Node* pNode = (Node*)malloc(sizeof(Node));
    strcpy_s(pNode->data, sizeof(pNode->data), szData);
    if (Isempty()) { //비어있으면
        p_Head.next = pNode;
        p_tail = pNode;
    }
    else //안비어있으면
    {
        p_tail->next = pNode;
        p_tail = pNode;
    }
}

void Print_list(p_Head) {
    Node* pNode = p_Head.next;
    int i = 0;
    while (pNode->next != NULL) {
        printf(" %d번 노드의 데이터 값 : %s \n", i++, pNode->data);
        pNode = pNode->next;
    }
}

void Finddata(char* szdata) {
    Node* pNode = p_Head.next;
    int i = 1;


    while (pNode->data != szdata) {
        pNode = pNode->next;
        i++;
    }
    if (pNode == NULL) printf("찾는 노드가 없습니다.\n");
    else printf(" %dst Node is finddata: %s\n", i, pNode->data);

}


int main(void) {
    InsertHeadNode("NODE 1");
    InsertHeadNode("NODE 2");
    InsertHeadNode("NODE 3");

    Print_list();


}
