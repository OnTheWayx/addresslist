#include "addresslist.h"

int main(int argc, char const *argv[])
{
    int choice;

    /* 家人 同事  同学  朋友 信息存放在各自的链表 */
    list *home = AddressListCreate();
    list *work = AddressListCreate();
    list *class = AddressListCreate();
    list *friends = AddressListCreate();

    /* 保存每个链表头指针 */
    list *info[4] = {home, work, class, friends};
    
    /* 读入文件信息 */
    AddressListInit(info);
    while (1)
    {
        menu();
        printf("input>>>");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            /* 更新通讯录信息 */
            AddressListUpdate(info);
            break;
        case 2:
            /* 删除通讯录信息 */
            AddressListDelete(info);
            break;
        case 3:
            /* 浏览通讯录信息 */
            AddressListPrint(info);
            break;
        case 4:
            /* 添加通讯录信息 */
            AddressListInsert(info);
            break;
        case 5:
            /* 保存修改的通讯录信息到文件中 */
            SaveInformation(info);
            break;
        case 6:
            /* 打印说明书 */
            Instructions();
            break;
        case 7:
            /* 回收申请的空间并退出系统 */
            AddressListClear(info);
            exit(0);
            break;
        default:
            system("clear");
            printf("输入有误，请重新输入！\n");
            getchar();
            sleep(1);
            break;
        }
    }

    return 0;
}
