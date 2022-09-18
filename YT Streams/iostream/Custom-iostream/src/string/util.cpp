#include "util.h"

size_t FROSTY515_API GetStringLength(const char* str) {
    size_t size = 0;
    char c = str[size];
    while(c != 0) {
        size++;
        str[size];
    }
    return size;
}

char FROSTY515_API convertToChar(const uint8_t num) {
    if (num > 9) return 0;
    return (num + '0');
}

StrConvertOut FROSTY515_API convertToStr(const uint64_t in) {
    uint64_t temp = in;
    char str[32];
    uint64_t size = 0;

    while (true) {
        if (temp <= 0) break;
        temp /= 10;
        size++;
    }

    temp = in; // instead of creating new variables, reuse old ones.
    for (uint64_t i = 0; i < size; i++) {
        str[size - 1 - i /* looks weird, but it makes it so the number isn't backwards */] = convertToChar((uint8_t)(temp % 10));
        temp /= 10;
    }

    str[size] = 0;

    return { str, (size + 1) };
}

StrConvertOut FROSTY515_API convertToStr(const int64_t in) {
    char str[32];
    uint64_t index = 0;
    int64_t temp2 = in;

    if (temp2 < 0) {
        str[index] = '-';
        temp2 *= -1;
        index++;
    }
    uint64_t size = 0;

    uint64_t temp = (uint64_t)temp2;

    while (true) {
        if (temp <= 0) break;
        temp /= 10;
        size++;
    }

    temp = temp2; // instead of creating new variables, reuse old ones.
    for (uint64_t i = 0; i < size; i++) {
        str[size - 1 - i /* looks weird, but it makes it so the number isn't backwards */ + index] = convertToChar((uint8_t)(temp % 10));
        temp /= 10;
    }

    str[size + index] = 0;

    return { str, (size + index + 1)};
}

StrConvertOut FROSTY515_API convertToStr(const bool b) {
    char str[6] = { 0 };
    if(b) {
        str[0] = 't';
        str[1] = 'r';
        str[2] = 'u';
        str[3] = 'e';
        str[4] = 0;
        return {str, 5};
    } else {
        str[0] = 'f';
        str[1] = 'a';
        str[2] = 'l';
        str[3] = 's';
        str[4] = 'e';
        str[5] = 0;
        return {str, 6};
    }

    return {nullptr, 0};
}

/*

StrConvertOut FROSTY515_API convertToStr(const double d, const uint64_t decimalPlaces) {
    char str[64];
    uint64_t index = 0;
    int64_t temp2 = (int64_t)d;

    if (temp2 < 0) {
        str[index] = '-';
        temp2 *= -1;
        index++;
    }
    uint64_t size = 0;

    uint64_t temp = (uint64_t)temp2;

    while (true) {
        if (temp <= 0) break;
        temp /= 10;
        size++;
    }

    temp = temp2; // instead of creating new variables, reuse old ones.
    for (uint64_t i = 0; i < size; i++) {
        str[size - 1 - i /* looks weird, but it makes it so the number isn't backwards *//* +index] = convertToChar((uint8_t)(temp % 10));
        temp /= 10;
    }

    index += size;

    double tempD;

    if (d < 0) {
        tempD = d * -1;
    }
    else {
        tempD = d;
    }

    tempD -= (int64_t)tempD;

    for (uint64_t i = 0; i < decimalPlaces; i++) {
        tempD *= 10;
        str[index] = convertToChar((uint8_t)tempD);
        if (str[index] == 0) return { nullptr, 0 };
        tempD -= (int64_t)tempD;
        index++;
    }
    
    return { str, (index + 1) };
}

*/
