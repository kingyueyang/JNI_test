/*
 * =====================================================================================
 *
 *       Filename:  s2.c
 *
 *    Description:  id
 *
 *        Version:  1.0
 *        Created:  04/28/2014 10:42:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (baifendian), yang.yue@baifendian.com
 *        Company:  baifendian.com
 *
 * =====================================================================================
 */

#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define PATH_SEPARATOR ':'

int
main( int argc, char *argv[] ) {
    JavaVMOption options[1];
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args;

    long status;
    jclass cls;
    jmethodID mid;
    jfieldID fid;
    jobject obj;

    options[0].optionString = "-Djava.class.path=.";
    memset(&vm_args, 0, sizeof(vm_args));
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;


    /*Start vm*/
    status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

    if(status != JNI_ERR) {
        /*Get class*/
        cls = (*env)->FindClass(env, "Sample2");

        if(cls != 0) {
            /*Get fun ID*/
            mid = (*env)->GetStaticMethodID(env, cls, "sayHello", "(Ljava/lang/String;)Ljava/lang/String;");

            if(mid != 0) {
                const char* name = "World";
                jstring arg = (*env)->NewStringUTF(env, name);
                jstring result = (jstring)(*env)->CallStaticObjectMethod(env, cls, mid, arg);
                const char* str = (*env)->GetStringUTFChars(env, result, 0);
                printf("Result of sayHello: %s\n", str);
                (*env)->ReleaseStringUTFChars(env, result, 0);
            }

            /*Call Constructor*/
            mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
            obj = (*env)->NewObject(env, cls, mid);
            if(obj == 0) {
                printf("Create object failed!\n");
            }

            fid = (*env)->GetFieldID(env, cls, "name", "Ljava/lang/String;");
            if(fid != 0) {
                const char* name = "icejoywoo";
                jstring arg = (*env)->NewStringUTF(env, name);
                (*env)->SetObjectField(env, obj, fid, arg);
            }

            mid = (*env)->GetMethodID(env, cls, "sayHello", "()Ljava/lang/String;");
            if(mid != 0) {
                jstring result = (jstring)(*env)->CallObjectMethod(env, obj, mid);
                const char* str = (*env)->GetStringUTFChars(env, result, 0);
                printf("Result of sayHello: %s\n", str);
                (*env)->ReleaseStringUTFChars(env, result, 0);
            }
        }

        (*jvm)->DestroyJavaVM(jvm);
        return 0;
    }else{
        printf("JVM Created Failed!\n");
        return EXIT_FAILURE;
    }



    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
