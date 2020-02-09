//
// Created by haisheng on 2020/2/9. 双链表
//

#ifndef NDK_SYSTEM_ARRAY_COPY_LINKEDLIST_H
#define NDK_SYSTEM_ARRAY_COPY_LINKEDLIST_H

#endif //NDK_SYSTEM_ARRAY_COPY_LINKEDLIST_H

template<class E>
struct Node_ {
    Node_<E> *pre;
    Node_<E> *next;
    E value;
//public:
//    Node(E value,Node<E>* pre,Node<E> *next){
//        this->value = value;
//        this->pre = pre;
//        this->next = next;
//    }
};

template<class E>
class LinkedList {
private:
    Node_<E> *getIndexNode(int index);

public:
    //头指针
    Node_<E> *head = NULL;
    int len = 0;
    Node_<E> *last = NULL;
public:
    void push(E e);

    int size();

    E get(int index);

    void insert(int index, E e);
};

template<class E>
void LinkedList<E>::insert(int index, E e) {
    if (index == len) {
        push(e);
    } else {
        Node_<E> *node = static_cast<Node_<E> *>(malloc(sizeof(Node_<E>)));
        node->value = e;
        Node_<E> *cur = getIndexNode(index);
        Node_<E> *pre = cur->pre;
       // Node_ *next = cur->next;
        node->next = pre;
        cur->pre = node;
        if(pre){
            pre->next = node;
            node->pre = pre;
        }else{
            head = node;
        }
        len++;
    }
}


template<class E>
void LinkedList<E>::push(E e) {
    Node_<E> *node = static_cast<Node_<E> *>(malloc(sizeof(Node_<E>)));
    node->value = e;
    //Node* node = new Node(e,lastNode,NULL);
    Node_<E>* lastNode = last;
    if (head) {
        lastNode->next = node;
        node->pre = lastNode;
        last = node;
    } else {
        head = node;
        last = node;
    }

    len++;
}

template<class E>
int LinkedList<E>::size() {
    return len;
}

template<class E>
Node_<E> *LinkedList<E>::getIndexNode(int index) {
    if (index < len >> 1) {
        // 从前往后变量
        struct Node_<E> *temp = this->head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    } else {
        // 从后往前遍历
        struct Node_<E> *temp = this->last;
        for (int i = this->len; i > index; --i) {
            temp = temp->pre;
        }
        return temp;
    }
}

template<class E>
E LinkedList<E>::get(int index) {
    if (index < len >> 1) {
        // 从前往后变量
        struct Node_<E> *temp = this->head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->value;
    } else {
        // 从后往前遍历
        struct Node_<E> *temp = this->last;
        for (int i = this->len; i > index; --i) {
            temp = temp->pre;
        }
        return temp->value;
    }
   // return this->getIndexNode(index)->value;
}