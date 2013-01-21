import java.io.*;
class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new
		InputStreamReader(System.in));
		String str=br.readLine();
		int index=str.indexOf(' ');
		int n=Integer.parseInt(str.substring(0,index));
		int q=Integer.parseInt(str.substring(index+1));
		String ext[]=new String[n];
		String media[]=new String[n];
		for(int i=0;i<n;i++)
		{
			str=br.readLine();
			index=str.indexOf(' ');
			ext[i]=str.substring(0,index);
			media[i]=str.substring(index+1);
		}
		for(int i=0;i<q;i++)
		{
			str=br.readLine();
			index=str.lastIndexOf('.');
			if(index==-1)
			{
				System.out.println("unknown");
				continue;
			}
			str=str.substring(index+1);
			int j;
			for(j=0;j<n;j++)
			if(str.compareTo(ext[j])==0)
			break;
			if(j==n)
			System.out.println("unknown");
			else
			System.out.println(media[j]);
		}
	}
}