#define _CRT_SECURE_NO_WARNINGS 1

//排序sort

#include<stdio.h>

void swap(char* x, char* y, int width)
{
    int i = 0;
    for (i = 0; i < width; i++)
    {
        char tem = *x;
        *x = *y;
        *y = tem;
        x++;
        y++;
    }
}

void sort(void* base,
    int sz,
    int width,
    int(*cmp)(const void* e1, const void* e2))
{
    int i = 0;
    //冒泡的趟数
    for (i = 0; i < sz - 1; i++)
    {
        //遍历
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            //交换
            if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
            {
                //以一字节为单位交换
                swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
            }
        }
    }
}

int test(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
void print(int* arr, int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = { 9,2,4,6,7,3,0,8 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    sort(arr, sz, sizeof(arr[0]), test);
    print(arr, sz);
    return 0;
}