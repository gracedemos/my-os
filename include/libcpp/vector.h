#ifndef LIBCPP
    #include <libcpp/libcpp.h>
#endif

template <typename T> class Vector {
    public:
    Vector();
    Vector(size_t initSize);

    void push(T element);
    T* data();
    T* operator[](size_t index);

    private:
    size_t size;
    T* array;
};