#include <iostream>
#include<cstdio>
using namespace std;
#define N 100
struct goods{
int sign;//��Ʒ���
int wight;//��Ʒ����
int value;//��Ʒ��ֵ
};

int n,bestValue,cv,cw,C;//��Ʒ��������ֵ��󣬵�ǰ��ֵ����ǰ��������������
int X[N],cx[N];//���մ洢״̬����ǰ�洢״̬
struct goods goods[N];

int Force(int i){
if(i>n-1){//��i����Ʒ 
    if(bestValue < cv && cw + goods[i].wight <= C){
        for(int k=0;k<n;k++)
            X[k] = cx[k];//�洢����·��
        bestValue = cv;
    }
    return bestValue;
}
cw = cw + goods[i].wight;
cv = cv + goods[i].value;
cx[i] = 1;//װ�뱳��
Force(i+1);
cw = cw-goods[i].wight;
cv = cv-goods[i].value;
cx[i] = 0;//��װ�뱳��
Force(i+1);
return bestValue;
}

int main()
{
    printf("��Ʒ����n��");
    scanf("%d",&n);
    printf("��������C��");
    scanf("%d",&C);
    for(int i=0;i<n;i++){
        printf("��Ʒ%d������w[%d]�����ֵv[%d]��",i+1,i+1,i+1);
        scanf("%d%d",&goods[i].wight,&goods[i].value);
    }
    int sum1 = Force(0);
    printf("���������0/1�������⣺\nX=[");
    for(int i=0;i<n;i++){
        printf("X[i]");//���մ洢 
        }
        printf("] װ���ܼ�ֵ%d\n",sum1);
    return 0;
}


