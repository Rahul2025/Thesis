#include <stdio.h>
#include <malloc.h>
int digit(int n)
{
    int count = 0;
    while(n != 0)
    {
            n = n/10;
            count++;
    }
    return count;
}
int sum(int n)
{
    int total = 0;
    while(n !=0)
    {
            total+= n%10;
            n = n/10;
    }
    return total;
}
int main()
{
    int total, n, i, j;
    scanf("%d", &total);
    int* result = (int *)calloc(sizeof(int),total);
    for(j=0;j<total;j++) 
    {
             scanf("%d", &n);
             int max = 9 * digit(n);
             for(i = n-max; i < n;i++)
             {
                   if((sum(i)+i) == n)
                   {
                          *(result+j) = i;
                          break;
                   }
             }
    }
    for(j=0;j<total;j++)
    {if(result[j]) printf("%d\n", result[j]);else printf("NONE\n");}
    return 0;
}
  