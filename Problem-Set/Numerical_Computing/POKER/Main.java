import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int t = Integer.valueOf(br.readLine()).intValue(), i=1, temp;
		char a,b;
		int[] suit = new int[5];
		int[] rank = new int[5];
		while(i<=t)
		{
		
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j=0; j<5; j++)
			{
				
				String s = st.nextToken();
				//System.out.println(s);
				a=s.charAt(0);
				if (a=='A') rank[j]=14;
				else if (a=='K') rank[j]=13;
				else if (a=='Q') rank[j]=12;
				else if (a=='J') rank[j]=11;
				else if (a=='T')rank[j]=10;
				else rank[j]=Integer.valueOf(Character.toString(a)).intValue();		//changing char to int - creates problems
				b=s.charAt(1);
				if (b=='S') suit[j]=1;
				else if (b=='H') suit[j]=2;
				else if (b=='D') suit[j]=3;
				else if (b=='C') suit[j]=4;
				//System.out.println(rank[j]+"	" + suit[j]);
			}
			for (int j=3; j>=0; j--)					//problem found here
			{
				for (int k=0; k<=j; k++)
				{
					if (rank[k]>rank[k+1]) {temp=rank[k]; rank[k]=rank[k+1]; rank[k+1]=temp;}
				}
			}
			boolean samesuit=false;
			if (suit[0]==suit[1] && suit[0]==suit[2] && suit[0]==suit[3] && suit[0]==suit[4]) samesuit=true;		
			//System.out.println(rank[0] + "  "+rank[1] + "  "+rank[2] + "  "+rank[3] + "  "+rank[4] + "  ");
			if (samesuit && rank[0]>=10) System.out.println("royal flush");			
			else if (samesuit && ((rank[1]==rank[0]+1 && rank[2]==rank[0]+2 && rank[3]==rank[0]+3 && rank[4]==rank[0]+4) || (rank[0]==2 && rank[1]==3 && rank[2]==4 && rank[3]==5 && rank[4]==14))) System.out.println("straight flush");
			else if (rank[0]==rank[3] ||rank[1]==rank[4]) System.out.println("four of a kind");
			else if ((rank[0]==rank[2] && rank[3]==rank[4]) || (rank[0]==rank[1] && rank[2]==rank[4])) System.out.println("full house");
			else if (samesuit) System.out.println("flush");
			else if ((rank[1]==rank[0]+1 && rank[2]==rank[0]+2 && rank[3]==rank[0]+3 && rank[4]==rank[0]+4) || (rank[0]==2 && rank[1]==3 && rank[2]==4 && rank[3]==5 && rank[4]==14)) System.out.println("straight");
			else if (rank[0]==rank[2] || rank[1]==rank[3] || rank[2]==rank[4]) System.out.println("three of a kind");
			else if ((rank[0]==rank[1] && rank[2]==rank[3]) || (rank[1]==rank[2] && rank[3]==rank[4]) || (rank[0]==rank[1] && rank[3]==rank[4])) System.out.println("two pairs");	//problem found here
			else if (rank[0]==rank[1] || rank[1]==rank[2] || rank[2]==rank[3] || rank[3]==rank[4]) System.out.println("pair");
			else System.out.println("high card");
			i++;
 
		}
	}
} 