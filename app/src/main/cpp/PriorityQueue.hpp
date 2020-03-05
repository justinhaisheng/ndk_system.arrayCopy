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
        LOGD("shifUp() pos = %d",pos)
        if (pos>0){
            LOGI("Array[%d] = %d ,Array[%d] = %d",pos,Array[pos],(pos-1)/2,Array[(pos-1)/2]);
            if (Array[pos] > Array[(pos-1)/2]){
                swap(Array[pos],Array[(pos-1)/2]);
                shifUp((pos-1)/2);
            }
        }
    }

    void shifDown(int pos){
        LOGD("shifDown() pos = %d",pos)
        if (pos < (index)/2){
            int max = 2*pos + 1;//左
            if (max+1 <= index && Array[max+1] > Array[max]){
                max = max + 1;//右孩子是最大值
            }
            if(Array[max] > Array[pos]){
                swap(Array[max],Array[pos]);
                pos = max;
                shifDown(pos);
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
        return index < 0;
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

    E pop(){
        E e = Array[0];
        Array[0] = Array[index];
        shifDown(0);
        index-- ;
        return e;
    }

};