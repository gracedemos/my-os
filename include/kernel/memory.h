#ifndef LIBCPP
    #include <libcpp/libcpp.h>
#endif

#define KERNEL_MEM

struct Page {
    size_t size;
    void* pointer;
};

class MemoryManager {
    public:
    MemoryManager(void* initHeapBottom, Page* initPages);
    void* allocateMemory(size_t size);
    void freeMemory(void* pointer);

    private:
    void* heapBottom;
    void* heapPointer;
    Page* pages;
    int pageCount;
};