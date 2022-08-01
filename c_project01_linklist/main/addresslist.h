
/**
 * @brief 
 * （1）通讯录编号，类型{家庭、工作、同学、亲友}，人数
 * （2）通讯录编号，姓名，关系，手机号码，备注
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mystring.h"

typedef char str_ch;    //存储字符串数据
typedef short sm_num;   //存储较小的整型数字

typedef struct list
{   
    str_ch id[10];
    str_ch name[15];
    str_ch rel[15];
    str_ch tel[12];
    struct list *next;
}list;

//菜单
void menu();
//初始化存储信息链表
list *AddressListCreate();
//初始化读如通讯录信息
void AddressListInit(list **info);
//修改指定用户的信息
void AddressListUpdate(list **info);
//删除指定用户的信息
void AddressListDelete(list **info);
//浏览通讯录信息
void AddressListPrint(list **info);
//添加用户信息
void AddressListInsert(list **info);
//保存所有的更改到文件中
void SaveInformation(list **info);
//说明书
void Instructions();
//程序结束前，清空单链表
void AddressListClear(list **info);
