#include <kernel/kernel.h>
#include <libcpp/libcpp.h>
#include <main.h>

Kernel* KERNEL;

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
    return KERNEL;
}

extern "C" void kernelMain(void* heapBottom, void* kernelPtr) {
    Page pages[1024] = {};
    MemoryManager memoryManager(heapBottom, pages);
    Terminal terminal;

    KERNEL = static_cast<Kernel*>(kernelPtr);
    *KERNEL = Kernel(&memoryManager, &terminal);

    main();

    while(true);
}