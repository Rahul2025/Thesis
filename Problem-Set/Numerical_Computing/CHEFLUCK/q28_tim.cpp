#include<iostream.h>
int main()
{int t;
 scanf("%d",&t);
 while(t--)
{ int a;
 scanf("%d",&a);
 while(a%7)
{ if(a<0)
 {    a=-1;
        break;}

 a=a-4;
}
 printf("%d\n",a);
}
system ("pause");
return 0;
}
