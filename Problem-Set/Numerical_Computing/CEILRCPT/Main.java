import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String args[] ) throws Exception {
	
		HashMap valueMap = new HashMap();
        int[] temp = {1,2,4,8,16,32,64,128,256,512,1024,2048};
		int count=0;
		
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int nooflines = Integer.parseInt(line);
        for(int i=0; i<nooflines; i++)
		{
			count=0;
			line = br.readLine();
			int value = Integer.parseInt(line);
			int powerValue = (int)((Math.log(value)/Math.log(2)));
			
			while(value > 2048)
			{
				value = value-2048;
				count++;
			}
			while(value >= 1)
			{	
				powerValue = (int)((Math.log(value)/Math.log(2)));
				value = value - (int)Math.pow(2.0,powerValue);
				count++;
			}
			System.out.println(count);
		}
    }
}