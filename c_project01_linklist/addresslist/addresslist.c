/**
 * @file addresslist.c
 * （1）通讯录编号，类型{家庭、工作、同学、亲友}，人数
 * （2）通讯录编号，姓名，关系，手机号码，备注
 * 
 */
#include "addresslist.h"

//菜单
void menu()
{
    //清空终端输出显示
    system("clear");
    printf("--------------------------------\n");
    printf("|                           \t|\n");
    printf("|   1.修改信息       2.删除信息\t|\n");
    printf("|   3.浏览信息       4.添加信息\t|\n");
    printf("|   5.保存修改       6.查看说明\t|\n");
    printf("|   7.退出系统               \t|\n");
    printf("|                           \t|\n");
    printf("--------------------------------\n");
}

//初始化存储信息链表
list *AddressListCreate()
{
    //创建单向链表的头结点
    list *head = (list *)malloc(sizeof(list));
    if (NULL == head)
    {
        printf("%d初始化失败\n", __LINE__);
        return NULL;
    }
    head->next = NULL;

    return head;
}

//初始化读如通讯录信息
void AddressListInit(list **info)
{
    /* 检查传入参数是否有误 */
    for (int i = 0; i < 4; i++)
    {
        if (info[i] == NULL)
        {
            return;
        }
    }
    FILE *fp[4] = {0};
    //打开保存通讯录信息的文件流，把信息读入链表内
    /**
     * @brief 
     * fp[0]    家人
     * fp[1]    同事
     * fp[2]    同学
     * fp[3]    朋友
     * 
     */
    fp[0] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/home.txt", "r");
    fp[1] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/work.txt", "r");
    fp[2] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/class.txt", "r");
    fp[3] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/friends.txt", "r");
    /* 检查所有文件流是否打开成功 */
    for (int i = 0; i < 4; i++)
    {
        if (fp[i] == NULL)
        {
            printf("初始化失败\n");
            exit(1);
            return;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        /* 将各个文件信息读入各自的链表中 */
        while (1)
        {
            //申请空间创建新的结点
            list *tmp = (list *)malloc(sizeof(list));
            tmp->next = NULL;
            if (NULL == tmp)
            {
                printf("申请空间失败！\n");
                return;
            }
            //若读取结束，则在退出循环之前释放上面申请的新结点的空间
            if (fscanf(fp[i], "%s %s %s %s", tmp->id, tmp->name, tmp->rel, tmp->tel) == EOF)
            {
                free(tmp);
                tmp = NULL;
                break;
            }
            //使用头插法插入数据
            tmp->next = info[i]->next;
            info[i]->next = tmp;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        fclose(fp[i]);
    }

    return;
}
//修改指定用户的信息
void AddressListUpdate(list **info)
{
    int choice;

    for (int i = 0; i < 4; i++)
    {
        if (info[i] == NULL)
        {
            return;
        }
    }
    /* 临时保存输入的要修改的信息 */
    str_ch updatebyid[10] = {0};
    str_ch update_name[15] = {0};
    str_ch update_tel[12] = {0};

    system("clear");
    printf("\033[33m***修改通讯录信息***\n");
    printf("\033[33m1.家人\t2.同事\t3.同学\t4.朋友\n");
    printf("\033[37m\n");
    printf("请输入选择：");
    /* 检查选择是否有误 */
    while (1)
    {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        getchar();
        printf("输入错误！请重新输入！\n");
    }
    printf("请输入要修改的用户的编号>>>");
    scanf("%s", updatebyid);
    //记录下头结点，从第一个结点开始遍历单链表，
    //直到找到指定的结点并修改其信息
    list *tmp = info[choice]->next;

    while (tmp != NULL)
    {
        if (_strcmp(tmp->id, updatebyid) == 0)
        {
            printf("用户原信息为>>>\n");
            printf("编号\t姓名\t关系\t电话\n");
            printf("%s\t%s\t%s\t%s\n", tmp->id, tmp->name, tmp->rel, tmp->tel);
            printf("请输入新的信息>>>\n");
            //依次输入新的姓名，电话，年龄
            printf("姓名>>>");
            scanf("%s", update_name);
            printf("电话>>>");
            //判定输入的电话号码的格式是否正确，不正确则重新输入
            while (1)
            {
                scanf("%s", update_tel);
                if (_strlen(update_tel) == 11)
                {
                    break;
                }
                printf("格式不正确，请重新输入！\n");
                printf("电话>>>");
            }
            _strcpy(tmp->name, update_name);
            _strcpy(tmp->tel, update_tel);
            printf("信息修改成功！\n注意保存！\n");
            getchar();
            printf("按回车键返回！\n");
            while (1)
            {
                if (getchar() == 10)
                {
                    break;
                }
                sleep(2);
            }

            return;
        }
        tmp = tmp->next;
    }
    printf("数据修改失败！查无此人！\n两秒后返回主页面！\n");
    sleep(2);
}

//删除指定用户的信息
void AddressListDelete(list **info)
{
    int choice;

    for (int i = 0; i < 4; i++)
    {
        if (info[i] == NULL)
        {
            return;
        }
    }
    system("clear");
    printf("\033[33m***删除通讯录信息***\n");
    printf("\033[33m1.家人\t2.同事\t3.同学\t4.朋友\n");
    printf("\033[37m\n");
    printf("请输入选择：");
    while (1)
    {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        getchar();
        printf("输入错误！请重新输入！\n");
    }
    str_ch delete_id[10] = {0};

    printf("请输入要删除的用户的编号>>>\n");
    printf("编号>>>");
    scanf("%s", delete_id);
    list *tmp = info[choice];
    list *des = NULL;


    system("clear");

    //遍历单链表，记录下要删除的用户的结点
    while (tmp->next != NULL)
    {
        if (_strcmp(tmp->next->id, delete_id) == 0)
        {
            des = tmp->next;
            break;
        }
        tmp = tmp->next;
    }
    // des初值为空，若遍历后des不为空，则说明找到了要删除的用户结点
    if (des != NULL)
    {
        tmp->next = tmp->next->next;
        free(des);
        des = NULL;
        printf("信息删除成功！\n注意保存！\n");
        getchar();
        printf("按回车键返回！\n");
        while (1)
        {
            if (getchar() == 10)
            {
                break;
            }
            sleep(2);
        }
    }
    else
    {
        printf("信息删除失败！查无此人！\n两秒后返回主页面！\n");
        sleep(2);
    }
}

//浏览通讯录信息
void AddressListPrint(list **info)
{
    int choice;
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        if (info[i] == NULL)
        {
            return;
        }
    }
    system("clear");
    printf("\033[33m***浏览通讯录信息***\n");
    printf("\033[33m1.家人\t2.同事\t3.同学\t4.朋友\n");
    printf("\033[37m\n");
    printf("请输入选择：");
    while (1)
    {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        getchar();
        printf("输入错误！请重新输入！\n");
    }
    list *tmp = info[choice];
    while (tmp != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    tmp = info[choice];
    printf("\033[33m人数：%d\n", count);
    printf("\033[37m\n");
    while (tmp != NULL)
    {
        printf("%s\t%s\t%s\t%s\n", tmp->id, tmp->name, tmp->rel, tmp->tel);
        tmp = tmp->next;
    }
    getchar();
    //直到读取到按下回车键再返回主目录
    printf("按回车键返回！\n");
    while (1)
    {
        if (getchar() == 10)
        {
            break;
        }
        sleep(2);
    }
}

//添加用户信息
void AddressListInsert(list **info)
{
    int choice;

    for (int i = 0; i < 4; i++)
    {
        if (info[i] == NULL)
        {
            return;
        }
    }
    system("clear");
    printf("\033[33m***添加通讯录信息***\n");
    printf("\033[33m1.家人\t2.同事\t3.同学\t4.朋友\n");
    printf("\033[37m\n");
    printf("请输入选择：");
    while (1)
    {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        getchar();
        printf("输入错误！请重新输入！\n");
    }
    list *tmp = info[choice];
    //申请空间（要添加的用户的信息）
    list *insert_stu = (list *)malloc(sizeof(list));
    if (NULL == insert_stu)
    {
        printf("内存空间申请失败！\n");
        return;
    }
    insert_stu->next = NULL;

    system("clear");
    printf("请输入要插入的用户的信息>>>\n");
    printf("编号>>>");
    scanf("%s", insert_stu->id);
    //遍历一遍单链表，若要添加的该学号存在，则重新输入
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (_strcmp(tmp->id, insert_stu->id) == 0)
        {
            printf("该编号已存在！请重新输入！\n");
            printf("编号>>>");
            scanf("%s", insert_stu->id);
            tmp = info[choice];
            continue;
        }
    }
    printf("姓名>>>");
    scanf("%s", insert_stu->name);

    /* 自动填充关系 */
    switch (choice)
    {
        case 1:_strcpy(insert_stu->rel, "家人");
        case 2:_strcpy(insert_stu->rel, "同事");
        case 3:_strcpy(insert_stu->rel, "同学");
        case 4:_strcpy(insert_stu->rel, "朋友");
    }

    //判断输入的电话的格式是否正确，若不正确则重新输入
    while (1)
    {
        printf("电话>>>");
        scanf("%s", insert_stu->tel);
        if (_strlen(insert_stu->tel) == 11)
        {
            break;
        }
        printf("格式不正确！请重新输入！\n");
    }
    //采用头插法插入数据
    insert_stu->next = info[choice]->next;
    info[choice]->next = insert_stu;
    printf("用户信息添加成功！\n");
    getchar();
    printf("按回车键返回主页面！\n");
    while (1)
    {
        if (getchar() == 10)
        {
            break;
        }
        sleep(2);
    }
}

//保存所有的更改到文件中
void SaveInformation(list **info)
{
    for (int i = 0; i < 4; i++)
    {
        if (info[i] == NULL)
        {
            return;
        }
    }
    FILE *fp[4] = {0};
    //打开保存通讯录信息的文件流，保存新的信息到文件
    fp[0] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/home.txt", "w");
    fp[1] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/work.txt", "w");
    fp[2] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/class.txt", "w");
    fp[3] = fopen("/home/xu/projects/project01-学生管理系统/c_project01_linklist/friends.txt", "w");
    for (int i = 0; i < 4; i++)
    {
        if (fp[i] == NULL)
        {
            printf("初始化失败\n");
            exit(1);
            return;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        /* 将链表的信息保存到各自的文件中 */
        list *tmp = info[i]->next;

        system("clear");
        while (tmp != NULL)
        {
            fprintf(fp[i], "%s %s %s %s\n", tmp->id, tmp->name, tmp->rel, tmp->tel);
            tmp = tmp->next;
        }
    }
    printf("所有更改保存成功！\n");
    getchar();
    printf("按回车键返回！\n");
    while (1)
    {
        if (getchar() == 10)
        {
            break;
        }
        sleep(2);
    }
    for (int i = 0; i < 4; i++)
    {
        fclose(fp[i]);
    }
}

//说明书
void Instructions()
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

//程序结束前，清空单链表
void AddressListClear(list **info)
{
    for (int i = 0; i < 4; i++)
    {
        if (info[i] == NULL)
        {
            return;
        }
        list *tmp = info[i];
        list *p = NULL;
        //将结点逐个释放，最后释放头结点并置空
        while (tmp->next != NULL)
        {
            p = tmp->next;
            tmp->next = tmp->next->next;
            free(p);
            p = NULL;
        }
        free(info[i]);
    }
}