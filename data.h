#include <stdint.h>

// region ��������״̬����
#define OK 1
#define ERROR 0
typedef int Status;
// endregion

// region ���ݽṹ����
typedef uint8_t Byte;
typedef uint16_t Px;

typedef struct Node{
    struct Node* next;
    Px px;
    short size;    
}Node;

typedef struct Node* LinkList;
// endregion

// region �ڵ㶨��
extern Node* start;
extern Node* end;
extern Node* current;
//extern Node *next;
// endregion

// region ��ѹ��
extern Px uncompressionPx;
extern Px* uncompressionPxPtr;
extern short uncompressionSize;
extern short* uncompressionSizePtr;
//extern unsigned char uncompressionArray[];
//extern unsigned int* arraySize;
extern Byte  lowByte;
extern Byte* lowBytePtr;
extern Byte  highByte;
extern Byte* highBytePtr;
// endregion

void printList();

void printArray(char*, int);

Px hexadecimalToPx(Byte, Byte);

void PxToHexadecimal(Px*);

Status compression(char*, int);

void uncompression(char*, int);

Status initLinkList();

//Status getCurrentPx(int*, Px*);

void insertPx(Px, int*);

void deletePx();