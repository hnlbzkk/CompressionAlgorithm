#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Node *start = NULL;
Node *end = NULL;
Node *current = NULL;
//Node *next = NULL;
Px uncompressionPx = 0;
Px* uncompressionPxPtr = &uncompressionPx;
short uncompressionSize = 0;
short* uncompressionSizePtr = &uncompressionSize;
unsigned char uncompressionArray[];
unsigned int* arraySize = NULL;
Byte  lowByte = 0;
Byte* lowBytePtr = &lowByte;
Byte  highByte = 0;
Byte* highBytePtr = &highByte;

Status compression(char* input, int size) {
    //*arraySize = size;
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

        return OK;
    }
    else {
        return ERROR;
    }
}

void uncompression(char* array, int size) {
    short currentSize = 0;
    Px currentPx = 0;
    for (int i = 0; i < size;) {
        deletePx();
        currentSize = *uncompressionSizePtr;
        currentPx = *uncompressionPxPtr;
        PxToHexadecimal(uncompressionPxPtr);
        for (int j = 0; j < currentSize; j++) {
            array[i++] = *highBytePtr;
            array[i++] = *lowBytePtr;
        }
    }
}

void printList() {
    printf("LinkList: \n");
	while (start != NULL) {
        if (start->next == NULL) {
            printf("(%d %d)", start->size, start->px);
            break;
        }
        else {
            printf(" (%d %d) ->", start->size, start->px);
        }
        start = start->next;
	}
    start = current;
    printf("\n\n");
    return;
}

void printArray(char* array, int size) {
    printf("Array:\n[ ");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d ]\n\n", array[i]);
            break;
        }
        printf("%d, ", array[i]);
    }
}

Px hexadecimalToPx(Byte high, Byte low) {
    return (high << 8) | low;
}

void PxToHexadecimal(Px* px) {
    (*lowBytePtr) = (*px) & 0x00FF;
    (*highBytePtr) = (*px) >> 8;
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

void insertPx(Px px, int* index) {
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

/*
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
*/
void deletePx() {
    if (start->next->next == NULL) {
        Node* temp = start->next;

        (*uncompressionPxPtr) = temp->px;
        (*uncompressionSizePtr) = temp->size;

        free(temp);
        free(start);
    }
    else {
        Node* temp = start, * node = temp->next;

        (*uncompressionPxPtr) = node->px;
        (*uncompressionSizePtr) = node->size;
        temp->next = temp->next->next;

        free(node);
    }
}