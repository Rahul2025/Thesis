#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int gdc(int M,int N)
{
    int rem;
    while(N>0)
    {
        rem = M%N;
        M = N;
        N = rem;
    }
    return M;
}

int main()
{
    int num;
    int number1,digit2,tem,prevTem,result;
    char number2[251];
    scanf("%d",&num);
    while(num>0)
    {
        scanf("%d",&number1);
        digit2=0;
        prevTem=0;

        scanf("%s",number2);
        digit2 = int(strlen(number2));
        int i=0;
        if(number1==0)
            printf("%s\n",number2);
        else
        {
            for(i=0;i<digit2;i++)
            {
                tem = prevTem*10 + int(number2[i]) - 48 ;
                prevTem = tem%number1;

            }

            result = gdc(number1,prevTem);
            printf("%d\n",result);
        }
        num--;
    }
    return 0;
}
