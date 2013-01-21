import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
	public static void main( String args[] ) throws Exception
	{
		BufferedReader r = new BufferedReader( new InputStreamReader( System.in ));
		int cases = Integer.parseInt( r.readLine() );
		int[] f_num = new int[cases];
		int[] l_num = new int[cases];
		int[] rslt = new int[cases];
		
		for( int i = 0 ; i < cases ; i++ )
		{
			int no_nails = Integer.parseInt( r.readLine() );
			StringTokenizer st = new StringTokenizer( r.readLine() );
			char[] price = new char[5];
			for( int j = 1 ; j < 4 ; j++ )
			{
				price[ j ] = st.nextToken().charAt(0);
			}
			int num = 0;
			boolean b = false;
			for( int j = 9 ; j > 0 ; j-- )
			{
				for( int x = 9 ; x >=0 ; x-- )
				{
					price[0] =(char)(j+48);
					price[4] =(char)(x+48);
					
					
					String str = new String( price );
					num = Integer.parseInt( str );
					
					if( ( num % no_nails ) ==  0 )
					{
						b = true;
						f_num[i] = j;
						l_num[i] = x;
						rslt[i] = (num/no_nails);
						break;
					}
				}
				if( b == true )
				   break;
			}
			if( b == false )
			  rslt[i] = 0 ;
		}
				
		for( int i = 0 ; i < cases ; i++ )
		{
                  	if ( rslt[i] != 0 )
                  		System.out.printf("%d %d %d\n",f_num[i],l_num[i],rslt[i] );
                  	else
                  		System.out.println(0);
                }
        }
}
                  		
					
				