import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Main_1
{
	public static int invCount = 0;
	public static void mergeSort(int[] a, int i, int j)
	{
		if(i < j)
		{
			mergeSort(a, i, (i+j)/2);
			mergeSort(a, (i+j)/2+1, j);
			merge(a, i, (i+j)/2, j);
		}
		
	}
	
	public static void merge(int[] a, int start, int mid, int end)
	{
		int tempinv = 0;
		//System.out.println("start = " + start + " end = " + end);
		//System.out.print("a = ");
		//for(int t = start; t <= mid; t++)
		//  System.out.print(a[t] + " ");
		//System.out.println();
		//System.out.print("b = ");
		//for(int t = mid+1; t <= end; t++)
		//	System.out.print(a[t] + " ");
			
		//  System.out.println();
		
		int[] c = new int[end-start+1];
		int count = 0;
		int i = start, j = mid+1;
		
		while(i <= mid && j <= end)
			if(a[i] < a[j])
				c[count++] = a[i++];
			else
			{
				tempinv += (mid-i+1);
			    c[count++] = a[j++];
			}
		
		while(i <= mid)
		{
			c[count++] = a[i++];
		}
		
		while(j <= end)
			c[count++] = a[j++];
		
		for(int k = 0; k < count; k++)
			a[start + k] = c[k];
		invCount += tempinv;
		//System.out.println("tempinv = " + tempinv);
	}
	
	
	public static void main(String args[]) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());

		StringTokenizer st = new StringTokenizer(in.readLine());
		int[] a = new int[n];
		int count = 0;
		while(st.hasMoreTokens())
			a[count++] = Integer.parseInt(st.nextToken());
		
		invCount = 0;
		mergeSort(a, 0, n-1);
		//System.out.println(Arrays.toString(a));
		System.out.println(invCount);
	}
}