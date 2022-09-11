#ifndef _F515_STDLIB_UTIL_STR_H
#define _F515_STDLIB_UTIL_STR_H

#include <stddef.h>
#include <stdint.h>

struct StrConvertOut {
    char* str;
    size_t size;
};

size_t GetStringLength(const char* str);

char convertToChar(const uint8_t num);

StrConvertOut convertToStr(const uint64_t i);
StrConvertOut convertToStr(const int64_t i);
StrConvertOut convertToStr(const bool b);
StrConvertOut convertToStr(const double d);

#endif /* _F515_STDLIB_UTIL_STR_CONVERTER_H */