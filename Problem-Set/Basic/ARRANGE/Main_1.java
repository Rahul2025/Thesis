import java.io.*;
import java.lang.*;


public class Main_1
{
	static int[][] A;

	static int reverse(int n,int k)
	{
		int ans=0;
		for(int i=0;i<k;i++)
		{
			int bit=(n>>i)&1;
			ans|=bit<<(k-1-i);
		}
		return ans;
	}
	static void calc()
	{
		A = new int[2][65536];
		A[1][0] = 0;
		A[1][1] = 1;
		int n=2;
		int tmp;
	
		for(int k=2, j=0; k<17; k++, n<<=1, j=1-j)
		{
			for(int i=0,s=0; i<n;i++,s+=2)
			{
				tmp = A[1-j][i];
				A[j][s] = tmp;
				A[j][1+s] = n + tmp;
			}
		}
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader kin=new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(kin.readLine());
		char []ans=new char[1<<17];
		while(T-- >0)
		{
			String []sp = kin.readLine().split(" ");
			int k=Integer.parseInt(sp[0]);
			int n=1<<k;

			for(int i=0; i<n; i++)
				ans[i]=sp[1].charAt(reverse(i,k));

			System.out.println(String.valueOf(ans,0,n));
		}

	}
}