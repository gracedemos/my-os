#include <kernel/kernel.h>

void main() {
    char* str = static_cast<char*>(getKernel()->getMemoryManager()->allocateMemory(4));
    str[0] = 'b';
    str[1] = 'o';
    str[2] = 'b';

    getKernel()->getTerminal()->writeString(str);
}