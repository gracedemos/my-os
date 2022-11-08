#include <kernel/memory.h>

MemoryManager::MemoryManager(void* initHeapBottom, Page* initPages) {
    heapBottom = initHeapBottom;
    heapPointer = initHeapBottom;
    pages = initPages;
    pageCount = 0;
}

void* MemoryManager::allocateMemory(size_t size) {
    Page newPage;
    newPage.size = size;
    newPage.pointer = heapPointer;
    pages[pageCount] = newPage;
    pageCount++;
    heapPointer = static_cast<char*>(heapPointer) + size;
    return newPage.pointer;
}

void MemoryManager::freeMemory(void* pointer) {
    for(int i = 0; i < pageCount; i++) {
        if(pages[i].pointer == pointer) {
            Page newPages[1024] = {};
            for(int j = 0; j < pageCount; j++) {
                if(pages[j].pointer != pointer) {
                    newPages[j] = pages[j];
                }
            }
            pages = newPages;
        }
    }
}