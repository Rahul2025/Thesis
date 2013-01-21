#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int board[1000][1000];
int N, Kr, Kc, maxM;
char row[1000];

int main() 
{
    int testCases;
	scanf("%d", &testCases);
  
    for (int i=0; i<testCases; i++) 
    {
        scanf("%d", &N);
        for (int j=0; j<N; j++)
        {
            scanf ("%s",row);
            for (int k=0; k<N; k++)
            {
                if (row[k]=='K') {
                    Kc = k;
                    Kr = j;
                }
                board[j][k]=(row[k]=='P');
            }
         }
         
         for (int j=0; j<N; j++)
         {
             maxM=0;
             if (j>=2) maxM = board[j-2][N-1];
             if (j<=N-3 && board[j+2][N-1]>maxM)
                    maxM = board[j+2][N-1];
             
             board[j][N-2]+=maxM;
         }
         
         for (int k=N-3; k>=Kc; k--)
         {
             for (int j=0; j<N; j++)
             {
                 maxM=0;
                 if (j>=2)
                    maxM = board[j-2][k+1];
                 if (j<=N-3 && board[j+2][k+1]>maxM)
                    maxM = board[j+2][k+1];
                 
                 if (j>=1 && board[j-1][k+2]>maxM)
                    maxM = board[j-1][k+2];
                 if (j<=N-2 && board[j+1][k+2]>maxM)
                    maxM = board[j+1][k+2];
                 
                 board[j][k]+=maxM;
             }
         }
                       
            printf("%d%c",board[Kr][Kc], '\n');
        }
}