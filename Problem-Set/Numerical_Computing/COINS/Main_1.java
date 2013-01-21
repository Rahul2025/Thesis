import java.io.*;

import java.util.Hashtable;

class Main_1

{

	

	static Hashtable<Long,Long> h = new Hashtable();

	

	public static void main(String args[]) throws Exception

	{

		BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );

		try

		{

			while( true )

			{

				System.out.println( max(Long.parseLong(in.readLine()) ) );

			}

		}

		catch(Exception e) { }

	}

	public static long max(long n)

	{

		if( n<=4 ) return n;

		long N = n;

		Long value = (Long) h.get( N );

		if( value == null ) 		

		{

			value = Math.max ( n, max(n/3)+ max(n/2) + max(n/4) );

			h.put( N , value );

		}

		return value.longValue();

	}

}



	