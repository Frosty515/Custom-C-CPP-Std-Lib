#include "CustomString.h"

namespace Frosty515 {

    /* String class */

    /* Public Methods */

    String::String() {
        m_str = (char*) malloc(64);
        m_StrPointer = &m_str;
        m_str_length = 0;
        m_str_size = 64;
    }

    String::String(const char* str) {
        const size_t inputStrSize = GetCStringLength(str);
        m_str = (char*) malloc(inputStrSize + 8);
        for (uint64_t i = 0; i < inputStrSize; i++) {
            m_str[i] = str[i];
        }
        m_str_length = inputStrSize;
        m_str_size = inputStrSize + 8;
        m_str[m_str_length] = 0;
        m_StrPointer = &m_str;
    }

    String::String(char* str) {
        const size_t inputStrSize = GetCStringLength(str);
        m_str = (char*) malloc(inputStrSize + 8);
        for (uint64_t i = 0; i < inputStrSize; i++) {
            m_str[i] = str[i];
        }
        m_str_length = inputStrSize;
        m_str_size = inputStrSize + 8;
        m_str[m_str_length] = 0;
        m_StrPointer = &m_str;
    }

    String::~String() {
        
    }


    void String::operator=(const char* str) {
        free(m_str);
        const size_t inputStrSize = GetCStringLength(str);
        m_str = (char*) malloc(inputStrSize + 8);
        for (uint64_t i = 0; i < inputStrSize; i++) {
            m_str[i] = str[i];
        }
        m_str_length = inputStrSize;
        m_str_size = inputStrSize + 8;
        m_str[m_str_length] = 0;
        m_StrPointer = &m_str;
    }

    char String::operator[](uint64_t index) {
        if (index > m_str_length) return 0;
        return m_str[index];
    }

    bool String::operator==(String other) {
        return c_str() == other.c_str();
    }

    const char* String::c_str() {
        return *m_StrPointer;
    }

    size_t String::length() {
        return m_str_length;
    }

    char String::start() {
        return m_str[0];
    }

    char String::end() {
        return m_str[m_str_length - 1];
    }


    void String::append(const char* str) {
        const size_t inputStrSize = GetCStringLength(str);
        if (m_str_size < (inputStrSize + m_str_length)) {
            ExpandStr(((inputStrSize + m_str_length) - m_str_size) + 8);
        }
        for (uint64_t i = m_str_length; i < (inputStrSize + m_str_length); i++) {
            m_str[i] = str[(i - m_str_length)];
            m_str_length++;
        }
        m_str[m_str_length] = 0;
    }

    void String::append(char* str) {
        const size_t inputStrSize = GetCStringLength(str);
        if (m_str_size < (inputStrSize + m_str_length)) {
            ExpandStr(((inputStrSize + m_str_length) - m_str_size) + 8);
        }
        for (uint64_t i = m_str_length; i < (inputStrSize + m_str_length); i++) {
            m_str[i] = str[(i - m_str_length)];
            m_str_length++;
        }
        m_str[m_str_length] = 0;
    }

    void String::append(const char c) {
        if (m_str_size < (1 + m_str_length)) {
            ExpandStr(((1 + m_str_length) - m_str_size) + 8);
        }
        m_str[m_str_length] = c;
        m_str_length++;
        m_str[m_str_length] = 0;
    }

    void String::append(const uint64_t num) {
        uint8_t size;
        size_t sizeTest = num;
        uint64_t numBuf = num;
        while (sizeTest / 10 > 0) {
            sizeTest /= 10;
            size++;
        }

        uint8_t index = 0;
        while (numBuf / 10 > 0) {
            uint8_t remainder = numBuf % 10;
            numBuf /= 10;
            append((char)(remainder + '0'));
            index++;
        }

        uint8_t remainder = num % 10;
        append((char)(remainder + '0'));
        m_str[m_str_length] = 0;
    }

    void String::append(const int64_t num) {
        int64_t numBuf = num;
        if (num < 0) {
            numBuf *= -1;
            append('-');
        }
        append((uint64_t)numBuf);
    }

    void String::append(const double num, const uint64_t DecimalPlaces) {
        append((int64_t)num);
        append('.');
    }

    void String::append(const bool b) {
        uint8_t extraLength = 0;
        char* str;
        if (b) {
            extraLength = 4; /* length of 'true' */
            str = (char*) malloc(4);
            str[0] = 't';
            str[1] = 'r';
            str[2] = 'u';
            str[3] = 'e';
        } else {
            extraLength = 5; /* length of 'false' */
            str = (char*) malloc(5);
            str[0] = 'f';
            str[1] = 'a';
            str[2] = 'l';
            str[3] = 's';
            str[4] = 'e';
        }
        if (m_str_size < (extraLength + m_str_length)) {
            ExpandStr(((extraLength + m_str_length) - m_str_size) + 8);
        }
        for (uint64_t i = m_str_length; i < (extraLength + m_str_length); i++) {
            m_str[i] = str[(i - m_str_length)];
        }
        free(str);
        m_str[m_str_length] = 0;
    }


    void String::removeChars(const size_t amount) {
        if (amount > m_str_length) return;
        size_t amountCPY = amount;
        for (int64_t i = m_str_length - 1; i >= 0; i--) {
            if (amountCPY = 0) break;
            m_str[i] = 0;
            m_str_length--;
            amountCPY--;
        }
        if (m_str_length <= 64) {
            ShrinkStr(m_str_size - 64); /* sets size to 64 */
            m_str_size = 64;
        }
        else if ((m_str_size - m_str_length) > 8) {
            ShrinkStr(m_str_size - m_str_length - 8);
            m_str_size = 8 + m_str_length;
        }
        m_str[m_str_length] = 0;
    }

    /* Private Methods */

    void String::ExpandStr(const size_t bytes) {
        m_StrPointer = nullptr;
        m_str = (char*) realloc(m_str, (m_str_size + bytes));
        if (m_str == nullptr) {
            std::cout << "STRING ERROR: FAILED TO EXPAND STRING. Terminating program with \"Memory Error\"..." << std::endl;
            int* i = (int*)0;
            *i = 1;
        }
        m_StrPointer = &m_str;
    }

    void String::ShrinkStr(const size_t bytes) {
        m_str = (char*) realloc(m_str, (m_str_size - bytes));
        if (m_str == nullptr) {
            std::cout << "STRING ERROR: FAILED TO SHRINK STRING. Terminating program with \"Memory Error\"..." << std::endl;
            int* i = (int*)0;
            *i = 1;
        }
        m_StrPointer = &m_str;
    }

    /* Other Methods */

    std::ostream& operator<<(std::ostream& stream, String str) {
        stream << str.c_str();
        return stream;
    }

    uint64_t GetCStringLength(const char* str) {
        uint64_t out = 0;
        char c;
        while (true) {
            c = str[out];
            if (c == 0) break;
            out++;
        }
        return out;
    }


}