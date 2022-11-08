#ifndef LIBCPP
    #include <libcpp/libcpp.h>
#endif

template <typename T> class Vector {
    public:
    Vector(size_t initSize);

    private:
    size_t size;
    T* array;
};