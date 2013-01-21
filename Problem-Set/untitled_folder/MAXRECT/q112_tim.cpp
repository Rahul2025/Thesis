 #include <iostream>
 #include<cstdio>

 using namespace std;
 int main()
 {     int h,w,max=0;
       cin>>h>>w;
       int a[h][w];

       int rmax,cmax;
       long long sum=0;
       long long rowcount[h];
       long long colcount[w];

       for(int i=0;i<h;i++)
           rowcount[i]=0;
       for(int i=0;i<w;i++)
           colcount[i]=0;

       for(int i=0;i<h;i++)
         {      for(int j=0;j<w;j++)
                     {
                         scanf("%d",&a[i][j]);
                         sum+=a[i][j];

                         if(a[i][j]>max)
                              {
                                   rmax=i;
                                   cmax=j;
                                   max=a[i][j];
                              }

                              colcount[j]+=a[i][j];
                              rowcount[i]+=a[i][j];
                     }
         }

         int cpy=0;
         int rowchosen[h],colchosen[w];
         int xx=0,yy=0;


         for(int i=0;i<h;i++)
           {         if(rowcount[i]>0)
                       {
                            rowchosen[xx++]=i;
                       }
           }

         for(int j=0;j<w;j++)
           {
                if(colcount[j]>0)
                  {
                      colchosen[yy++]=j;

                  }
           }


        if(xx==0||yy==0)
         {
              cout<<1<<" "<<1<<endl;
              cout<<rmax<<endl;
              cout<<cmax<<endl;
         }

         else
         {
             cout<<xx<<" "<<yy<<endl;
             for(int i=0;i<xx;i++)
                   {
                       cout<<rowchosen[i]<<" ";
                   }
             cout<<endl;

             for(int i=0;i<yy;i++)
                  {
                       cout<<colchosen[i]<<" ";
                  }
            cout<<endl;
         }

         return 0;
}