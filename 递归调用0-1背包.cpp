#include <iostream>
#include<cstdio>
using namespace std;
#define N 100
struct goods{
int sign;//物品序号
int wight;//物品重量
int value;//物品价值
};

int n,bestValue,cv,cw,C;//物品数量，价值最大，当前价值，当前重量，背包容量
int X[N],cx[N];//最终存储状态，当前存储状态
struct goods goods[N];

int Force(int i){
if(i>n-1){//第i件物品 
    if(bestValue < cv && cw + goods[i].wight <= C){
        for(int k=0;k<n;k++)
            X[k] = cx[k];//存储最优路径
        bestValue = cv;
    }
    return bestValue;
}
cw = cw + goods[i].wight;
cv = cv + goods[i].value;
cx[i] = 1;//装入背包
Force(i+1);
cw = cw-goods[i].wight;
cv = cv-goods[i].value;
cx[i] = 0;//不装入背包
Force(i+1);
return bestValue;
}

int main()
{
    printf("物品种类n：");
    scanf("%d",&n);
    printf("背包容量C：");
    scanf("%d",&C);
    for(int i=0;i<n;i++){
        printf("物品%d的重量w[%d]及其价值v[%d]：",i+1,i+1,i+1);
        scanf("%d%d",&goods[i].wight,&goods[i].value);
    }
    int sum1 = Force(0);
    printf("蛮力法求解0/1背包问题：\nX=[");
    for(int i=0;i<n;i++){
        printf("X[i]");//最终存储 
        }
        printf("] 装入总价值%d\n",sum1);
    return 0;
}


