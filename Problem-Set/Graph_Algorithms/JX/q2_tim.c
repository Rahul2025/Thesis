#include<stdio.h>
//#include<conio.h> 
int main()
{
    int testcases,i,n,D,S,bs,max,l,no,j,ind,k=0,p,q,bsO,ans=0;
    char mat[500][500];
    int my_dan[500]={0},brdm[500];
    short int ss[500]={0};
    //FILE *fr,*fw ;
    //fw=fopen("Palinromef1.txt","w");
    //fr=fopen("PalinromeRangef1.txt","w");
    scanf("%d %d",&D,&S);
    //printf("Enter the number:");
    i=0;
    for(;i<D;i++)
    {
              scanf("%d",&brdm[i]);
    }
//    printf("\nbrdm");
              
    for(i=0;i<D;i++)
    {
                    for(j=0;j<S;j++)
                    {
                                    scanf(" %c",&mat[i][j]);
  //                                  printf("%c \n",mat[i][j]);
                                    //printf("\nHa");
                                    if(mat[i][j]=='1')
                                                      my_dan[j]+=1;
                    }
    }
   for(p=0;p!=S;p++){
    bs=0;                                
    for(j=1;j<S;j++)
     if(*(my_dan+bs)<my_dan[j])
          bs=j;
    ss[bs]=1;
    ans++;
    my_dan[bs]=0;
    no=0;
    if(!p)
     bsO=bs;
    for(q=0;q<D;q++)
        if(mat[q][bs]==0&&mat[q][bsO]==1)
           brdm[q]--;
    for(i=0;i<S;i++)
    {
                    if(mat[i][bsO]==1)
                    {
                                     if(brdm[i]==1)
                                     {
                                                   no++;
                                                   ind=i;
                                     }
                    }
    }
         for(;k<S&&no==1;k++)
          if(mat[ind][k]==1&&ss[k]==0)
          {
                 p++;
                 ss[k]=1;
                 ans++;
                 for(q=0;q<D;q++)
                   if(mat[q][k]==0&&mat[q][bsO]==1)
                     brdm[q]--;
                     
                 no=0;    
                 for(i=0;i<S;i++)
                 {
                    if(mat[i][bsO]==1)
                    {
                                     if(brdm[i]==1)
                                     {
                                                   no++;
                                     }
                    }
                 }    
          }
          if(k>0)
           break;
    else if(no>1)
     break;
   // for(i=0;i<S;i++)
     // printf("######i=%d#######ss[i]=%d##############\n",i,ss[i]);
}
ans=0;
   //printf("%d\n",ans);
   for(i=0;i<S;i++)  
    if(ss[i]==1)                 
    {// printf("%d\n",i);
    ans++;
    }
    printf("%d\n",ans);
   for(i=0;i<S;i++)  
    if(ss[i]==1)                 
     printf("%d\n",i);
   
    
   
  // getch();
   return 0;
}           
    
 