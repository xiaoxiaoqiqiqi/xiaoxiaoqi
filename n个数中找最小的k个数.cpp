#include <stdio.h>
#include <string>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
//ÿ�ν����黮��Ϊ�����֣���������������һ�������ҵ���kС��������ǰ�����������С��k����
void FindKLeastNums(int Data[],int lower,int upper,int Least_Size)
{
	if(Least_Size<lower||Least_Size>upper)
		return;//��С��������������С��󷵻�
	int i = lower;int j = upper + 1;int Tmp;
	while (1)
	{
		do 
		{
			i++;
		} while (i<upper && Data[i]<Data[lower]);//i<���ֵ������i<������Сֵ 
	    do 
	    {
			j--;
	    } while (Data[j]>Data[lower]);//����j>������Сֵ 
		if (i>j)
		  break;
		Tmp = Data[i];
		Data[i] = Data[j];
		Data[j] = Tmp;
	}
	Tmp = Data[lower];
	Data[lower] = Data[j];
	Data[j] = Tmp;
	if (j<Least_Size)//���������ֵ<���ҵ���С��ֵ���õ�һ�� 
	{
		FindKLeastNums(Data,j+1,upper,Least_Size);
	}
	else if (j>Least_Size)//��֮ 
	{
		FindKLeastNums(Data,lower,j-1,Least_Size);
	}
	return;
}
 
int main(void)
{
	int data[10] = {1,3,5,2,6,8,4,9,0,7};
	printf("   ԭ������Ԫ�أ�");
	int i = 0;
	while(i<10)
	{
		printf("%d ",data[i]);
		i++;
	}
	FindKLeastNums(data,0,9,3);
	printf("\n��������С��3����");
    for (i = 0;i<3;i++)
    {
		printf("%d ",data[i]);
    }
    return 0;
}

