import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
class Main_1
{
	public static void main(String args[])throws Exception
	{
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

		PrintWriter p = new PrintWriter(System.out);

		int i=1,j,tmp;
		int a[] = new int[8002];
		a[1]=1;		

		for(j=2;j<=8000;j+=2)
		{
			a[j]=a[i]*5;
			a[j+1]=a[j]+1;
			i++;
		}

		int t = Integer.parseInt(r.readLine());

		while(t!=0)
		{
			p.println(5*a[Integer.parseInt(r.readLine())]);
			t--;
		}
		p.flush();
	}
}