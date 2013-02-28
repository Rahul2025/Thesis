import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Collections;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashSet;

public class Main
{
	public static final boolean FILE = false;
	public static int boredomFactor[];
	public static int songChoice[][];
	public static void main(String args[]) throws Exception
	{

		BufferedReader reader = null;
		PrintWriter writer = null;

		if(!FILE)
		{

			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);

		}
		else
		{

			reader = new BufferedReader(new FileReader("in.txt"));
			writer = new PrintWriter("out.txt");

		}
		int numOfDancers = 0, numOfSongs = 0;
		int temp = 0;
		int numOfDisLikes[], numOfLikes[];
		float dancerPriority[], songPriority[];

		String line = reader.readLine();
		temp = line.indexOf(" ");
		numOfDancers = Integer.parseInt(line.substring(0,temp));//D
		numOfSongs = Integer.parseInt(line.substring(temp+1));//S

		boredomFactor = new int[numOfDancers];
		StringTokenizer st = new StringTokenizer(reader.readLine());//by default the delimiter is blank space
		for(int i = 0; i < numOfDancers; i++)
		{
			boredomFactor[i] = Integer.parseInt(st.nextToken());
		}

		numOfLikes = new int[numOfDancers];
		numOfDisLikes = new int[numOfDancers];
		songChoice = new int[numOfDancers][numOfSongs];
		dancerPriority = new float[numOfDancers];
		for(int j = 0; j < numOfDancers; j++)
		{
			st = new StringTokenizer(reader.readLine());//by default the delimiter is blank space
			numOfLikes[j] = 0;
			for(int k = 0; k < numOfSongs; k++)
			{
				songChoice[j][k] = Integer.parseInt(st.nextToken());
				numOfLikes[j] = numOfLikes[j] + songChoice[j][k];
			}
			//populate numOdDislikes and calculate dancerPriority
			numOfDisLikes[j] = numOfSongs - numOfLikes[j];
			dancerPriority[j] = (float)boredomFactor[j]/(float)numOfDisLikes[j];
			//System.out.println("dancerPriority"+j+" = "+dancerPriority[j]);

		}

		//end of reading data
		//calculate songPriority
		songPriority = new float[numOfSongs];
		for(int l = 0; l < numOfSongs; l++)
		{
			songPriority[l] = 0.0f;
			for(int m = 0; m < numOfDancers; m++)
			{
				songPriority[l] = songPriority[l] + (dancerPriority[m]*songChoice[m][l]);
			}
			//System.out.println("songPriority"+l+" = "+songPriority[l]);
		}

		Song s[] = new Song[numOfSongs];
		for(int n = 0; n < numOfSongs; n++)
		{
			s[n] = new Song(n, songPriority[n]);
		}

		List<Song> al = Arrays.asList(s);
		Collections.sort(al);
		//s = (Song[])al.toArray();

		/*for(int o = 0; o < numOfSongs; o++)
    {
    System.out.println(s[o].songNum);
    }*/

		//get the one with the highest priority
		int songCount = numOfSongs-1;
		int previousDancerCount = 0;
		ArrayList playlist = new ArrayList();
		HashSet dancers = new HashSet();
		Song highestPrioritySong = s[songCount];
		playlist.add(highestPrioritySong.songNum);
		int minWindow = minWindow(highestPrioritySong, numOfDancers);
		songCount--;

		//initialize dancers and previousDancerCount
		for(int q = 0; q < numOfDancers; q++)
		{
			if(songChoice[q][highestPrioritySong.songNum] == 1)
				dancers.add(q);
		}
		previousDancerCount = dancers.size();
		//System.out.println("previousDancerCount:"+previousDancerCount);
		//System.out.println("songCount:"+songCount);

		for(int p = 0; p < (minWindow-1) && songCount >= 0; songCount--)
		{
			Song t = s[songCount];
			//System.out.println("songNum:"+t.songNum);
			HashSet hs = getDancers(t, dancers, numOfDancers);
			if(minWindow(t, numOfDancers) >= minWindow && hs.size() >= previousDancerCount)
			{
				playlist.add(t.songNum);
				dancers = hs;
				p++;
			}
		}
		//print the results
		writer.println(playlist.size());
		for(int count = 0; count < playlist.size(); count++)
			writer.println(playlist.get(count));

		writer.flush();
		writer.close();

	}//end of main

	public static int minWindow(Song temp, int numOfDancers)
	{
		int minWindow = Integer.MAX_VALUE;
		for(int p = 0; p < numOfDancers; p++)
		{
			if(songChoice[p][temp.songNum] == 1)
			{
				minWindow = minWindow < boredomFactor[p] ? minWindow : boredomFactor[p];
			}
		}

		//System.out.println("minWindow:"+minWindow);
		return minWindow;
	}


	public static HashSet getDancers(Song s, HashSet dancers, int totalDancers)
	{
		HashSet hset = (HashSet)dancers.clone();
		for(int count = 0; count < totalDancers; count++)
		{
			if(songChoice[count][s.songNum] == 1)
				hset.add(count);
		}

		//System.out.println("hset:"+hset.size());
		return hset;
	}

}//end of Main class


class Song implements Comparable<Song>
{

	public int songNum;
	public float songPriority;

	public Song(int a, float b)
	{
		songNum = a;
		songPriority = b;
	}

	public int compareTo(Song other)
	{
		return (new Float(songPriority)).compareTo(new Float(other.songPriority));
	}
} 