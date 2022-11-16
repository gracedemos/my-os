#include <libcpp/libmem.h>
#include <kernel/kernel.h>

#ifndef KERNEL_MEM
    #include <kernel/memory.h>
#endif

void* malloc(size_t size) {
    return getKernel()->getMemoryManager()->allocateMemory(size);
}

void free(void* pointer) {
    getKernel()->getMemoryManager()->freeMemory(pointer);
}