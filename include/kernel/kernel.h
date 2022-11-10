#include <kernel/memory.h>
#include <kernel/terminal.h>

class Kernel {
    public:
    Kernel(MemoryManager* initMemoryManager, Terminal* initTerminal);
    MemoryManager* getMemoryManager();
    Terminal* getTerminal();

    private:
    MemoryManager* memoryManager;
    Terminal* terminal;
};

Kernel* getKernel();