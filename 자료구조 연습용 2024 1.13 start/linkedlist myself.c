#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct NODE
{
    char data[64]; 
    struct NODE* next;



} Node;

NODE p_Head = { NULL };
NODE* p_tail = NULL;

int Isempty()
{
    if (p_Head.next == 0)
        return 1; // 비어있다면 
    else return 0; // 노드가 있다면

}

void InsertHeadNode(char* szData) { // 왜 포인터로 받아야할까? 
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    strcpy_s(pNode->data, sizeof(pNode->data), szData);
    pNode->next = NULL;

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
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    strcpy_s(pNode->data, sizeof(pNode->data), szData);
    pNode->next = NULL;
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

void Print_list(){
    NODE* pNode = p_Head.next;
    int count = 0;
    while (1) {
        if (pNode != NULL){
            printf(" %s-> ",  pNode->data);
            pNode = pNode->next;
            count = 1;
        }
        else {
            if (count == 1) {
                printf("NULL \n");
                return 0;
            }
            else {
                printf("List is empty.\n");
                return 0;
            }
         }
    }
}

NODE* Finddata(char* szdata) {
    NODE* Pre = &p_Head;
    NODE* pNode = p_Head.next;
    int i = 1;
    while(1){
        if (strcmp(pNode->data , szdata)==0) { // pNode->data==szdata 하면 왜틀림? 왱 ㅙ왜오애ㅙㅗ
            return Pre;
        }
        else
            if (pNode->next == NULL) {
                printf("찾는 노드가 없습니다.\n");
                return NULL;
            }
            else {
                Pre = pNode;
                pNode = pNode->next;
                i++;
            }
    }
}
void deletedata(char*szdata) {
    NODE* Pre = Finddata(szdata);
    NODE* pNode = Pre->next;
    if (Pre==NULL){
        printf("삭제할 노드를 찾지 못했습니다.\n");
    }
    else{
        if (pNode->next == NULL) { // 끝의 데이터를 삭제하는 경우 
            p_tail = Pre;
            Pre->next = NULL;
        }
        else {
            Pre->next = pNode->next;
        } 
        printf("Delete data, Deleted data : %s\n", pNode->data);
        free(pNode);
    }




}


int main(void) {

    InsertailNode("NODE 4");
    InsertailNode("NODE 3");
    InsertailNode("NODE 2");
    InsertailNode("NODE 1");
    Print_list();

    deletedata("NODE 4");
    deletedata("NODE 1");
    deletedata("NODE 2");
    deletedata("NODE 3");

    Print_list();
    return 0;

    
    


}
