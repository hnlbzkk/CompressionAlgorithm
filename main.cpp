//
// Created by ZKK on 2022/8/23.
//
#include <stdio.h>
#include "data.h"

int main() {
    Word word = {1, 2};
    Zip zip = {1, word};
    printf("size%d low%d high%d", zip.size, zip.word.low, zip.word.high);
}
