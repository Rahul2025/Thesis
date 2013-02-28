import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {
    public static void main(String []args)
    {
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		try{
		int count=Integer.parseInt(br.readLine());
                long[] no=new long[count];
		   for(int i=0;i<count;i++)
		   { 	
                       no[i]=Long.parseLong(br.readLine());
                    
			if( no[i]%2!=0)
                        {
                            no[i]-= 1 ;
                        }
                   }
                    for(int i=0;i<count;i++)
		   {
                   System.out.println(no[i]);
                   }
		}catch(Exception e)
		{
			e.printStackTrace();
		}	
    }
}