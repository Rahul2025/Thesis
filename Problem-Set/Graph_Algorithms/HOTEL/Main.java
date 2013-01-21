import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
 class Main {
 	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);int t=in.readInt();
		while(t>0){
			
			int n=in.readInt();
			int arrivalTime[]=new int[n];
			int departureTime[]=new int[n];
	        int i=0;
			// Values Taken
	        int min=100001,max=0;
	        while(i<n){
			arrivalTime[i]=in.readInt();	
				
				if(min>arrivalTime[i]){
					min=arrivalTime[i];
				}
				i++;
			}
			i=0;
			while(i<n){
				
				departureTime[i]=in.readInt();
			if(max<departureTime[i])
				max=departureTime[i];
				i++;
			}
			int ans=0;
			int counter=0;
			while(min<max){
				counter=0;
				for (int j = 0; j < n; j++) {
					if(min>=arrivalTime[j]&&min<departureTime[j]){
						counter++;
					}
				}
				if(ans<counter)
					ans=counter;
				
				min++;
			}
			System.out.println(ans);
			
			
			t--;}

	
	}

}


class InputReader {
	 

	
	private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
 
    public InputReader(InputStream stream) {
        this.stream = stream;
    }
 
    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }
 
    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }
 
    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}



// All values took

/*for(int i1=0;i1<n;i1++){			
			for (int j = 0; j <=departureTime[i1]-arrivalTime[i1]; j++) {
			
				int counter=0;
				int counter2 = 0;
				System.out.println(counter);
			
			for (int j1 = 1; j1 < n; j1++) {
				if(arrivalTime[i1]+j>=arrivalTime[j1]&&arrivalTime[i1]<departureTime[j1]){
					counter++;
			//System.out.println("sex");
					if(counter==(n-1)){
				//		System.out.println("love");
						System.out.println(n);
						break;
				}
				}
				else if(arrivalTime[i1]+j<=arrivalTime[j1]&&arrivalTime[j1]<departureTime[i1]){
					counter2++;
					if(counter2==(n-1)){
					//	System.out.println("chut");
						System.out.println(n);
						break;
	
					}
				
				}
				
				
			}
			System.out.println(counter+" "+counter2);
			}
			
}
*/			