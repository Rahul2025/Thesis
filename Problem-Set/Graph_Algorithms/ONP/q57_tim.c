#include <stdio.h>
#include <stdlib.h>

//#define SIZE 40000
/*
 * 
 */
int main(int argc, char** argv) {
    char stk[400],tmp[400],op[100][400];
    int n,bc,i,ti,j,mc=0,pc,top,opi;;
    scanf("%d\n",&n);
    //bc=fread(buff,1,SIZE,stdin);
    for(i=0;i<n;i++)
    {
        //if(buff[i] == '\n') {
        gets(tmp);
            top=-1;opi=0;
            for(j=0;tmp[j]!='\0';j++)
            {
                switch(tmp[j])
                {
                    case '(':
                        
                        break;
                    case ')':
                        op[i][opi++]=stk[top--];
                        break;
                    case '+':
                    case '/':
                    case '-':
                    case '*':
                    case '^':
                        stk[++top]=tmp[j];
                        break;
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                        op[i][opi++]=tmp[j];
                        break;
                }
            }
            op[i][opi]='\0';
            //printf("%s\n",op);
            //ti=0;
            
        //}
        //else
         //   tmp[ti++]=buff[i];
    }
    for(i=0;i<n;i++)
        printf("%s\n",op[i]);
    return (EXIT_SUCCESS);
}