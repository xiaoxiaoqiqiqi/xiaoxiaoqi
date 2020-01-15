#include<stdio.h>
#include<stdlib.h>
int BinarySerach(int *a, int x, int left, int right)//递归实现二分查找 
{
	while (left <= right)//二分查找是在已经排好序的情况下实现 
 
	{
		int mid = (left+ right ) / 2 ;//取中间值 
		if (a[mid] == x)//中间值等于要查找的值返回中间值 
			return mid;
		if (a[mid] > x)//中间值大于要查找的值时 ，要查找的值在左边，中间值-1作为新的最右边的值 
		{
			return BinarySerach(a, x, left, mid - 1);//递归调用第一步 
		}
		else
		{
			return BinarySerach(a, x, mid + 1, right);//中间值小于要查找的值时执行该语句 
		}
	}
	return -1;//不满足条件找不到时返回-1 
}
int main()
{
	int a[10] = {1,3,4,6,7,8,10,13,14,16 };
	int sz = sizeof(a) / sizeof(a[0]);//数组a的大小/数组a中第0个元素的大小，int将值由size_t类型转成int类型
	int key=BinarySerach(a, 6, 0, sz);
	printf("查找的元素数组下标为%d\n", key);
	return 0;	
}

