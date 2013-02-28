      #include<stdio.h>
      int main()
      {
       int n,b,z,l,k;
     scanf("%d%d",&n,&b);
     for(l=0;l<n;l++)
      scanf("%d",&z);
      for(l=0;l<n;l++)
      for(k=0;k<b;k++)
     scanf("%d",&z);
      b=b/2; z=-1;
      printf("%d\n",b);
      for(l=0;l<b;l++)
      {
      z++;
       printf("%d\n",z);
        }
        return 0;
       } 