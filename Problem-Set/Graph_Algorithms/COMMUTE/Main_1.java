import java.io.*;
import java.util.*;
public class Main_1{
public static void main(String args[])throws Exception{
BufferedReader br=new BufferedReader (new InputStreamReader(System.in));
int tc=Integer.parseInt(br.readLine());
int i=0,j=0,k=0,p=0,m=0,t=0,a=0,b=0,c=0;
StringTokenizer st=null;
while(tc-->0){
m=Integer.parseInt(br.readLine());
while(m-->0)
{st=new StringTokenizer(br.readLine());
a=Integer.parseInt(st.nextToken());
b=Integer.parseInt(st.nextToken());
c=Integer.parseInt(st.nextToken());
t=t<=a?t+(a-t)+b:t+b+(a+c*((t-a)/c+((t-a)%c>0?1:0))-t);

}
System.out.println(t);
t=0;
}
}}