#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Node *start = NULL;
Node *end = NULL;
Node *current = NULL;
//Node *next = NULL;

Status compression(char* input, int size) {
    Px px;
    int index = 0;
    int *iPtr = &index;
    if (initLinkList()) {
        for (int i = 0; i < size;) {
            Byte high = input[i++];
            Byte low = input[i++];
            px = hexadecimalToPx(high, low);

            insertPx(px, iPtr);
        }
        
        start->size = *iPtr;
        end->next = NULL;
        current = start;
        printf("\n\nend: %d %d", end->size, end->px);

        return OK;
    }
    else {
        return ERROR;
    }
}

void printList() {
	while (start != NULL) {
		printf("%d ", start->size);
        start = start->next;
	}
    return;
}

Px hexadecimalToPx(Byte high, Byte low) {
    return (high << 8) | low;
}

Status initLinkList() {
    start = (LinkList)malloc(sizeof(Node));
    if (start) {
        start->size = 0;
        start->px = 0;
        current = start;
        end = start;

        return OK;
    }
    else {
        return ERROR;
    }
}

Status getCurrentPx(int *size, Px *px) {
    if (current && current->next) {
        (* px) = current->px;
        (* size) = current->size;

        current = current->next;
    }
    else if (current && current->next == NULL) {
        (*px) = current->px;
        (*size) = current->size;

        current = NULL;
    }
    else {
        return ERROR;
    }
	return OK;
}

void insertPx(Px px, int *index) {
    if (px == current->px) {
        current->size++;
    }
    else {
        current = (Node*)malloc(sizeof(Node));
        if (current) {
            current->size = 1;
            current->px = px;
            end->next = current;
            end = current;
            (*index)++;
        }
    }
}

Status deletePx(LinkList L, Px* data) {
    if (L->next == NULL) {
        free(L);
        return OK;
    }

    Node* temp = L->next,* node = temp->next;
    
    temp->next = temp->next->next;
    *data = node->px;

    free(node);

    return OK;
}