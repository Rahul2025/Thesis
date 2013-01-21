import java.util.*;
import java.io.*;
class Pract
{
  public static void main(String []args)throws Exception
	{
		BufferedReader br=new BufferedReader(new  InputStreamReader(System.in));
		Integer N=Integer.parseInt(br.readLine());
		for(int i=0;i<N;i++)
		{	int b=0;
			int i1=0,i2=0;
			String s[]=(br.readLine()).split(" ");
			int n1=Integer.parseInt(s[0]);
			int n2=Integer.parseInt(s[1]);
			i1=Integer.parseInt(new StringBuilder(n1+"").reverse().toString());
			i2=Integer.parseInt(new StringBuilder(n2+"").reverse().toString());
			int temp=Integer.parseInt(new 

StringBuilder((i1+i2)+"").reverse().toString());
					 
			System.out.println(temp);
		}
	}
 static int Reverse(int i){
		int d,m=0;
		while(i>0)
		{
			d=i%10;
			i=i/10;
			m=m*10+d;	
		}
	 return m;
	}
} 