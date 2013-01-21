/* 
 * File:   poker.c
 * Author: Administrator
 *
 * Created on February 28, 2009, 3:05 AM
 */

#include <stdio.h>
#include <stdlib.h>
int find(char);
int mapsuit(char);
int nothigh(int [],int []);
void sort(int []);
/*
 * 
 */
int main(int argc, char** argv) {
int n,val=0,i,j,card[5],suit[5];
char cards[5][3];
fscanf(stdin,"%d",&n);
for(i=0;i<n;i++)
 {
val=0;
for(j=0;j<5;j++)
 fscanf(stdin,"%s",cards[j]);
for(j=0;j<5;j++)
  {
card[j]=find(cards[j][0]);
suit[j]=mapsuit(cards[j][1]);
  }
  val+=nothigh(card,suit);
 if(val&0x100)
 {
   if(i!=n-1)
   fprintf(stdout,"royal flush\n");
   else
   fprintf(stdout,"royal flush");
   }
 else if((val&0x20)&& (val&0x10))
 {
 if(i!=n-1)
   fprintf(stdout,"straight flush\n");
   else

   fprintf(stdout,"straight flush");
   }
 else if(val&0x40)
 {
 if(i!=n-1)
  fprintf(stdout,"four of a kind\n");
   else

   fprintf(stdout,"four of a kind");
   }
 else if((val&0x08) && (val&0x02))
 {
 if(i!=n-1)
   fprintf(stdout,"full house\n");
   else

   fprintf(stdout,"full house");
   }
 else if(val&0x20)
 {
 if(i!=n-1)
  fprintf(stdout,"flush\n");
   else

  fprintf(stdout,"flush");
  }
  else if(val&0x10)
  {
  if(i!=n-1)
   fprintf(stdout,"straight\n");
   else

   fprintf(stdout,"straight");
   }
  else if(val&0x08)
  {
  if(i!=n-1)
  fprintf(stdout,"three of a kind\n");
   else

  fprintf(stdout,"three of a kind");
  }
  else if(val&0x04)
  {
  if(i!=n-1)
   fprintf(stdout,"two pairs\n");
   else
   fprintf(stdout,"two pairs");
   }
   else if(val&0x02)
   {
   if(i!=n-1)
   fprintf(stdout,"pair\n");
   else

   fprintf(stdout,"pair");
   }
   else
   {
   if(i!=n-1)
 fprintf(stdout,"high card\n");
   else
 fprintf(stdout,"high card");
   }
  }
    return (EXIT_SUCCESS);
}
int nothigh(int card[5],int suit[5])
{
int pair=0,three=0,four=0,strait,cnt,i,val=0,flag=1,sum=0,flag1=0;
sort(card);
cnt=1;
for(i=1;i<5;i++)  {
      if(suit[i]!=suit[i-1]){
      flag=0;
      break;
      }
      }
      if(flag)
	val=32;
for(i=1;i<5;i++)  {
 if(card[i]==card[i-1])
  cnt++;
 if(card[i]!=card[i-1])
 {
 if(cnt==2){cnt=1;pair++;}
 if(cnt==3){cnt=1;three++;}
 if(cnt==4){cnt=1;four++;}
 }
 }
 if(cnt==2){cnt=1;pair++;}
 if(cnt==3){cnt=1;three++;}
 if(cnt==4){cnt=1;four++;}

 val+=2*pair+8*three+64*four;
 sum=card[0]*20+card[1]*2+card[2]*2+card[3]*2+card[4]*2;
 if(sum!=112)
 {
  flag=1;
  for(i=1;i<5;i++)
   {
    if(card[i]!=card[i-1]+1){
      flag=0;break;}
   }
   if(flag)
   val+=16;
  }
  else
  {
  if(!!(val&0x20))
   val+=256;
  else{
      flag1=13;
      flag=1;
      for(i=4;i>=1;i++)
      {
          if(card[i]!=flag1)
          {
              flag=0;
              break;
          }
          flag1--;
      }
      if(flag)
        val+=16;
  }
   }
 return val;
}
void sort(int card[5])
{
int i,j;
for(i=0;i<5;i++)
{
for(j=i+1;j<5;j++)
{
if(card[i]>card[j])
{
card[i]=card[i]+card[j];
card[j]=card[i]-card[j];
card[i]=card[i]-card[j];
}
}
}
}
int find(char card)
{
char denom[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int i;
for(i=0;i<13;i++)
  {
if(denom[i]==card)
  return (i+1);
  }
}
int mapsuit(char suit)
{
if(suit=='S')
 return 1;
if (suit=='D')
 return 2;
if(suit=='H')
 return 3;
if(suit=='C')
 return 4;
}
