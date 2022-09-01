#include <stdint.h>

// region 方法返回状态定义
#define OK 1
#define ERROR 0
typedef int Status;
// endregion

// region 数据结构定义
typedef uint8_t Byte;
typedef uint16_t Px;

typedef struct Node{
    struct Node* next;
    Px px;
    short size;    
}Node;

typedef struct Node* LinkList;
// endregion

// region 节点定义
extern Node* start;
extern Node* end;
extern Node* current;
//extern Node *next;
// endregion

// region 解压缩
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