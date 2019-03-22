#include<stdio.h>
#include<stdlib.h>
#include<jni.h>
#include <unistd.h>
#include <string.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
int i =0;
int flag =1;
void JNICALL Java_test_com_zh_uninstalllistener_MainActivity_callC
        (JNIEnv * env, jobject obj){
    int pid = fork();
    LOGI("flag==%d",pid);
    if(pid==0){
        // 表示拆分成功
        // 这是一个死循环
        while (flag){
            i++;
            FILE* f = fopen("/data/data/test.com.zh.uninstalllistener","rw");
            if(f==NULL){
                LOGI("文件已经不存在了啊");
                // 文件不存在了
                // 调用C代码执行一个外部命令开启一个界面
//        int execlp(const char* __file, const char* __arg0, ...) __attribute__((__sentinel__));
//                execlp("am","am","start","-a","android.intent.action.VIEW","-d","http://www.baidu.com",NULL);
              /*  execlp("am", "am", "start", "-a", "android.intent.action.VIEW",
                       "-d", "http://www.baidu.com", NULL);*/
                execlp("am","am","start","--user","0","-a","android.intent.action.VIEW","-d","http://www.baidu.com",(char*)NULL);
                flag=0;
            }else{
                LOGI("文件已经存在");
            }
            LOGI("我还活着呢");
            LOGI("flag==%d",i);
            sleep(1);
        }
    }


}
