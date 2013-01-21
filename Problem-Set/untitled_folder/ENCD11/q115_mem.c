#include<stdio.h>
#include<malloc.h>
/*int main()
{
	int N=1,temp;
	int bits[32],i,j;
	long long Mincount,k,tcount=0,count=0;
	int Nocount,first1,nozero=0;
//	for(i=0;i<32;i++)
	{
//		bits[i]=0;
	}
	//printf("Enter the input \n");
	scanf("%d",&N);
	do
	{
		//printf("%d\n",N);
		if(N==0)
			break;
//		temp=N;
	
		Mincount=1;
		Mincount=Mincount<<N;


		for(k=1;k<Mincount;k++)
		{
			temp=k;
			first1=0;
			count=0;
			i=0;
			while(temp!=0)	
			{
				int biti;

				biti=temp & 1;
//				bits[i]=biti;
				temp=temp >> 1;
				if(first1==0 && biti==1)
				{
					first1=1;
					count=1;
					nozero=0;
				}
				if(biti==0)
				{
					nozero++;
				}	
				if(biti==1)
				{
					count=count*(nozero+1);
					nozero=0;
				}	
				i++;
				//printf("%d ",biti);
			}
//			for(j=i-1;j>=0;j--)
			{
//				printf("%d ",bits[j]);	
			}
//			printf("\t%lld \n",count);
			tcount=tcount+count;
			//printf("\nThe number of combination %d \n",count);
		}
		printf("%lld\n",tcount);
		tcount=0;
		scanf("%d",&N);
	}while(N!=0);

	return 0;
}*/

int main()
{
	int N,i;
	unsigned long long A,B,prevA,prevB;
	scanf("%d",&N);
	do{
		if(N==0)
			break;
		if(N>0)
		{
			//A=0;
			//B=1;
			prevA=0;
			prevB=1;
			A=0;
			B=1;
		}
		for(i=1;i<N;i++)
		{
			A=prevA+prevB;
			B=2*prevB+prevA;
			prevA=A;
			prevB=B;
		}		
		printf("%lld\n",A+B);
		
	
		scanf("%d",&N);
	}while(N!=0);
	return 0;
}
