#include "addresslist.h"

int main(int argc, char const *argv[])
{
    int choice;

    init();
    while (1)
    {
        menu();
        printf("请输入您的选择：");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            updateInfor();
            break;
        case 2:
            delInfor();
            break;
        case 3:
            scanInfor();
            break;
        case 4:
            addInfor();
            break;
        case 5:
            retrieveInfor();
            break;
        case 6:
            saveInfor();
            break;
        case 7:
            instructions();
            break;
        case 8:
            exit(0);
            break;
        default:
            system("clear");
            printf("输入有误，请重新输入！\n");
            sleep(2);
            break;
        }    
    }

    return 0;
}
