#include <stdio.h>
#include <malloc.h>
typedef int element;

typedef struct DYNAMICARRAY {
    element* arr;
    int size;
    int endIndex;
    int resizeCount;
} DYNAMICARRAY;

void constructor(DYNAMICARRAY* dArr, int size);
void resize(DYNAMICARRAY* dArr);
void append(DYNAMICARRAY* dArr, element elem);
void pop(DYNAMICARRAY* dArr);
void removeAll(DYNAMICARRAY* dArr);
void print(DYNAMICARRAY* dArr);

void constructor(DYNAMICARRAY* dArr, int size) {
    dArr->arr = (element*)malloc(sizeof(element) * size);
    dArr->size = size;
    dArr->endIndex = -1;
    dArr->resizeCount = 0;
}

int Is_full(DYNAMICARRAY* dArr)
{
    return (dArr->endIndex == (dArr->size - 1));
}

void append(DYNAMICARRAY* dArr, element elem) 
{
    if (Is_full(dArr)) {
        dArr->size *= 2;
        dArr->arr = (element*)realloc(dArr->arr, dArr->size * sizeof(element));
    }
    dArr->arr[++(dArr->endIndex)] = elem;


}
void resize(DYNAMICARRAY* dArr) {
    dArr->resizeCount++;
    int* temp = (int*)malloc(sizeof(int) * (dArr->size) * (dArr->resizeCount));

    for (int i = 0; i < dArr->size; i++) {
        temp[i] = dArr->arr[i];
    }
    free(dArr->arr);
    dArr->arr = temp;
    dArr->size *= dArr->resizeCount;
}

void pop(DYNAMICARRAY* dArr) {
    free(dArr->arr[dArr->endIndex]);
    dArr->endIndex--;
}
void removeAll(DYNAMICARRAY* dArr) {
    free(dArr->arr);
}


void print(DYNAMICARRAY* dArr) {
    for (int i = 0; i <= dArr->endIndex; i++) {
        printf(dArr->arr[i] + " ");
    }
}

int main() {
    DYNAMICARRAY da;
    printf("-------------------------\n");
    constructor(&da, 5);
    append(&da, 5);
    




    printf("-------------------------\n");
    
   

    return 0;
}


