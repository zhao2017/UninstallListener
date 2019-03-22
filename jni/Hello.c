#include<stdio.h>
#include<stdlib.h>
#include<jni.h>
#include <unistd.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
int i =0;
void JNICALL Java_test_com_zh_uninstalllistener_MainActivity_callC
        (JNIEnv * env, jobject obj){
    int flag = fork();
    LOGI("flag==%d",flag);
    if(flag==0){
        // 表示拆分成功
        // 这是一个死循环
        while (1){
            i++;
            LOGI("我还活着呢");
            LOGI("flag==%d",i);
            sleep(1);
        }
    }


}
