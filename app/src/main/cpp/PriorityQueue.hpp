//
// Created by haisheng.lu on 2020/3/5.
//

#ifndef NDK_SYSTEM_ARRAYCOPY_PRIORITYQUEUE_HPP
#define NDK_SYSTEM_ARRAYCOPY_PRIORITYQUEUE_HPP

#endif //NDK_SYSTEM_ARRAYCOPY_PRIORITYQUEUE_HPP

#include <iostream>

using namespace std;

template<class E>
class PriorityQueue{
public:
    int index = 0;
    int count = 0;
    E* Array = NULL;
private:
    void shifUp(int pos){
        LOGD("pos = %d",pos)
        if (pos>0){
            LOGI("Array[%d] = %d ,Array[%d] = %d",pos,Array[pos],(pos-1)/2,Array[(pos-1)/2]);
            if (Array[pos] > Array[(pos-1)/2]){
                swap(Array[pos],Array[(pos-1)/2]);
                shifUp((pos-1)/2);
            }
        }
    }
public:
    PriorityQueue(int count){
        index = 0;
        this->count = count;
        Array = new E[count];
    }
    ~PriorityQueue(){
        delete Array;
    }

    bool isEmpty(){
        return count == 0;
    }

    void push(E e){
        LOGI("push= %d",e);
        Array[index] = e;
        shifUp(index);
        index++;
        for (int i = 0; i < index; ++i) {
            LOGE("PriorityQueue= %d",Array[i]);
        }
        LOGD("---");
    }

};