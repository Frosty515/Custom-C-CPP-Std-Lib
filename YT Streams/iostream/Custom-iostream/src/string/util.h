#ifndef _F515_STDLIB_UTIL_STR_H
#define _F515_STDLIB_UTIL_STR_H

#include <stddef.h>
#include <stdint.h>

#include "../Core.h"

struct FROSTY515_API StrConvertOut {
    char* str;
    size_t size;
};

size_t FROSTY515_API GetStringLength(const char* str);

char FROSTY515_API convertToChar(const uint8_t num);

StrConvertOut FROSTY515_API convertToStr(const uint64_t in);
StrConvertOut FROSTY515_API convertToStr(const int64_t in);
StrConvertOut FROSTY515_API convertToStr(const bool b);

inline StrConvertOut FROSTY515_API convertToStr(const uint32_t in) { return convertToStr((uint64_t)in); };
inline StrConvertOut FROSTY515_API convertToStr(const  int32_t in) { return convertToStr(( int64_t)in); };
inline StrConvertOut FROSTY515_API convertToStr(const uint16_t in) { return convertToStr((uint64_t)in); };
inline StrConvertOut FROSTY515_API convertToStr(const  int16_t in) { return convertToStr(( int64_t)in); };
inline StrConvertOut FROSTY515_API convertToStr(const uint8_t  in) { return convertToStr((uint64_t)in); };
inline StrConvertOut FROSTY515_API convertToStr(const  int8_t  in) { return convertToStr(( int64_t)in); };

/*
Not working yet:
StrConvertOut FROSTY515_API convertToStr(const double d, const uint64_t decimalPlaces);

inline StrConvertOut FROSTY515_API convertToStr(const float f) { return convertToStr((double)f); };
*/

#endif /* _F515_STDLIB_UTIL_STR_CONVERTER_H */