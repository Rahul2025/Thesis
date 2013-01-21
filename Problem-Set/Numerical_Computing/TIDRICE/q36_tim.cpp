#include<stdio.h>
#include<stdlib.h>

using namespace std;

int strcmp (const char * s1, const char * s2);

int main()
{
 int n,i,j,sum,t;

 typedef char voter[21];

 scanf("%d",&t);

 while(t--)
 {
 	scanf("%d",&n);

 	voter str[n];
 	char *ch = new char[n];
 	int *r = new int[n];
 
 	sum = 0;

	for(i=0;i<n;i++)
 	{
		scanf("%s",&str[i]);
		scanf("%s",&ch[i]);
		r[i] = 1;
 	}

 	for(i=n-1;i>=0;i--)
 	{
		if(r[i]!=0)
		{
			
			for(j=0;j<i;j++)
			{
				if(strcmp(str[i],str[j])==0)
				{
						r[j] = 0;
				}
		
			}
		
			if(ch[i]=='+')
				sum+=1;
			else
				sum-=1;	
		
		}
			
 	}

 	printf("%d\n",sum);
 }

}

int strcmp (const char * s1, const char * s2)
{
    for(; *s1 == *s2; ++s1, ++s2)
        if(*s1 == 0)
            return 0;
    return *(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1;
}
