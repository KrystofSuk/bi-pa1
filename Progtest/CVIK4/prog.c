#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Arr{
    int val;
    struct Arr * next;
}ARR;

int isEmpty(ARR * first){
    if(first == NULL)
        return 1;
    return 0;
}

ARR * push(ARR * first, int val){
    ARR * newOne = (ARR * )malloc(sizeof(newOne));
    newOne->next = first;
    newOne->val = val;
    return newOne;
}

void pushBack(ARR * first, int val){
    ARR * now = first;
    while(now->next !=NULL){
        now = now -> next;
    }
    ARR * newOne = (ARR * )malloc(sizeof(newOne));
    now->next = newOne;
    newOne->val = val;
    newOne->next=NULL;
    return;
}

void printLinkedList(ARR * first){
    ARR * now = first;
    while(now -> next != NULL){
        printf("P: %d\n", now->val);
        now = now -> next;
    }
    printf("E: %d\n", now->val);
    return;
}

int getSizeLinkedList(ARR * first){
    int size = 1;
    while(first -> next != NULL){
        size++;
        first = first -> next;
    }
    return size;
}

void freeLinkedList(ARR * first){
    ARR * next = NULL;
    while(first->next!=NULL){
        next = first -> next;
        free(first);
        first = NULL;
        first = next;
    }
    free(first);
    first = NULL;
    return;
}



int main(void){
    ARR * linked = NULL;
    printf("%d\n", isEmpty(linked));
    linked = push(linked,1);
    linked = push(linked,2);
    pushBack(linked,3);
    printf("%d\n", isEmpty(linked));
    printf("%d\n", linked->next->next -> val);
    printf("S: %d\n", getSizeLinkedList(linked));
    
    printLinkedList(linked);
    printf("%d\n", isEmpty(linked));
    freeLinkedList(linked);
    printf("%d\n", isEmpty(linked));
    return 0;
}