import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;


public class Main_1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int t=0;	//for test cases
		int no,reverseno,sum;
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		
		try
		{
			t=Integer.parseInt(br.readLine());
		}
		catch(Exception e)
		{
			
		}
		Main_1 ob=new Main_1();
		for(int i=0;i<t;i++)
		{
			sum=0;
			try
			{
				String line=br.readLine();
				String a[]=line.split(" ");
				for(int j=0;j<2;j++)
				{
				sum+=ob.reverseno(Integer.parseInt(a[j]));
				}
				System.out.println(ob.reverseno(sum));
			}catch(Exception e)
			{
				
			}
		}
	}
	public int reverseno(int no)
	{
		
		int rno=0;
		while(no!=0)
		{
		rno=rno*10+(no%10);
		no/=10;
		}
		return rno;	
	}

}