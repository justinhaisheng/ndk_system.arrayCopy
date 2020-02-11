//
// Created by haisheng on 2020/2/9. 双链表
//

#ifndef NDK_SYSTEM_ARRAY_COPY_LINKEDLIST_H
#define NDK_SYSTEM_ARRAY_COPY_LINKEDLIST_H

#endif //NDK_SYSTEM_ARRAY_COPY_LINKEDLIST_H

template<class E>
struct Node_ {
    Node_<E> *prev;
    Node_<E> *next;
    E value;
public:
    Node_(E value,Node_<E>  *prev,Node_<E>* next){
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

template<class E>
class LinkedList {
private:
    Node_<E> *getIndexNode(int index);
    void linkLast(E e);
    void linkFirst(Node_<E> *pNode,E e);
    E unlink(Node_<E> *pNode);
    //头指针
    Node_<E> *head = NULL;
    int len = 0;
    Node_<E> *last = NULL;
public:

public:
    void push(E e);
    int size();
    E get(int index);
    void insert(int index, E e);
    E remove(int index);
    ~LinkedList();
};

template<class E>
void LinkedList<E>::insert(int index, E e) {
    assert(index>=0 && index < len);
    if (index == len){
        linkLast(e);
    }else{
        linkFirst(getIndexNode(index),e);
    }
    len ++;
}

template<class E>
void LinkedList::linkFirst(Node_<E> *pNode, E e) {
    Node_<E>* prev = pNode->prev;
    Node_<E>* node = new Node_<E>(e,prev,pNode);
    pNode->prev = node;
    if(prev){
        prev->next = node;
    }else{// pNode 是头结点
        head = node;
    }

}

template<class E>
void LinkedList<E>::push(E e) {
//        Node_<E> *node = static_cast<Node_<E> *>(malloc(sizeof(Node_<E>)));
//        node->value = e;
//        //Node* node = new Node(e,lastNode,NULL);
//        Node_<E>* lastNode = last;
//        if (head) {
//            lastNode->next = node;
//            node->pre = lastNode;
//            last = node;
//        } else {
//            head = node;
//            last = node;
//        }
    linkLast(e);
    len++;
}

template<class E>
void LinkedList<E>::linkLast(E e) {
    Node_<E>* lastNode = last;
    Node_<E>* node = new Node_<E>(e,lastNode,NULL);
    last = node;
    if (head){
        lastNode->next = node;
    }else{
        head = node;
    }
}


template<class E>
int LinkedList<E>::size() {
    return len;
}

template<class E>
Node_<E> *LinkedList<E>::getIndexNode(int index) {
    if (index < len >> 1) {
        // 从前往后变量
       Node_<E>* h = head;
        for (int i = 0; i < index; ++i) {
            h = h->next;
        }
        return h;
    } else {
        // 从后往前遍历
        Node_<E> *l = this->last;
        for (int i = len -1 ; i > index; --i) {
            l = l->prev;
        }
        return l;
    }
}

template<class E>
E LinkedList<E>::get(int index) {
    assert(index >=0 && index < len);
    return getIndexNode(index)->value;
}

template<class E>
LinkedList<E>::~LinkedList() {
    Node_* node = head;
    while (node){
        Node_* temp = node;
        node = node->next;
        delete(temp);
    }
    head = NULL;
    last = NULL;
}

template<class E>
E LinkedList<E>::remove(int index) {
    assert(index>=0 && index < len);
    E value;
    return unlink(getIndexNode(index));
}

template<class E>
E LinkedList<E>::unlink(Node_<E> *pNode) {
    E value = pNode->value;
    Node_<E>* prev = pNode->prev;
    Node_<E>* next = pNode->next;

    if (prev){
        prev->next = next;
    }else{
        head = pNode;
    }

    if(next){
        next->prev = prev;
    }else{
        last = prev;
    }
}