//coded by c0d3rb0y

import java.io.*;

class Main_1
{
public int palin(int num){
String s=Integer.toString(num);
StringBuffer ss=new StringBuffer(s);
String sa=ss.reverse().toString();
if(s.equals(sa))
{
return -1;
}
else{
int ni=Integer.parseInt(sa);
return ni;
}
}
public static void main(String args[])throws IOException{

Main_1 p=new Main_1();
DataInputStream d=new DataInputStream(System.in);
int n=Integer.parseInt(d.readLine());
int a[]=new int[n];
int b[]=new int[n];
int k,l,m=0;
for(int i=0;i<n;i++){
a[i]=Integer.parseInt(d.readLine());
}
if(n>0&&n<=100){
for(int i=0;i<n;i++){
m=0;
k=p.palin(a[i]);
while(k!=-1)
{
a[i]=a[i]+k;
m++;
k=p.palin(a[i]);
}
b[i]=m;
}
}
for(int i=0;i<n;i++)
{
System.out.println(b[i]+" "+a[i]);
}
}
}