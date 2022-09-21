#include "ostream.h"

namespace F515_Custom_std {

    /* ostream class */

    /* Public methods */

    ostream::ostream() {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;

        bool check = Attemptmalloc(OSTREAM_DEFAULT_SIZE);
        if (!check) this->~ostream();
        m_dataSize = OSTREAM_DEFAULT_SIZE;
        m_hasData = false;
    }
    
    ostream::ostream(const char* str) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;

        const uint64_t strLength = GetStringLength(str);
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }


    ostream::ostream(const uint64_t in) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;

        StrConvertOut out = convertToStr(in);
        const uint64_t strLength = out.size;
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = out.str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }

    ostream::ostream(const int64_t in) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;

        StrConvertOut out = convertToStr(in);
        const uint64_t strLength = out.size;
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = out.str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }

    /*
    ostream::ostream(const double d) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;


    }
    */

    ostream::ostream(const bool b) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;

        StrConvertOut out = convertToStr(b);
        const uint64_t strLength = out.size;
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = out.str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }

    void ostream::operator=(const char* str) {
        Clear();

        const uint64_t strLength = GetStringLength(str);
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }

    void ostream::operator=(const uint64_t in) {
        Clear();
        StrConvertOut out = convertToStr(in);
        const uint64_t strLength = out.size;
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = out.str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }

    void ostream::operator=(const int64_t in) {
        Clear();
        StrConvertOut out = convertToStr(in);
        const uint64_t strLength = out.size;
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = out.str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }

    /*
    void ostream::operator=(const double d) {
        Clear();
    }
    */

    void ostream::operator=(const bool b) {
        Clear();
        StrConvertOut out = convertToStr(b);
        const uint64_t strLength = out.size;
        bool check = Attemptmalloc(strLength);
        if (!check) {
            this->~ostream();
            return;
        }

        for (uint64_t i = 0; i < strLength; i++) {
            m_data[i] = out.str[i];
        }

        m_dataSize = strLength;
        m_hasData = true;
    }

    bool ostream::operator==(ostream other) {
        if (m_dataSize != other.GetDataSize()) return false;
        const char* otherStr = other.GetStr();
        for (uint64_t i = 0; i < m_dataSize; i++) {
            if (m_data[i] != otherStr[i]) return false;
        }
        return true;
    }

    void ostream::append(const char* str) {
        if (!m_hasData) return operator=(str);
        if (m_data[m_dataSize - 1] == 0) {
            m_dataSize--;
        }
        const uint64_t strSize = GetStringLength(str);
        for (uint64_t i = 0; i < strSize; i++) {
            m_data[m_dataSize + i] = str[i];
        }
        m_dataSize += strSize;
    }

    void ostream::append(const uint64_t in) {
        if (!m_hasData) return operator=(in);
        if (m_data[m_dataSize - 1] == 0) {
            m_dataSize--;
        }
        StrConvertOut strOut = convertToStr(in);
        const uint64_t strSize = strOut.size;
        for (uint64_t i = 0; i < strSize; i++) {
            m_data[m_dataSize + i] = strOut.str[i];
        }
        m_dataSize += strSize;
    }

    void ostream::append(const int64_t in) {
        if (!m_hasData) return operator=(in);
        if (m_data[m_dataSize - 1] == 0) {
            m_dataSize--;
        }
        StrConvertOut strOut = convertToStr(in);
        const uint64_t strSize = strOut.size;
        for (uint64_t i = 0; i < strSize; i++) {
            m_data[m_dataSize + i] = strOut.str[i];
        }
        m_dataSize += strSize;
    }

    /*
    void ostream::append(const double d) {
        if (!m_hasData) return operator=(d);
    }
    */

    void ostream::append(const bool b) {
        if (!m_hasData) return operator=(b);
        if (m_data[m_dataSize - 1] == 0) {
            m_dataSize--;
        }
        StrConvertOut strOut = convertToStr(b);
        const uint64_t strSize = strOut.size;
        for (uint64_t i = 0; i < strSize; i++) {
            m_data[m_dataSize + i] = strOut.str[i];
        }
        m_dataSize += strSize;
    }

    void ostream::Clear() {
        for (uint64_t i = 0; i < m_dataSize; i++)
            m_data[i] = 0;
        m_hasData = false;
    }

    char* strOutput = nullptr;
    bool strOutHasmalloc = false;
    const char* ostream::GetStr() {
        if (!strOutHasmalloc) {
            strOutput = (char*)malloc(m_dataSize);
            strOutHasmalloc = true;
        }
        else
            strOutput = (char*)realloc(strOutput, m_dataSize);
        if (strOutput == nullptr)
            return nullptr;

        for (uint64_t i = 0; i < m_dataSize; i++) {
            strOutput[i] = m_data[i];
        }

        return strOutput;
    }

    ostream::~ostream() {
        if (m_hasCalled_malloc) free(m_data);
        m_dataSize = 0;
        m_hasCalled_malloc = false;

        m_hasData = false;
    }

    /* Private Methods */

    bool ostream::Attemptmalloc(const size_t size) {
        if (m_hasCalled_malloc) return AttemptResize(size);
        m_data = (uint8_t*)malloc(size);

        if (m_data == nullptr) return false;
        m_hasCalled_malloc = true;
        return true;
    }

    bool ostream::AttemptResize(const size_t newSize) {
        if (!m_hasCalled_malloc) return Attemptmalloc(newSize);

        m_data = (uint8_t*)realloc(m_data, newSize);
        if (m_data == nullptr) return false;
        return true;
    }

}