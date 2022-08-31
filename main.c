#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "file.h"


int main()
{
    /*
    Px px;
    Byte low = 1;
    Byte high = 1;
    px = hexadecimalToPx(low, high);
    printf("%d", px);
    */
    char chs[] = { 0X6B,0X7B,0X4B,0X73,0X4B,0X73,0X6B,0X7B,0X6B,0X73,0X6B,0X73 };

    compression(chs, sizeof(chs));
    printList();
    deletePx();
    printList();
    deletePx();
    printList();
    deletePx();
    printList();
}
