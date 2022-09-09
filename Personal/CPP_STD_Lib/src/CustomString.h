#ifndef _CUSTOM_STRING_H
#define _CUSTOM_STRING_H

#include <stdint.h>
#include <stddef.h>
#include <iostream>

namespace Frosty515 {

    class String {
    public:
        String();
        String(const char* str);
        String(char* str);
        ~String();

        void operator=(const char* str);
        inline void operator=(char* str) { return operator=((const char*)str); };

        char operator[](uint64_t index);
        inline char operator[](int64_t  index) { return operator[]((uint64_t)index); };
        inline char operator[](uint32_t index) { return operator[]((uint64_t)index); };
        inline char operator[](int32_t  index) { return operator[]((uint64_t)index); };
        inline char operator[](uint16_t index) { return operator[]((uint64_t)index); };
        inline char operator[](int16_t  index) { return operator[]((uint64_t)index); };
        inline char operator[](uint8_t  index) { return operator[]((uint64_t)index); };
        inline char operator[](int8_t   index) { return operator[]((uint64_t)index); };

        inline void operator+=(const char* str) { append(str); };
        inline void operator+=(      char* str) { append(str); };

        bool operator==(String other);

        const char* c_str();
        size_t length();
        char start();
        char end();

        void append(const char* str);
        void append(char* str);
        void append(const char c);
        void append(const uint64_t num);
        void append(const  int64_t num);
        void append(const   double num, const uint64_t DecimalPlaces = 2);
        void append(const bool b);

        inline void append(const uint32_t num)                                   { return append((uint64_t)num);                };
        inline void append(const int32_t  num)                                   { return append(( int64_t)num);                };
        inline void append(const uint16_t num)                                   { return append((uint64_t)num);                };
        inline void append(const int16_t  num)                                   { return append(( int64_t)num);                };
        inline void append(const uint8_t  num)                                   { return append((uint64_t)num);                };
        inline void append(const int8_t   num)                                   { return append(( int64_t)num);                };
        inline void append(const float    num, const uint64_t DecimalPlaces = 2) { return append((  double)num, DecimalPlaces); };

        void removeChars(const size_t amount); /* removes chars from end of string */

    private:
        void ExpandStr(const size_t bytes = 8);
        void ShrinkStr(const size_t bytes = 8);

    private:
        char* m_str;
        size_t m_str_length;
        size_t m_str_size;
        char** m_StrPointer;

    };

    std::ostream& operator<<(std::ostream& stream, String str);

    uint64_t GetCStringLength(const char* str);
    inline uint64_t GetCStringLength(char* str) { return GetCStringLength((const char*)str); };

}

#endif /* _CUSTOM_STRING_H */