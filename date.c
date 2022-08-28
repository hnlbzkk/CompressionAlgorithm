#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Node *end = NULL;
Node* current = NULL;
Node* next = NULL;

LinkList compression(char* input, int size) {
    Px px;
    int index = 0;
    LinkList list = NULL;
    for (int i = 0; i < size;) {
        Byte high = input[i++];
        Byte low = input[i++];
        px = hexadecimalToPx(high, low);

        printf("%d\n", px);
    }
    return list;
}

Px hexadecimalToPx(Byte high, Byte low) {
    return (high << 8) | low;
}

Status initLinkList() {
    return OK;
}

Status getCurrentPx(int *size, Px *px) {
    if (current && current->next) {
        *px = current->px;
        *size = current->size;

        current = current->next;
        next = current->next;
        return OK;
    }
    else if (current && current->next == NULL) {
        *px = current->px;
        *size = current->size;

        current = NULL;
        next = NULL;
        return OK;
    }
    else {
        return ERROR;
    }
}

void insertPx(Px px) {
    Px currentPx = current->px;
    if (px == currentPx) {
        current->size++;
    }
    else {
        next = (Node*)malloc(sizeof(Node));
        if (next) {
            next->size = 1;
            next->px = currentPx;
            next->next = end;
            current->next = next;
        }
    }
}

Status deletePx(LinkList L, Px* px) {
    return OK;
}