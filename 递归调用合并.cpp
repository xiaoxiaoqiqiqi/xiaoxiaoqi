#include <stdio.h>
#include <stdlib.h>
 
/***�ݹ鷽��ʵ�ֹ鲢����****/
//�������ܣ��������������һ�������
//�ϲ�
void merge( int array[] , int left , int middle , int right )//array[]�ϲ��������� 
{
    int left_len = middle - left;
    int right_len = right - middle - 1;
    int left_array[left_len];
    int right_array[right_len];
    int i,j,k;
 
    //����ժ��������������
    for( i = 0 ; i <= left_len ; i++ )
        left_array[i] = array[i+left];
 
    for( j = 0 ; j <= right_len ; j++)
        right_array[j] = array[j+middle+1];
 
    //�������������б��һ����������
    //ע�⣺��Ϊ�����������һֱ�Ƕ�array����ĵݹ飬���������ʼ�����Ƕ�array������У�
    //array����Ԫ�ص�λ�ñ仯����������array����������ñ�ı�������!!!
    k = left;
    i = 0;j = 0;
    while( i <= left_len && j <= right_len )
    {
        if( left_array[i] < right_array[j] )
            array[k++] = left_array[i++];//i<j���µ��������i��k����λ�� 
        else
            array[k++] = right_array[j++];//��֮j��k���� 
    }
    while( i <= left_len )
        array[k++] = left_array[i++];
    while( j <= right_len )
        array[k++] = right_array[j++];
}
 
//merge_sort()�������ٺϲ�
void merge_sort( int array[] , int left , int right )
{
    int middle;
    if( left < right )
    {
        middle = ( left + right ) / 2;
        // �ֽ� + ���
        merge_sort( array , left , middle );
        merge_sort( array , middle+1 , right );
        // �ϲ�
        merge( array , left , middle , right );
    }
}

int main()
{
    int *array;
    int i,array_size;
    printf("����������Ԫ�صĸ���:");
    scanf("%d",&array_size);
 
    array = (int*)malloc(sizeof(int));
    printf("������ %d ��Ԫ��",array_size);
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);
 
    merge_sort( array , 0 , array_size-1 );
    printf("���鲢���������Ԫ��˳�����Ϊ��");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}

