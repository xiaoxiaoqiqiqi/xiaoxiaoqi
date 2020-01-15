#include <stdio.h>
#include <string>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
//每次将数组划分为两部分，再在满足条件的一部分里找到第k小的数，它前面的数就是最小的k个数
void FindKLeastNums(int Data[],int lower,int upper,int Least_Size)
{
	if(Least_Size<lower||Least_Size>upper)
		return;//最小的数比所给的数小或大返回
	int i = lower;int j = upper + 1;int Tmp;
	while (1)
	{
		do 
		{
			i++;
		} while (i<upper && Data[i]<Data[lower]);//i<最大值与数组i<数组最小值 
	    do 
	    {
			j--;
	    } while (Data[j]>Data[lower]);//数组j>数组最小值 
		if (i>j)
		  break;
		Tmp = Data[i];
		Data[i] = Data[j];
		Data[j] = Tmp;
	}
	Tmp = Data[lower];
	Data[lower] = Data[j];
	Data[j] = Tmp;
	if (j<Least_Size)//所给的最大值<查找的最小的值调用第一步 
	{
		FindKLeastNums(Data,j+1,upper,Least_Size);
	}
	else if (j>Least_Size)//反之 
	{
		FindKLeastNums(Data,lower,j-1,Least_Size);
	}
	return;
}
 
int main(void)
{
	int data[10] = {1,3,5,2,6,8,4,9,0,7};
	printf("   原数组中元素：");
	int i = 0;
	while(i<10)
	{
		printf("%d ",data[i]);
		i++;
	}
	FindKLeastNums(data,0,9,3);
	printf("\n调整后最小的3个：");
    for (i = 0;i<3;i++)
    {
		printf("%d ",data[i]);
    }
    return 0;
}

