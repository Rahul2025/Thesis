import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		int testCases;
		int n, m;
		int k,l;
		//int table[][];
		//int denominations[];
		StringBuffer b = new StringBuffer();
		if((line = br.readLine())!= null){
			testCases = Integer.parseInt(line.trim());
			//System.out.println("");
			while(testCases-->0){
				line = br.readLine().trim();
				String strArr[] = line.split(" ");
				n = Integer.parseInt(strArr[0]);
				m = Integer.parseInt(strArr[1]);
				int table[][]  = new int[m][n];
				int denominations[] = new int[n];
				for(int i = 0; i< n; i++){
					denominations[i] = Integer.parseInt(br.readLine().trim());
				}
				for(int i=0; i<n; i++){
					if((k = denominations[i]) <= m)
						table[k-1][i] = 1;
					for(int j=0; j<m; j++){
					//	System.out.print("P "+table[j][i]+" ");
//						if(i >  0 && j != k-1)
//							table[j][i] = table[j][i-1];
						if(i >  0){
						l= table[j][i-1];
						if( l == 1){
							table[j][i] = table[j][i-1];
							
							if( j + k < m){
								table[j+k][i] = 1;
							}
						}
						}
					//	System.out.print(table[j][i]+" ");
						
					}
				//	System.out.println("");
				}
				if(table[m-1][n-1] == 1)
					b.append("Yes").append('\n');
				else b.append("No").append('\n');
				
				
			}
			System.out.print(b);
		}
		
	}
	
}