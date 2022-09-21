#include "util.h"

char outStr[64];

size_t FROSTY515_API GetStringLength(const char* str) {
    size_t size = 0;
    char c = str[size];
    while(c != 0) {
        size++;
        c = str[size];
    }
    size++;
    return size;
}

char FROSTY515_API convertToChar(const uint8_t num) {
    if (num > 9) return 0;
    return (num + '0');
}

StrConvertOut FROSTY515_API convertToStr(const uint64_t in) {
    uint64_t temp = in;
    uint64_t size = 0;

    while (true) {
        if (temp <= 0) break;
        temp /= 10;
        size++;
    }

    temp = in; // instead of creating new variables, reuse old ones.
    for (uint64_t i = 0; i < size; i++) {
        outStr[size - 1 - i /* looks weird, but it makes it so the number isn't backwards */] = convertToChar((uint8_t)(temp % 10));
        temp /= 10;
    }

    outStr[size] = 0;

    size++;

    return { &outStr[0], size};
}

StrConvertOut FROSTY515_API convertToStr(const int64_t in) {
    uint64_t index = 0;
    int64_t temp2 = in;

    if (temp2 < 0) {
        outStr[index] = '-';
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
        outStr[size - 1 - i /* looks weird, but it makes it so the number isn't backwards */ + index] = convertToChar((uint8_t)(temp % 10));
        temp /= 10;
    }

    outStr[size + index] = 0;

    size += index;
    size++;

    return { &outStr[0], size};
}

char boolOutStr[6] = { 0 };
StrConvertOut FROSTY515_API convertToStr(const bool b) {
    if(b) {
        boolOutStr[0] = 't';
        boolOutStr[1] = 'r';
        boolOutStr[2] = 'u';
        boolOutStr[3] = 'e';
        boolOutStr[4] = 0;
        return {&boolOutStr[0], 5};
    } else {
        boolOutStr[0] = 'f';
        boolOutStr[1] = 'a';
        boolOutStr[2] = 'l';
        boolOutStr[3] = 's';
        boolOutStr[4] = 'e';
        boolOutStr[5] = 0;
        return {&boolOutStr[0], 6};
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
