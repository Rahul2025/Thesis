import java.io.*;
import java.util.*;
class Main_1
{
public static long cr(long n)
{
if(n<3)
return(0);
else
return((n*(n-1)*(n-2))/6);
}
public static void main(String args[])throws IOException
{
BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
int t=Integer.parseInt(in.readLine());
StringBuffer ss=new StringBuffer("");
for(int qq=1;qq<=t;qq++)
{
StringTokenizer s=new StringTokenizer(in.readLine());
long N=Long.parseLong(s.nextToken());
long A=Long.parseLong(s.nextToken());
long B=Long.parseLong(s.nextToken());
long C=Long.parseLong(s.nextToken());
long sum;A++;B++;C++;
sum=cr(N+3)-cr(N+3-A)-cr(N+3-B)-cr(N+3-C)+cr(N+3-A-B)+cr(N+3-B-C)+cr(N+3-A-C)-cr(N+3-A-B-C);
ss.append(sum);
ss.append('\n');
}
System.out.println(ss);
}
}