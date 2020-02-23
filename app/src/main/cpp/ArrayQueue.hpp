//
// Created by haisheng.lu on 2020/2/19.
//

#ifndef NDK_SYSTEM_ARRAYCOPY_ARRAYQUEUE_HPP
#define NDK_SYSTEM_ARRAYCOPY_ARRAYQUEUE_HPP

#endif //NDK_SYSTEM_ARRAYCOPY_ARRAYQUEUE_HPP

#include <malloc.h>



template<class E>
class ArrayQueue{
private:
    int size = 0;
    //头索引
    int head = 0;
    //尾索引
    int tail = 0;
    E* array;
public:
    ArrayQueue();
    ArrayQueue(int size);
    ~ArrayQueue();
    
    bool isEmpty();
    E pop();
    void push(E e);
    // 获取队首的位置，但是不移除
    E peek();
    
    void growArray();
    void copyElement(E* sourceArray,int SourcePos,E* targetArray,int targetPos,int len);
};

template<class E>
ArrayQueue<E>::ArrayQueue():ArrayQueue(4) {

}

template<class E>
ArrayQueue<E>::ArrayQueue(int size) {
    int init_size = size;
    if(init_size >=4){
        init_size|= init_size >>1;
        init_size |= init_size >> 1;
        init_size |= init_size >> 2;
        init_size |= init_size >> 4;
        init_size |= init_size >> 8;
        init_size |= init_size >> 16;
        // int 4 字节  32
        init_size += 1;//2的幂次方
    }
    array = (E *) malloc(sizeof(E) * init_size);
    this->size = init_size;//保证了 size是2的幂次方
}

template<class E>
void ArrayQueue<E>::push(E e) {
    this->head = (this->head - 1) & (this->size -1);
    array[head] = e;
    if (tail == head){
        growArray();//扩容
    }
}

template<class E>
bool ArrayQueue<E>::isEmpty() {
    return this->head = this->tail;
}

template<class E>
E ArrayQueue<E>::pop() {
    this->tail = (this->tail - 1) & (this->size -1);
    return array[tail];
}

template<class E>
void ArrayQueue<E>::growArray() {
    int new_size = size << 1;
    // 扩容
    E *new_array = (E *) malloc(sizeof(E) * new_size);
    int r = size - tail;
    copyElement(array,tail,new_array,0,r);
    copyElement(array,0,new_array,r,tail);
    head = 0;
    tail = size;
    free(array);
    size = new_size;
    array = new_array;

}

template<class E>
void ArrayQueue<E>::copyElement(E *sourceArray, int SourcePos, E *targetArray, int targetPos,
                             int len) {
    for (int i = 0; i < len; ++i) {
        targetArray[targetPos + i] = sourceArray[SourcePos + i];
    }
}
template<class E>
ArrayQueue<E>::~ArrayQueue() {
    free(array);
}