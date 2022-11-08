#include <kernel/kernel.h>

void handleEvent() {

}

extern "C" void kernelMain(void* heapBottom) {
    Page pages[1024] = {};
    MemoryManager memoryManager(heapBottom, pages);

    Terminal terminal;

    char* message = static_cast<char*>(memoryManager.allocateMemory(4));
    message[0] = 'a';
    message[1] = 'b';
    message[2] = '\n';
    message[3] = '\x00';

    char* msg2 = static_cast<char*>(memoryManager.allocateMemory(5));
    msg2[0] = 'h';
    msg2[1] = 'e';
    msg2[2] = 'h';
    msg2[3] = 'e';
    msg2[4] = '\x00';

    terminal.writeString(message);
    terminal.writeString(msg2);

    while(true) {
        
    }
}