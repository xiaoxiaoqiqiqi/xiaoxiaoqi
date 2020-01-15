#include<stdio.h>
void quick_sort(int a[], int p, int r) {
	if (p< r ){
		int s = a[p];//基准 
		int i = p;//左边 
		int j = r;//右边 
 
		//刚开始排序一定得从右向左查找
		while (i < j) {
 
			//从右向左查找第一个小于s的值与a[0]交换
			while (i < j && a[j] >= s)
				j--;
			if (i<j) 
				a[i++] = a[j];//把a[j]的值给a[i]，并让i向后走一位
 
			//从左向右查找第一个大于等于s的值与a[0]交换
			while (i < j && a[i] < s)
				i++;
			if (i < j) {
				a[j--] = a[i];//把a[i]的值给此时s所在的地址，并让j向前退一位
			}
		}
		a[i] = s;//因为在之前的交换值过程中a[i]的值已经不是最初的值，所以要变回来 
		quick_sort(a, p, i - 1);//排序枢轴前数列 
		quick_sort(a, i + 1, r);//排序枢轴后数列 
	}
}
 
void put(int a[],int length) {
	for (int i = 0; i < length; i++) {
		printf("%d",a[i]);
	}
}
 
int main() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	printf("排序前：");
	put(a, 10);
	quick_sort(a, 0, 9);
	printf("\n");
	printf("排序后：");
	put(a, 10);
	return 0;
}

