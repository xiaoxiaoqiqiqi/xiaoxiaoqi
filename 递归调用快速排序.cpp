#include<stdio.h>
void quick_sort(int a[], int p, int r) {
	if (p< r ){
		int s = a[p];//��׼ 
		int i = p;//��� 
		int j = r;//�ұ� 
 
		//�տ�ʼ����һ���ô����������
		while (i < j) {
 
			//����������ҵ�һ��С��s��ֵ��a[0]����
			while (i < j && a[j] >= s)
				j--;
			if (i<j) 
				a[i++] = a[j];//��a[j]��ֵ��a[i]������i�����һλ
 
			//�������Ҳ��ҵ�һ�����ڵ���s��ֵ��a[0]����
			while (i < j && a[i] < s)
				i++;
			if (i < j) {
				a[j--] = a[i];//��a[i]��ֵ����ʱs���ڵĵ�ַ������j��ǰ��һλ
			}
		}
		a[i] = s;//��Ϊ��֮ǰ�Ľ���ֵ������a[i]��ֵ�Ѿ����������ֵ������Ҫ����� 
		quick_sort(a, p, i - 1);//��������ǰ���� 
		quick_sort(a, i + 1, r);//������������� 
	}
}
 
void put(int a[],int length) {
	for (int i = 0; i < length; i++) {
		printf("%d",a[i]);
	}
}
 
int main() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	printf("����ǰ��");
	put(a, 10);
	quick_sort(a, 0, 9);
	printf("\n");
	printf("�����");
	put(a, 10);
	return 0;
}

