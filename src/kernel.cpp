#include <kernel/kernel.h>
#include <libcpp/libcpp.h>

void handleEvent() {
    char* interrupt = reinterpret_cast<char*>(INTERRUPT);
}

extern "C" void kernelMain(void* heapBottom) {
    Page pages[1024] = {};
    MemoryManager memoryManager(heapBottom, pages);

    Terminal terminal;

    char* msg = static_cast<char*>(memoryManager.allocateMemory(4));
    msg[0] = 'b';
    msg[1] = 'o';
    msg[2] = 'b';
    msg[3] = '\x00';

    terminal.writeString(msg);

    while(true) {
        handleEvent();
    }
}