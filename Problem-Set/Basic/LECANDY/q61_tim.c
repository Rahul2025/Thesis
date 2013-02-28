  #include<stdio.h>
  #include<stdlib.h>
 // #include<config.h>
    inline int inp( )
    {
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
    }
    int main()
    {
    int t=inp(),n,c,a,i;
    while(t--)
    {
    n=inp();
    c=inp();
    for(;n--;c-=inp());
    (c<0)?printf("No\n"):printf("Yes\n");
    }
  //  system("Pause");
    return 0;
    }  