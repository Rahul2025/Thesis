//package popularRiceRecipe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

//public class PopularRiceRecipe
public class Main_1
{
	static Map < String , String > votersMap;
	
	public static void main ( String [ ] args )
	{
		BufferedReader reader;
	    
	    int numberOfTestCases, numberOfVotes;
	    String tempString;
	    int voteCount;
	    
	    try
		{
	    	reader = new BufferedReader(new InputStreamReader(System.in));
			numberOfTestCases = Integer.parseInt( reader.readLine() );
			
			for ( int counter = 0 ; counter < numberOfTestCases ; counter ++ )
			{
				votersMap = new HashMap < String , String >( );
				numberOfVotes = Integer.parseInt( reader.readLine() );
				voteCount = 0;
				
				for ( int voteCounter = 0 ; voteCounter < numberOfVotes ; voteCounter ++ )
				{
					tempString = reader.readLine( );
					votersMap.put( tempString.substring( 0 , tempString.length( ) - 2 ) , tempString.substring( tempString.length( ) - 1 ) );
				}
					
				for( Map.Entry < String , String > mapElement : votersMap.entrySet( ) )
				{
					//System.out.println( mapElement.getKey( ) + " : " + mapElement.getValue( ) );
					if ( mapElement.getValue( ).equalsIgnoreCase( "+" ) )
						voteCount ++;
					else
						voteCount --;
				}
				
				System.out.println( voteCount );
			}
		}
	    catch( NumberFormatException e )
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	    catch( IOException e )
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}