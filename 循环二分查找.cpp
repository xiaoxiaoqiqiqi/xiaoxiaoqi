#include<stdio.h>
#include<stdlib.h>
int binarysearch(int a[],int n,int x)
{				//�ҵ�xʱ���������������е�λ�ã����򷵻�-1 
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;//�����м�ֵ�����м�ֵ��Ҫ���ҵ���x�Ƚ�
		if(x==a[middle])//����˵���ҵ�Ԫ��
			return middle;
		if(x>a[middle])//x>middle��x��������Ұ�ߣ���֮������
			left=middle+1;//���¶��峤��
		else
			right=middle-1;
	}
	return -1;//�����������Ҳ�������-1
}
int main()
{
	int a[10]={1,3,4,6,7,8,10,13,14,16};//�����������
	int key=binarysearch(a,10,6);//����Ԫ�ظ������ҵ�ֵ��a���飬n=10,x=6Ϊ�����ҵ�ֵ 
	printf("�����ҵ�ֵ�������±�Ϊ%d\n",key);//keyΪ���պ�������ֵ 
}

