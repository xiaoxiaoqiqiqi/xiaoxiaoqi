#include <stdio.h>
#include <stdlib.h>
 
/***递归方法实现归并排序****/
//函数功能：将两个有序表变成一个有序表
//合并
void merge( int array[] , int left , int middle , int right )//array[]合并后的有序表 
{
    int left_len = middle - left;
    int right_len = right - middle - 1;
    int left_array[left_len];
    int right_array[right_len];
    int i,j,k;
 
    //单独摘出两个有序序列
    for( i = 0 ; i <= left_len ; i++ )
        left_array[i] = array[i+left];
 
    for( j = 0 ; j <= right_len ; j++)
        right_array[j] = array[j+middle+1];
 
    //将两个有序序列变成一个有序序列
    //注意：因为后面的排序函数一直是对array数组的递归，因此排序至始至终是对array数组进行，
    //array数组元素的位置变化必须体现在array数组里，不能用别的变量代替!!!
    k = left;
    i = 0;j = 0;
    while( i <= left_len && j <= right_len )
    {
        if( left_array[i] < right_array[j] )
            array[k++] = left_array[i++];//i<j在新的有序表中i跟k交换位置 
        else
            array[k++] = right_array[j++];//反之j跟k交换 
    }
    while( i <= left_len )
        array[k++] = left_array[i++];
    while( j <= right_len )
        array[k++] = right_array[j++];
}
 
//merge_sort()先排序，再合并
void merge_sort( int array[] , int left , int right )
{
    int middle;
    if( left < right )
    {
        middle = ( left + right ) / 2;
        // 分解 + 解决
        merge_sort( array , left , middle );
        merge_sort( array , middle+1 , right );
        // 合并
        merge( array , left , middle , right );
    }
}

int main()
{
    int *array;
    int i,array_size;
    printf("请输入数组元素的个数:");
    scanf("%d",&array_size);
 
    array = (int*)malloc(sizeof(int));
    printf("请输入 %d 个元素",array_size);
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);
 
    merge_sort( array , 0 , array_size-1 );
    printf("经归并排序后，数组元素顺序输出为：");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}

