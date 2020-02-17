//
// Created by haisheng.lu on 2020/2/16.
//

#ifndef NDK_SYSTEM_ARRAYCOPY_ARRAYSTACK_HPP
#define NDK_SYSTEM_ARRAYCOPY_ARRAYSTACK_HPP

#endif //NDK_SYSTEM_ARRAYCOPY_ARRAYSTACK_HPP

#include <malloc.h>


template <class E>
class ArrayStack{
private:
    int top = -1;
    E* array = NULL;
    int size = 10;

    void grow();
public:
    ArrayStack();
    ~ArrayStack();

    void push(E);
    bool isEmpty();
    E pop();
};

template <class E>
ArrayStack<E>::ArrayStack() {
    array = static_cast<E*>(malloc(sizeof(E) * size));
}

template <class E>
ArrayStack<E>::~ArrayStack() {
    if (array){
        free(array);
    }
}

template <class E>
bool ArrayStack<E>::isEmpty() {
    return top == -1;
}

template <class E>
void ArrayStack<E>::push(E e) {
    if (top+1 > size){
        grow();
    }
    array[++top] = e;
}

template <class E>
E ArrayStack<E>::pop() {
    return array[top--];
}

template<class E>
void ArrayStack<E>::grow() {
    size = size + size >> 1;
    array = (E *) realloc(array, size * sizeof(E));
}
