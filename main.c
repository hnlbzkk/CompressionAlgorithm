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
    int len = sizeof(chs);

    // 压缩
    compression(chs, len);
    printList();

    // 解压缩
    char uncompressionChs[sizeof(chs)];
    uncompression(uncompressionChs, len);
    printArray(uncompressionChs, len);
}
