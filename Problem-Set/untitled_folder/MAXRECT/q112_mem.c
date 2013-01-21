#include<stdio.h>
int b[302][302];
main()
{
      int h,w,sum=0,x,y,p=0,t,c=0,i,j;
      scanf("%d %d",&h,&w);
      for(i=0;i<h;i++)
      {
                      for(j=0;j<w;j++)
                      {
                                      scanf("%d",&b[i][j]);
                      }
      }
      for(i=0;i<h;i++)
      {
                      for(j=0;j<w;j++)
                      {
                                      if(b[i][j]>=0){
                                       printf("%d %d\n",1,1);
                                       printf("%d\n",i);
                                       printf("%d ",j); 
                                       p=1;
                                       break;           
                                      }
                      }
                      if(p==1)
                      break;
      }
      return 0;
}
                                                   
                                      