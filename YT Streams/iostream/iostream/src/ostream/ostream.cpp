#include "ostream.h"

namespace F515_Custom_std {

    /* ostream class */

    /* Public methods */

    ostream::ostream() {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;

        bool check = Attemptmalloc(OSTREAM_DEFAULT_SIZE);
    }
    
    ostream::ostream(const char* str) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    ostream::ostream(const uint64_t i) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    ostream::ostream(const int64_t i) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    ostream::ostream(const double d) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    ostream::ostream(const bool b) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    void ostream::operator=(const char* str) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    void ostream::operator=(const uint64_t i) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    void ostream::operator=(const int64_t i) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    void ostream::operator=(const double d) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    void ostream::operator=(const bool b) {
        m_data = nullptr;
        m_dataSize = 0;
        m_hasCalled_malloc = false;
    }

    bool ostream::operator==(const ostream other) {

    }

    void ostream::append(const char* str) {

    }

    void ostream::append(const uint64_t i) {

    }

    void ostream::append(const int64_t i) {

    }

    void ostream::append(const double d) {

    }

    void ostream::append(const bool b) {

    }

    void ostream::Clear() {

    }

    ostream::~ostream() {

    }

    /* Private Methods */

    bool ostream::Attemptmalloc(const size_t size) {
        m_data = (uint8_t*)malloc(size);

        if (m_data == nullptr) return false;
        return true;
    }

    bool ostream::AttemptResize(const size_t newSize) {
        if (!m_hasCalled_malloc) return Attemptmalloc(newSize);

        m_data = (uint8_t*)realloc(m_data, newSize);
        if (m_data == nullptr) return false;
        return true;
    }

}