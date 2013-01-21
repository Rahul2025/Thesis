import java.io.*;
public class Main
{
public static void main(String args[])throws IOException
{
InputStreamReader isr=new InputStreamReader(System.in);
BufferedReader br=new BufferedReader (isr);
int t=Integer.parseInt(br.readLine());
int i,k,j,l,p=0;
int out[]=new int[t];
boolean status=true;
for(i=0;i<t;i++)
{
k=Integer.parseInt(br.readLine())+1;
while(status==true)
{
l=rever(k);
if(k==l)
break;
else
k++;
}
out[p++]=k;
}
for(i=0;i<p;i++)
System.out.println(out[i]);
}
public static int rever(int n)
{
int rem,rev=0;
while(n>0)
{
rem=n%10;
rev=rev*10+rem;
n=n/10;
}
return rev;
}}