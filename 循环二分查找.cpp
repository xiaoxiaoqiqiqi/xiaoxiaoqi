#include<stdio.h>
#include<stdlib.h>
int binarysearch(int a[],int n,int x)
{				//找到x时返回其所在数组中的位置，否则返回-1 
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;//设置中间值，用中间值与要查找的数x比较
		if(x==a[middle])//等于说明找到元素
			return middle;
		if(x>a[middle])//x>middle，x在数组的右半边，反之在左半边
			left=middle+1;//重新定义长度
		else
			right=middle-1;
	}
	return -1;//不满足条件找不到返回-1
}
int main()
{
	int a[10]={1,3,4,6,7,8,10,13,14,16};//定义查找数组
	int key=binarysearch(a,10,6);//定义元素个数查找的值，a数组，n=10,x=6为所查找的值 
	printf("所查找的值的数组下标为%d\n",key);//key为接收函数返回值 
}

