#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Node *end = NULL;
Node *current = NULL;
Node *next = NULL;

LinkList compression(char* input, int size) {
    Px px, *currentPx = NULL;
	int *currentSize;
    int index = 0;
    LinkList list = initLinkList();
    for (int i = 0; i < size;) {
        printf("=======\n");
        Byte high = input[i++];
        Byte low = input[i++];
        px = hexadecimalToPx(high, low);
        printf("==%d==\n", px);

		insertPx(px);
    }
	//printList(list);
    return list;
}

void printList(LinkList list) {
	while (list->next) {
		printf("%d %d -> ", list->size, list->px);
	}
}

Px hexadecimalToPx(Byte high, Byte low) {
    Px result;
    result = ((high << 8) | low);
    printf("ToPx = %d", result);
    return result;
}

LinkList initLinkList() {
	LinkList head;
	head = (LinkList)malloc(sizeof(Node));
    head->size = 0;
    head->px = 0;
	current = head;

	next = (Node*)malloc(sizeof(Node));
    next->size = 0;
    next->px = 0;
	current->next = next;
	next->next = NULL;

	return head;
}

Status getCurrentPx(int *size, Px *px) {
    if (current && current->next) {
        *px = current->px;
        *size = current->size;

        current = current->next;
        next = current->next;
    }
    else if (current && current->next == NULL) {
        *px = current->px;
        *size = current->size;

        current = NULL;
        next = NULL;
    }
    else {
        return ERROR;
    }
	return OK;
}

void insertPx(Px px) {
    printf("current: %d %d\n", current->size, current->px);
    Px currentPx = current->px;
    printf("currentPx: %d, inputPx %d  ", currentPx, px);
    if (px == currentPx) {
        printf("add  ");
        current->size++;
    }
    else {
        /*
        next = (Node*)malloc(sizeof(Node));
        if (next) {
            next->size = 1;
            next->px = currentPx;
            next->next = NULL;

            current->next = next;
			current = next;
            printf("next: %d %d\n", next->size, next->px);
        }
        */
        next = (Node*)malloc(sizeof(Node));
        if (next) {
            current->size = 1;
            current->px = px;
            current->next = next;

            next->size = 0;
            next->px = 0;
            next->next = NULL;
            printf("new: %d %d\n", current->size, current->px);
        }
    }
}

Status deletePx(LinkList L, Px* px) {
    return OK;
}