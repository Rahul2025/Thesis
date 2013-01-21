#include<iostream>
using namespace std;
int main()
{
 
    int test;
    scanf("%d",&test);
    do
    {   
        long num;
        scanf("%ld",&num);
        if((num-1)%4 ==0)
           printf("ALICE\n");
        else
            printf("BOB\n");
            
        
        test--;
        
        
    }while(test);
    
    return 0;
}