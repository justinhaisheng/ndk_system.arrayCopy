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

#include "cmath"

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




int getDepthTree(TreeNode<char> *pNode){
    if (!pNode){
        return 0;
    }
    int leftCount = getDepthTree(pNode->left);
    int rightCount = getDepthTree(pNode->right);
    return max(leftCount,rightCount) + 1;
}

//判断是否是平衡二叉树 空树是 、每颗树的左右子树的高度不会超过一
bool isBalanceTree(TreeNode<char> *pNode) {
    if (!pNode){
        return true;
    }
    int left = getDepthTree(pNode->left);
    int  right = getDepthTree(pNode->right);
    return abs(left - right) <=1 && isBalanceTree(pNode->left) && isBalanceTree(pNode->right);
}

void serialized(TreeNode<char> *pNode,char s[],int &index){
    if (!pNode){
        s[index]= '#';
        LOGI("serialized # index=%d",index);
        index = index+1;
        return;
    }
    s[index] = pNode->data;
    LOGI("serialized %c index=%d",pNode->data,index);
    index = index+1;
    serialized(pNode->left,s,index);
    serialized(pNode->right,s,index);
}

TreeNode<char>* reSerialized(char s[],int &index){
    if (s[index] == '#'){
        index = index+1;
        return NULL;
    }
    TreeNode<char>* root = new TreeNode<char>(s[index]);
    index = index+1;
    //LOGI("reSerialized %c index=%d",pNode->data,index);
    index = index+1;
    reSerialized(s,index);
    reSerialized(s,index);
    return root;
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


    int count = getDepthTree(root);
    bool  ba = isBalanceTree(root);
    LOGE("二叉树 count%d %d",count,ba);

    LOGD("序列化和反序列化");
    TreeNode<char>* serializeA = new TreeNode<char>('A');
    TreeNode<char>* serializeB = new TreeNode<char>('B');
    TreeNode<char>* serializeC = new TreeNode<char>('C');
    TreeNode<char>* serializeD = new TreeNode<char>('D');
    TreeNode<char>* serializeE = new TreeNode<char>('E');
    TreeNode<char>* serializeF = new TreeNode<char>('F');

    serializeA->left = serializeB;
    serializeA->right = serializeC;
    serializeB->left = serializeD;
    serializeB->right = serializeE;
    serializeC->right = serializeF;

    char* serialize = static_cast<char *>(malloc(sizeof(char) * 30));
    int index = 0;
    serialized(serializeA,serialize,index);
    //preOrderTraverse(serializeA);
    LOGE("serialize= %s",serialize);
    free(serialize);

    return env->NewStringUTF(hello.c_str());
}
