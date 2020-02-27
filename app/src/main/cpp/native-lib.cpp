#include <jni.h>
#include <string>
#include "ArrayList1.hpp"
#include "SingleLinkedList.hpp"
#include "LinkedList.hpp"
#include "AndroidLog.h"
#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"
#include "AndroidLog.h"
#include "TreeNode.hpp"

using  namespace std;
//前序遍历
void preOrderTraverse(TreeNode<char>* root){
    if (root == NULL){
        return;
    }
    LOGD("前序 %c",root->data);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

//中序遍历
void minOrderTraverse(TreeNode<char>* root){
    if (root == NULL){
        return;
    }
    minOrderTraverse(root->left);
    LOGD("中序 %c",root->data);
    minOrderTraverse(root->right);
}

//后序序遍历
void backOrderTraverse(TreeNode<char>* root){
    if (root == NULL){
        return;
    }
    backOrderTraverse(root->left);
    backOrderTraverse(root->right);
    LOGD("后序 %c",root->data);
}

#include <queue>
//利用队列的先进后出的原理 实现 层次遍历
void levelOrderTraverse(TreeNode<char>* root){
    queue<TreeNode<char>*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode<char>*  fr =  q.front();
        LOGD("层次 %c",fr->data);
        q.pop();
        if(fr->left){
            q.push(fr->left);
        }
        if(fr->right){
            q.push(fr->right);
        }
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_aispeech_array_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";


    ArrayList1<int> array(5);
    for (int i = 0; i < 100; ++i) {
        array.add(i);
    }

    for (int i = 0; i < 100; ++i) {
        int d = array.get(i);
        LOGD("d= %d",d);
    }

    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.push(5);
    singleLinkedList.push(10);
    singleLinkedList.push(11);
    singleLinkedList.push(33);
    for (int i = 0; i < singleLinkedList.size(); ++i) {
        int d = singleLinkedList.get(i);
        LOGD("singleLinkedList (%d)",d);
    }

    singleLinkedList.insert(0,100);
    singleLinkedList.insert(singleLinkedList.size(),101);
    singleLinkedList.insert(3,55);
    for (int i = 0; i < singleLinkedList.size(); ++i) {
        int d = singleLinkedList.get(i);
        LOGD("singleLinkedList insert之后 (%d)",d);
    }

//   int re0 =  singleLinkedList.remove(0);
//    int re5 =  singleLinkedList.remove(5);
//    for (int i = 0; i < singleLinkedList.size(); ++i) {
//        int d = singleLinkedList.get(i);
//        LOGD("singleLinkedList remove (%d)",d);
//    }
//    LOGD("singleLinkedList re0 = %d re5 = %d",re0,re5);

//
//    LinkedList<int > linkedList;
//    linkedList.push(1);
//    linkedList.push(2);
//    linkedList.push(3);
//    linkedList.push(4);
//    linkedList.push(5);
//
//    for (int i = 0; i < linkedList.size(); ++i) {
//        int d = linkedList.get(i);
//        LOGD("linkedList push (%d)",d);
//    }
//    linkedList.insert(3,33);
//    for (int i = 0; i < linkedList.size(); ++i) {
//        int d = linkedList.get(i);
//        LOGD("linkedList insert (%d)",d);
//    }
    //二叉树遍历
    LOGD("二叉树遍历");
    TreeNode<char>* root = new TreeNode<char>('A');
    TreeNode<char>* rootB =new TreeNode<char>('B');
    TreeNode<char>* rootC = new TreeNode<char>('C');
    TreeNode<char>* rootD = new TreeNode<char>('D');
    TreeNode<char>* rootE = new TreeNode<char>('E');
    TreeNode<char>* rootF =new  TreeNode<char>('F');
    TreeNode<char>* rootG =new  TreeNode<char>('G');
    TreeNode<char>* rootH =new  TreeNode<char>('H');

    root->left = rootB;
    root->right = rootF;
    //rootB->left = rootD;
    rootB->right = rootC;
    rootC->left = rootD;
    rootC->right = rootE;
    rootF->right = rootG;
    rootG->left = rootH;
    preOrderTraverse(root);
    minOrderTraverse(root);
    backOrderTraverse(root);
    levelOrderTraverse(root);
    return env->NewStringUTF(hello.c_str());
}
