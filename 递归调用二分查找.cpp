#include<stdio.h>
#include<stdlib.h>
int BinarySerach(int *a, int x, int left, int right)//�ݹ�ʵ�ֶ��ֲ��� 
{
	while (left <= right)//���ֲ��������Ѿ��ź���������ʵ�� 
 
	{
		int mid = (left+ right ) / 2 ;//ȡ�м�ֵ 
		if (a[mid] == x)//�м�ֵ����Ҫ���ҵ�ֵ�����м�ֵ 
			return mid;
		if (a[mid] > x)//�м�ֵ����Ҫ���ҵ�ֵʱ ��Ҫ���ҵ�ֵ����ߣ��м�ֵ-1��Ϊ�µ����ұߵ�ֵ 
		{
			return BinarySerach(a, x, left, mid - 1);//�ݹ���õ�һ�� 
		}
		else
		{
			return BinarySerach(a, x, mid + 1, right);//�м�ֵС��Ҫ���ҵ�ֵʱִ�и���� 
		}
	}
	return -1;//�����������Ҳ���ʱ����-1 
}
int main()
{
	int a[10] = {1,3,4,6,7,8,10,13,14,16 };
	int sz = sizeof(a) / sizeof(a[0]);//����a�Ĵ�С/����a�е�0��Ԫ�صĴ�С��int��ֵ��size_t����ת��int����
	int key=BinarySerach(a, 6, 0, sz);
	printf("���ҵ�Ԫ�������±�Ϊ%d\n", key);
	return 0;	
}

