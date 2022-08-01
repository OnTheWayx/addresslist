#ifndef _ADDRESS_H
#define _ADDRESS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void menu();  //菜单
void init();  //初始化读入信息
int updateInfor(); //修改所选信息
int delInfor(); //删除所选信息
void scanInfor(); //输出所有信息
int addInfor(); //添加信息
int retrieveInfor(); //检索信息
int saveInfor(); //保存所有更改
void instructions(); //说明书

#endif