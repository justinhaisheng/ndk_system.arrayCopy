#include <jni.h>
#include <string>
#include "ArrayList1.hpp"
#include "SingleLinkedList.hpp"
#include "AndroidLog.h"

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

   int re0 =  singleLinkedList.remove(0);
    int re5 =  singleLinkedList.remove(5);
    for (int i = 0; i < singleLinkedList.size(); ++i) {
        int d = singleLinkedList.get(i);
        LOGD("singleLinkedList remove (%d)",d);
    }
    LOGD("singleLinkedList re0 = %d re5 = %d",re0,re5);

    return env->NewStringUTF(hello.c_str());
}
