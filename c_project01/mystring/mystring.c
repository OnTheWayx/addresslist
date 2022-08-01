#include <stddef.h>
int _strlen(char *str)  //计算字符串长度
{
    int length = 0;

    while (*(str + length) != 0)
    {
        length++;
    }

    return length;
}

int _strcmp(char *str1, char *str2)  //比较字符串大小
{
    while (*str1 != 0 && *str2 != 0)
    {
        if (*str1 > *str2)
        {
            return 1;
        }
        else if (*str1 < *str2)
        {
            return -1;
        }
        str1++;
        str2++;
    }
    if (*str1 != 0)
    {
        return 1;
    }
    else if (*str2 != 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

int _strncmp(char *str1, char *str2, int str2_length)  //字符串2的前n字符与字符串1比较
{
    int i = 0;

    while (i < str2_length)
    {
        if (*(str1 + i) > *(str2 + i))
        {
            return 1;
        }
        else if (*(str1 + i) < *(str2 + i))
        {
            return -1;
        }
        i++;
    }

    return 0;
}

char *_strcpy(char *str1, char *str2) //复制字符串2到字符串1
{
    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';

    return str1;
}

char *_strncpy(char *str1, char *str2, int n)  //字符串2的前n字符赋予字符串1
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    for (i = 0; i < n && *(str2) != '\0'; i++)
    {
        str1[i] = str2[i];
    }
    for ( ; i < n; i++)
    {
        str1[i] = '\0';
    }

    return str1;
}

char *_strcat(char *str1, char *str2) //字符串2拼接到字符串1尾部 
{
    char *temp = str1;

    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    while (*temp != '\0')
    {
        temp++;
    }
    while (*str2 != '\0')
    {
        *temp = *str2;
        temp++;
        str2++;
    }
    *temp = '\0';

    return str1;
}

char *_strncat(char *str1, char *str2, int n)
{
    char *temp = str1;

    int i;

    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    while (*temp != '\0')
    {
        temp++;
    }
    for (i = 0; i < n && *str2 != '\0'; i++)
    {
        *temp = *str2;
        temp++;
        str2++;
    }
    *temp = '\0';

    return str1;    
}