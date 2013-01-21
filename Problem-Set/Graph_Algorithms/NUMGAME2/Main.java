import java.util.Scanner;;
public class Main {

private static int T;
private static int N;
private static int[] ans;
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		T=kb.nextInt();
		ans=new int[T];
		for(int i=0;i<T;i++)
		{
			N=kb.nextInt();
			if((N%4)==1)
				ans[i]=1;
			else
				ans[i]=2;
		}
		for(int i=0;i<T;i++)
		{
			if(ans[i]==1)
				System.out.println("ALICE");
			else
				System.out.println("BOB");
		}

	}

}