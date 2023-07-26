#include "Hello.h"
#include <jni.h>
#include <stdio.h>

JNIEXPORT void JNICALL Java_Hello_sayHello(JNIEnv *, jobject){
    printf("Hello JNI\n");
}