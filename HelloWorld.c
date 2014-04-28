/*
 * =====================================================================================
 *
 *       Filename:  HelloWorld.c
 *
 *    Description:  test for jni
 *
 *        Version:  1.0
 *        Created:  04/28/2014 09:58:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (baifendian), yang.yue@baifendian.com
 *        Company:  baifendian.com
 *
 * =====================================================================================
 */

#include <jni.h>
#include <stdio.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL
Java_HelloWorld_print(JNIEnv *env, jobject obj) {
    printf("Hello World!\n");
    return;
}
