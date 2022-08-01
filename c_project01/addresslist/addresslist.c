#include "addresslist.h"
#include "mystring.h"

static student stu[MAXSIZE] = { 0 };

void menu()
{
    
    system("clear");
    printf("--------------------------------\n");
    printf("|                           \t|\n");  
    printf("|   1.修改信息       2.删除信息\t|\n");
    printf("|   3.浏览信息       4.添加信息\t|\n"); 
    printf("|   5.检索信息       6.保存更改\t|\n");
    printf("|   7.查看说明       8.退出系统\t|\n");   
    printf("|                           \t|\n"); 
    printf("--------------------------------\n");

}

void init()
{
    FILE *f = NULL;

    int i = 0;

    if ((f = fopen("/home/xu/homework/c_project01/information.txt", "r")) == NULL)  //打开文件流
    {
        printf("文件打开失败！\n");
        return ;
    }
    while (1)
    {
        if ((fscanf(f, "%s %s %s %d", stu[i].no, stu[i].name, stu[i].tel, &stu[i].age)) == EOF)  //读取文件流信息
        {
            break;
        }
        i++;
    }
    fclose(f);  //关闭文件流

}

int updateInfor()
{
    char update_no[10];
    char update_name[15];
    char update_tel[12];

    int i = 0;

    printf("请输入要修改的学生信息的学号：");
    scanf("%s", update_no);
    while (i < MAXSIZE)
    {
        if (_strcmp(stu[i].no, update_no) == 0)   //若检索到需要修改的学生信息的学号
        {
            printf("现具体信息为：\n");
            printf("学号\t姓名\t电话\t年龄\n");
            printf("%s\t%s\t%s\t%d\n", stu[i].no, stu[i].name, stu[i].tel, stu[i].age);
            printf("请依次输入新的姓名，电话，年龄。\n");
            printf("姓名：");
            scanf("%s", update_name);
            _strcpy(stu[i].name, update_name);
            printf("电话：");
            while (1)
            {
                scanf("%s", update_tel);
                if (_strlen(update_tel) == 11)
                    break;
                printf("您输入的电话号码不正确，请重新输入！\n");
            }
            _strcpy(stu[i].tel, update_tel);
            printf("年龄：");
            scanf("%d", &stu[i].age);
            break;
        }
        i++;
    }
    if (i < MAXSIZE)
    {
        printf("修改成功！\n");
        printf("注意保存！\n");
        getchar();
        printf("按回车键返回");
        while (1)
        {
            if (10 == getchar())   //直到按回车键返回，否则一直循环睡眠两秒
                break;
            sleep(2);
        }
        return 0;
    }
    else   //i=MAXSIZE说明，检索了全部都没有检索到
    {
        printf("修改失败，查无此人！\n");
        printf("两秒后返回主页面\n");
        sleep(2);
        return -1;
    }

}

int delInfor()
{
    char del_no[10];

    int i = 0;
    
    printf("请输入要删除的学生信息的学号：");
    scanf("%s", del_no);
    while (i < MAXSIZE)
    {
        if (_strcmp(stu[i].no, del_no) == 0)
        {
            _strcpy(stu[i].no, "");
            _strcpy(stu[i].name, "");
            _strcpy(stu[i].tel, "");
            stu[i].age = 0;
            break;
        }
        i++;
    }
    if (i < MAXSIZE)
    {
        printf("删除成功！\n");
        printf("注意保存!\n");
        printf("按回车键返回\n");
        getchar();
        while (1)
        {
            if (10 == getchar())
                break;
            sleep(2);
        }
        return 0;
    }
    else
    {
        printf("查无此人!\n");
        printf("两秒后返回主页面\n");
        sleep(2);
        return -1;
    }
}

void scanInfor()
{
    int i = 0;
    //int scan_stu_length = 0;

    //student scan_stu[MAXSIZE] = { 0 };

    system("clear");
    printf("学号\t姓名\t电话\t年龄\n");
    while (i < MAXSIZE)
    {
        if (stu[i].age != 0)
            printf("%s\t%s\t%s\t%d\n", stu[i].no, stu[i].name, stu[i].tel, stu[i].age);
        // {
        //     _strcpy(scan_stu[scan_stu_length].no, stu[i].no);
        //     _strcpy(scan_stu[scan_stu_length].name, stu[i].name);
        //     _strcpy(scan_stu[scan_stu_length].tel, stu[i].tel);
        //     scan_stu[scan_stu_length].age = stu[i].age;
        //     scan_stu_length++;
        // }
        i++;
    }
    printf("按回车键返回\n");
    getchar();
    while (1)
    {
        if (10 == getchar())
            break;
        sleep(2);
    }
}

int addInfor()
{
    char add_no[10];
    char add_name[15];
    char add_tel[12];

    int add_age;
    int i;

    printf("请依次输入要添加的学生信息\n");
    printf("学号：");
    while (1)
    {
        int flag = 0;  //设立标志
        i = 0;

        scanf("%s", add_no);
        while (i < MAXSIZE)
        {
            if (_strcmp(add_no, stu[i].no) == 0)  //若该学号已存在，则设立标志为1，继续循环
            {
                flag = 1;
                break;
            }
            i++;
        }
        if (flag == 0)   //若标志仍为0，则说明该学号不存在，退出循环
        {
            break;
        }
        printf("该学号已存在\n");
        printf("请重新输入：");
    }
    printf("姓名：");
    scanf("%s", add_name);
    getchar();
    printf("电话：");
    while (1)
    {
        scanf("%s", add_tel);
        if (_strlen(add_tel) == 11)  //直到电话号码长度为11才退出循环
            break;
        printf("格式不正确，请重新输入\n");
    }
    printf("年龄：");
    scanf("%d", &add_age);
    i = 0;
    while (1)
    {
        if (stu[i].age == 0)
            break;      
        i++;  
    }
    if (i < MAXSIZE)
    {
        _strcpy(stu[i].no, add_no);
        _strcpy(stu[i].name, add_name);
        _strcpy(stu[i].tel, add_tel);
        stu[i].age = add_age;
        printf("添加成功！\n");
        printf("注意保存！\n");
        printf("按回车键返回\n");
        getchar();
        while (1)
        {
            if (10 == getchar())
                break;
            sleep(2);
        }
        return 0;
    }
    else
    {
        printf("添加失败！\n");
        printf("两秒后返回主页面\n");
        sleep(2);
        return -1;
    }
}

int retrieveInfor()
{
    char re_no[15];
    char re_name[15];

    int choice;
    int i = 0;

    printf("您是要1、输入学号检索学生信息还是2、输入姓名检索学生信息？1or2？\n");
    while (1)
    {
        scanf("%d", &choice);
        if (choice == 1 || choice == 2)
            break;
        printf("输入不正确！请重新输入！\n");
    }
    if (choice == 1)
    {
        printf("请输入要检索的学生信息的学号：");
        scanf("%s", re_no);
        while (i < MAXSIZE)
        {
            if (_strcmp(stu[i].no, re_no) == 0)
                break;
            i++;
        }
        if (i < MAXSIZE)
        {
            printf("检索成功！\n");
            printf("学生信息为\n");
            printf("学号\t姓名\t电话\t年龄\n");
            printf("%s\t%s\t%s\t%d\n", stu[i].no, stu[i].name, stu[i].tel, stu[i].age);
            printf("按回车键返回\n");
            getchar();
            while (1)
            {
                if (10 == getchar())
                    break;
                sleep(2);
            }
            return 0;
        }
        else
        {
            printf("检索失败，查无此人！\n");
            printf("两秒后返回主页面\n");
            sleep(2);
            return -1;
        }
    }
    else
    {
        int flag = 0;  //标志是否检索到相应学生，若检索到，则置1

        printf("请输入要检索的学生信息的姓名：");
        scanf("%s", re_name);
        while (i < MAXSIZE)
        {
            if (_strcmp(stu[i].name, re_name) == 0)
            {
                flag = 1;  //置1，表示检索到人了
                printf("检索成功！\n");
                printf("学生信息为\n");
                printf("学号\t姓名\t电话\t年龄\n");
                printf("%s\t%s\t%s\t%d\n", stu[i].no, stu[i].name, stu[i].tel, stu[i].age);
            }
            i++;
        }
        if (flag == 1)
        {
            printf("按回车键返回\n");
            getchar();
            while (1)
            {
                if (10 == getchar())
                    break;
                sleep(2);
            }
            return 0;
        }
        else
        {
            printf("检索失败，查无此人！\n");
            printf("两秒后返回主页面\n");
            sleep(2);
            return -1;
        }
    }
}

int saveInfor()
{
    FILE *f = NULL;

    int i = 0;

    if ((f = fopen("/home/xu/homework/c_project01/information.txt", "w")) == NULL) //以只写形式打开文件
    {
        printf("文件打开失败！\n");
        return -1;
    }
    while (i < MAXSIZE)
    {
        if (stu[i].age != 0) //若年龄不为0，则说明该条信息为有效信息，写入文件流
        {
            fprintf(f, "%s %s %s %d\n", stu[i].no, stu[i].name, stu[i].tel, stu[i].age);  //注意加换行符
        }
        i++;
    }
    printf("保存成功！\n");
    printf("按回车键返回\n");
    getchar();
    while (1)
    {
        if (10 == getchar())
            break;
        sleep(2);
    }
    fclose(f);

    return 0;

}

void instructions()
{
    system("clear");
    printf("说明\n\n");
    printf("通讯录管理系统\n");
    printf("具有简单的crud功能\n");
    printf("按回车键返回\n");
    getchar();
    while (1)
    {
        if (10 == getchar())
            break;
        sleep(2);
    }
}