#include <iostream.h>

#include <cstdio>

int main(int argc, char** argv) {

    printf("\nStarting!\n");

    F515_Custom_std::ostream stream("hi!");

    const uint64_t size = stream.GetDataSize();
    const char* str = stream.GetStr();

    for (uint64_t i = 0; i < size; i++) {
        printf("%c", str[i]);
    }
    printf("\n\n");

    stream.Clear();

    stream << "New string!";

    const uint64_t size2 = stream.GetDataSize();
    const char* str2 = stream.GetStr();

    for (uint64_t i = 0; i < size2; i++) {
        printf("%c", str2[i]);
    }

    printf("\n\n");

    while (true);
    return 0;
}