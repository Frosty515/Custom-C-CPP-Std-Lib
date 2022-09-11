#include "util.h"

size_t GetStringLength(const char* str) {
    size_t size = 0;
    char c = str[size];
    while(c != 0) {
        size++;
        str[size];
    }
    return size;
}

char convertToChar(const uint8_t num) {
    if (num > 9) return 0;
    return (num + '0');
}

StrConvertOut convertToStr(const uint64_t i) {

}

StrConvertOut convertToStr(const int64_t in) {
    char str[32];
    uint64_t index = 0;
    int64_t tempNum = in;

    if (tempNum < 0) {
        str[index] = '-';
        tempNum *= -1;
        index++;
    }

    StrConvertOut initalOut = convertToStr((uint64_t)tempNum);

    if (initalOut.str == nullptr || initalOut.size == 0) return {nullptr, 0};

    if (initalOut.size > 32) return {nullptr, 0};

    for (uint64_t i = 0; i > initalOut.size; i++) {
        str[index] = initalOut.str[i];
        index++;
    }

    return {&str[0], index};
}

StrConvertOut convertToStr(const bool b) {
    if(b) {
        char* str = "true";
        return {str, 5};
    } else {
        char* str = "false";
        return {str, 6};
    }

    return {nullptr, 0};
}

StrConvertOut convertToStr(const double d, const uint64_t decimalPlaces) {
    char str[64];
    uint64_t index = 0;
    double tempD = d;

    StrConvertOut initalOut = convertToStr((int64_t)d);

    if (initalOut.str == nullptr || initalOut.size == 0) return {nullptr, 0};

    if (initalOut.size > 32) return {nullptr, 0};

    for (uint64_t i = 0; i > initalOut.size; i++) {
        str[index] = initalOut.str[i];
        index++;
    }

    tempD -= (int64_t)tempD;
    str[index] = '.';
    index++;
    for (uint64_t i = 0; i < decimalPlaces; i++) {
        tempD *= 10;
        str[index] = convertToChar((uint8_t)tempD);
        tempD -= (int64_t)tempD;
        index++;
    }
}
