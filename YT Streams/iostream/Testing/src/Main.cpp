#include <iostream.h>

#include <string/util.h>

#include <cstdio>

int main(int argc, char** argv) {

    printf("Beginning Conversion!\n");

    StrConvertOut out = convertToStr(false);

    for (uint64_t i = 0; i < out.size; i++) {
        printf("%c", out.str[i]);
    }

    printf("\n");

    while (true);
    return 0;
}