#include<stdio.h>
#include<string.h>

int main()
	{
		int a,b,arr[10],brr[10],crr[11],count;
		scanf("%d%d",&a,&b);
		int i,j;
		int a_digit,b_digit;
		int temp1,temp2;
		while( !(a==0 && b==0) )
			{	
				//memset(arr,0,sizeof(a));
				//memset(brr,0,sizeof(a));
				count=0;
				j=1;
				for(i=0;i<10;i++)
					{
						temp1=(a%(j*10));
						temp2=(a%(j));
						arr[i]=(temp1-temp2)/j;
						//arr[i]=((a%j)-(a%(j/10)))(j/10);
						//brr[i]=((b%j)-(b%(j/10)))(j/10);
						temp1=(b%(j*10));
						temp2=(b%(j));
						brr[i]=(temp1-temp2)/j;					
						crr[i]=0;
						j*=10;
					}
				crr[10]=0;
				for(i=0;i<10;i++)
					{
						if((arr[i]+brr[i]+crr[i])>= 10 )
						{
							count++;
							crr[i+1]++;
						}
					}
				
				if(count==0)
					printf("No carry operation.\n");
				else if(count == 1)
					printf("1 carry operation.");
				else 
					printf("%d carry operations.\n",count);

				scanf("%d%d",&a,&b);
			}
		return 0;
	}