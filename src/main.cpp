#include <kernel/kernel.h>
#include <libcpp/libmem.h>

void main() {
    char* str = static_cast<char*>(malloc(4));
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = '\x00';

    getKernel()->getTerminal()->writeString(str);
}