#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "file.c"



int main()
{
    /*
    Px px;
    Byte low = 1;
    Byte high = 1;
    px = hexadecimalToPx(low, high);
    printf("%d", px);
    */

    compression(gImage_file, sizeof(gImage_file));
}
