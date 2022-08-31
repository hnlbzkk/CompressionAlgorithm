#include <stdint.h>

#define OK 1
#define ERROR 0
typedef int Status;

typedef uint8_t Byte;
typedef uint16_t Px;

typedef struct Node{
    struct Node* next;
    Px px;
    short size;    
}Node;

typedef struct Node* LinkList;

extern Node *start;
extern Node *end;
extern Node *current;
//extern Node *next;
extern Px uncompressionPx;
extern Px* uncompressionPxPtr;
extern short uncompressionSize;
extern short* uncompressionSizePtr;

void printList();

Px hexadecimalToPx(Byte, Byte);

Status compression(char*, int);

Status initLinkList();

Status getCurrentPx(int*, Px*);

void insertPx(Px, int*);

void deletePx();