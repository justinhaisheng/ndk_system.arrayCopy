//
// Created by haisheng on 2020/2/2.
//

#ifndef NDK_SYSTEM_ARRAY_COPY_ARRAYLIST_H
#define NDK_SYSTEM_ARRAY_COPY_ARRAYLIST_H

#include "AndroidLog.h"
#include <malloc.h>
#include <cstring>

template <class E>
class ArrayList1 {
private:
    E* array;//当前的数组指针
    int len = 0;
    int index = 0;
    void ensureCapacityInternal(int capacity);
    void grow(int capacity);
public:
    ArrayList1(int len);
    ~ArrayList1();
    int add(E e);
    int getSize();
    E remove(int index);
    E get(int index);
};


template <class E>
ArrayList1<E>::ArrayList1(int len){
    if (len < 0){
        return ;
    }
    this->len = len;
    array = (E*)malloc(sizeof(E)*len);
    LOGD("ArrayList1() len= %d",len);
}

template <class E>
ArrayList1<E>::~ArrayList1(){
    if (array){
        free(array);
        array = NULL;
        this ->len = 0;
        this ->index = 0;
    }
}

template <class E>
int ArrayList1<E>::getSize(){
    return this->len;
}

template <class E>
int ArrayList1<E>::add(E e) {
    ensureCapacityInternal(index + 1);  // Increments modCount!!
    array[index++] = e;
    return 1;
}

template <class E>
E ArrayList1<E>::get(int index){
    return array[index];
}

template <class E>
void ArrayList1<E>::ensureCapacityInternal(int capacity) {
    if (this->array == NULL) {
        capacity = 10;
    }
    if (capacity - len >0){
        grow(capacity);
    }
}

template <class E>
void ArrayList1<E>::grow(int capacity){

    int new_len = len + (len >> 1);
    if (capacity - new_len >0){
        new_len = capacity;
    }
    LOGD("grow() capacity=%d new_len=%d",capacity,new_len);
    //创建新的数组
    E* new_e = (E*)malloc(sizeof(E)*new_len);
    if (array){
        memcpy(new_e,this->array, sizeof(E) * index);
        free(array);
    }

    this->array = new_e;
    this->len = new_len;
}

template <class E>
E ArrayList1<E>::remove(int index){
    if (index >= len){
        return NULL;
        //throw new IndexOutOfBoundsException(outOfBoundsMsg(index));
    }

    E oldValue = (E) array[index];
    int numMoved = len - index - 1;
    for (int i = 0; i < numMoved; ++i) {
       array[index+i] =  array[index + i + 1];
    }

    return oldValue;
}

#endif //NDK_SYSTEM_ARRAY_COPY_ARRAYLIST_H
