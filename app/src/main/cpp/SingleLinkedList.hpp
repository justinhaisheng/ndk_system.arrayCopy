//
// Created by haisheng on 2020/2/9.
//

#ifndef NDK_SYSTEM_ARRAY_COPY_SINGLELINKEDLIST_H
#define NDK_SYSTEM_ARRAY_COPY_SINGLELINKEDLIST_H

#include <assert.h>

template <class E>
class Node{
private:
    E value;
public:
    Node* next;
    Node(E value){
        this->value = value;
        this->next = NULL;
    }
    ~Node(){
        if(this->next){
            free(next);
            this->next = NULL;
        }
    }
    E getValue(){
        return this->value;
    }
};

template <class E>
class SingleLinkedList{
private:
    Node<E>* head = NULL;
    int len = 0;
    Node<E>* getLastNode();
public:
    void push(E e);
    int size();
    E get(int index);
};

template <class E>
Node<E>* SingleLinkedList<E>::getLastNode() {
    assert(this->len>0);
    Node<E>* temp = head;
    for (int i = 0; i < len -1; ++i) {
        temp = temp->next;
    }
    return temp;
}

template <class E>
void SingleLinkedList<E>::push(E e) {
    Node<E>* node = new Node<E>(e);
    if(head){
        //先找出最后一个节点
        Node<E>* lastNode = getLastNode();
        lastNode->next = node;
    } else{ // 如果头指针为null
        this ->head = node;
    }
    this->len ++ ;
}

template <class E>
int SingleLinkedList<E>::size() {
    return this->size();
}

template <class E>
E SingleLinkedList<E>::get(int index) {
    //assert(index>=this->len);
    Node<E>* temp = this->head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->getValue();
}

#endif //NDK_SYSTEM_ARRAY_COPY_SINGLELINKEDLIST_H