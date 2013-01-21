import java.util.*;
import java.io.*;
class Main
{
public static void main(String args[])throws IOException{
 
BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
//Scanner pin =new Scanner(System.in);
int t=Integer.parseInt(input.readLine());
for(;t>0;t--)
{
String tmp[] = input.readLine().split(" "); 
  String s2=tmp[0];
  String s1=tmp[1];
int n=Integer.parseInt(s2);
int r=Integer.parseInt(s1);
int a[]=new int[n];
int sum=0,flag=0;
String wemp[] = input.readLine().split(" "); 
for(int i=0;i<n;i++)
{
String p=wemp[i];
a[i]=Integer.parseInt(p); 
 sum=sum+a[i];
}
  
  
 //System.out.println(sum);
 
boolean s[]=new boolean[sum+5];
s[0]=true;
int j=0;
for(;j<n;j++)
{
int i=a[j];
for(int k=r;k>=i;k--)
{
if(s[k-i])
{
s[k]=true;
if(k==r)
{
flag=1;
break;
}
}
}}
if(flag==1)
System.out.println("1");
else
System.out.println("0");
}}}