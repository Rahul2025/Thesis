import java.io.*;
class Main {
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int test;
		test=Integer.parseInt(br.readLine());
		while(test!=0)
		{
			
		
		String s=br.readLine();
		int n=s.length();
		int	m=n/2;
		String t1=s.substring(0,m);
		StringBuffer t3=new StringBuffer(t1);
		t3.reverse();
		t1=t3+"";
		String t2=s.substring(m,n);
		StringBuffer t4=new StringBuffer(t2);
		t4.reverse();
		t2=t4+"";
		String ans=t1.concat(t2);
		System.out.println(ans);
		test--;
		}
	}

}