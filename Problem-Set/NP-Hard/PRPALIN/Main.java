import java.util.*;
class Main
{
	public static void main(String [] args)throws Exception
	{
		Scanner in = new Scanner(System.in);
		int n,m,re,i;
		n=in.nextInt();
		int rev,temp;
		for(i=n;;i++)
		{	
			rev=temp=0;
			int j=i;
			while(j>0)
			{
				temp = j%10;
				j /=10;
				rev =rev*10 + temp;
			}
			if(i==rev)
			{
				if(i==1 || i==2)
				{
					System.out.println(i);
					System.exit(0);
				}
				if(isPrime(i))
				{
					System.out.println(i);
					System.exit(0);
				}
			}
		}
	}
	static boolean isPrime(int k) 
	{
    	for(int l=2;l<k/2;l++) 
    	{
       		if(k%l==0)
           		return false;
    	}
    	return true;
	}
}