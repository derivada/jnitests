#include "Example1.h"
#include <string.h>

/* 
* Compile as shared library:
* gcc -c -Wall -fpic Example.c -I/usr/lib/jvm/java-11-openjdk-amd64/include/ -I/usr/lib/jvm/java-11-openjdk-amd64/include/linux/
*
* Resources: 
*
* 
*/

JNIEXPORT jint JNICALL Java_Example1_intMethodName(JNIEnv *env, jobject obj, jint num)
{
    return num * num;
}

JNIEXPORT jboolean JNICALL Java_Example1_booleanMethodName(JNIEnv *env, jobject obj, jboolean bool)
{
    return !bool;
}

JNIEXPORT jstring JNICALL Java_Example1_stringMethodName(JNIEnv *env, jobject obj, jstring string)
{
    const char *str = (*env)->GetStringUTFChars(env, string, 0);
    char cap[128];
    strcpy(cap, str);
    for (int i = 0; cap[i] != '\0'; i++)
    {
        if (cap[i] >= 'a' && cap[i] <= 'z')
        {
            cap[i] = cap[i] - 32;
        }
    }
    (*env)->ReleaseStringUTFChars(env, string, str);
    return (*env)->NewStringUTF(env, cap);
}

JNIEXPORT jint JNICALL Java_Example1_intArrayMethodName(JNIEnv *env, jobject obj, jintArray arr)
{
    int sum = 0;
    jsize len = (*env)->GetArrayLength(env, arr);
    jint *body = (*env)->GetIntArrayElements(env, arr, 0);
    for (int i = 0; i < len; i++)
    {
        sum += body[i];
    }
    (*env)->ReleaseIntArrayElements(env, arr, body, 0);
    return sum;
}