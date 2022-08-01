#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <stddef.h>
/*
封装的字符串处理函数
*/

int _strlen(char *str);  //计算字符串长度
int _strcmp(char *str1, char *str2);  //比较字符串大小
int _strncmp(char *str1, char *str2, int str2_length);  //字符串2的前n字符与字符串1比较
char *_strcpy(char *str1, char *str2); //复制字符串2到字符串1
char *_strncpy(char *str1, char *str2, int n);  //字符串2的前n字符赋予字符串1
char *_strcat(char *str1, char *str2); //字符串2拼接到字符串1尾部 
char *_strncat(char *str1, char *str2, int n);

#endif