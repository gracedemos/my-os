#include <libcpp/vector.h>
#include <libcpp/libmem.h>

template <typename T> Vector<T>::Vector() {
    size = 0;
    array = nullptr;
}

template <typename T> Vector<T>::Vector(size_t initSize) {
    if(initSize > 0) {
        size = initSize;
        array = malloc(initSize);
    }else {
        size = 0;
        array = nullptr;
    }
}

template <typename T> void Vector<T>::push(T element) {
    if(size > 0) {
        size++;
        T newArray[size];
        for(int i = 0; i < size - 1; i++) {
            newArray[i] = array[i];
        }
        free(array);
        newArray[size - 1] = element;
        array = malloc(size);
        for(int i = 0; i < size; i++) {
            array[i] = newArray[i];
        }
    }else {
        array = malloc(sizeof(element));
        size = sizeof(element);
    }
}

template <typename T> T* Vector<T>::data() {
    return array;
}

template <typename T> T* Vector<T>::operator[](size_t index) {
    return &array[index];
}