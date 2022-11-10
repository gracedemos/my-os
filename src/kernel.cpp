#include <kernel/kernel.h>
#include <libcpp/libcpp.h>
#include <main.h>

Kernel::Kernel(MemoryManager* initMemoryManager, Terminal* initTerminal) {
    memoryManager = initMemoryManager;
    terminal = initTerminal;
}

MemoryManager* Kernel::getMemoryManager() {
    return memoryManager;
}

Terminal* Kernel::getTerminal() {
    return terminal;
}

Kernel* getKernel() {
    return reinterpret_cast<Kernel*>(0x108050);
}

extern "C" void kernelMain(void* heapBottom, void* kernelPtr) {
    Page pages[1024] = {};
    MemoryManager memoryManager(heapBottom, pages);
    Terminal terminal;

    Kernel* kernel = static_cast<Kernel*>(kernelPtr);
    *kernel = Kernel(&memoryManager, &terminal);

    main();

    while(true);
}