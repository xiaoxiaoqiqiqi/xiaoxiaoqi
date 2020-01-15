#include <stdio.h>
int main()
{
	int g,i,k,s,a[10];//a[1]/a[2]a[3]+a[4]/a[5]a[6] = a[7]/a[8]a[9]
 	long m1,m2,m3;//m1 = a[2]a[3] = a[2]*10+a[3];  m2 = a[5]a[6] = a[5]*10+a[6];  m3 = a[8]a[9] = a[8]*10+a[9] 
	i=1;a[1]=1;s=0;
	while (1)
   	{
   		g=1;
    	for(k=i-1;k>=1;k--)
      	if(a[i]==a[k])
		{
		   g=0;break;
		}            // 两数相同,标记g=0  
    	if(i==9 && g==1 && a[1]<a[4])//等式左侧两分数交换次序只算一个解，为了避免重复，令a[1] < a[4]
     	{ 
		 	m1=a[2]*10+a[3];
			m2=a[5]*10+a[6];
			m3=a[8]*10+a[9];
       		if(a[1]*m2*m3+a[4]*m1*m3==a[7]*m1*m2)  // 判断等式  
         	{
			 	s++;printf("(-) ",s);
				printf("%d/%ld+%d/",a[1],m1,a[4]);
				printf("%ld=%d/%ld   ",m2,a[7],m3);
				if(s%2==0) printf("\n");

			}

		}

  		if(i< 9 && g==1) 
		{
			i++;a[i]=1;continue;
		}      // 不到9个数,往后继续 执行continue语句直接跳到while语句，则不在执行下面的语句   
  		while(a[i]==9 && i>1) 
			i--;    // 往上一步回溯  
  		if(a[i]==9 && i==1)
		   	break;
		else 
			a[i]++;                  // 至第1个数为9结束  
  	}
	printf("  共以上%d个解。\n",s);
}

