#ifndef _F515_STDLIB_OSTREAM_H
#define _F515_STDLIB_OSTREAM_H

#include <stddef.h>
#include <stdint.h>

#include <memory>

#include "../Core.h"
#include "../string/util.h"

#define OSTREAM_DEFAULT_SIZE 64

namespace F515_Custom_std {
    class FROSTY515_API ostream {
    public:
        ostream();
        ostream(const char* str);
        ostream(const uint64_t in);
        ostream(const int64_t in);
        //ostream(const double d);
        ostream(const bool b);

        void operator=(const char* str);
        void operator=(const uint64_t in);
        void operator=(const int64_t in);
        //void operator=(const double d);
        void operator=(const bool b);

        bool operator==(ostream other);

        void append(const char* str);
        void append(const uint64_t in);
        void append(const int64_t in);
        //void append(const double d);
        void append(const bool b);

        inline void operator<<(const char* str)   { append(str);  };
        inline void operator<<(const uint64_t in) { append(in);   };
        inline void operator<<(const int64_t in)  { append(in);   };
        //inline void operator<<(const double d)  { append(d);    };
        inline void operator<<(const bool b)      { append(b);    };

        void Clear();

        const char* GetStr();
        inline size_t GetDataSize() {
            if (m_hasData)
                return m_dataSize;
            return 0;
        };

        ~ostream();

    private:

        bool Attemptmalloc(const size_t size);
        bool AttemptResize(const size_t newSize);

    private:
        uint8_t* m_data;
        size_t   m_dataSize;
        bool     m_hasCalled_malloc;
        bool     m_hasData;
    };

}

#endif /* _F515_STDLIB_OSTREAM_H */