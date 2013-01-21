import java.io.*;
import java.util.*;
public class Main_1
{
public static void main(String args[])throws IOException
{
BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
int t=Integer.parseInt(in.readLine());
StringBuffer str=new StringBuffer("");
for(int i=1;i<=t;i++)
{
String s=in.readLine();
int avg=0;
for(int j=0;j<s.length();j++)
avg+=(int)(s.charAt(j));
avg/=(s.length());
str.append((char)(avg));
str.append('\n');
}
System.out.println(str);
}
}