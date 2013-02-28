import java.io.IOException;
import java.util.Arrays;
import static java.lang.System.in;

class Main_1 {
	public static void main(String[] args) throws IOException {
		StringBuffer output = new StringBuffer();
		int N = 0;
		int bufferSize;
		byte buffer[] = new byte[8192];
		boolean readN = true;
		while((in.read())!='\n');
		int curPos = 0;
		int V1, V2, C1, C2;
		int A[]=null;
		while((bufferSize=in.read(buffer))>0){
			for(int i=0; i<bufferSize; ++i){
				if(readN){
					if(buffer[i]!='\n')	N = N*10+buffer[i]-'0';
					else{
						A = new int[N];
						readN = false;
						N = 0;
					}
				}
				else{
					if(buffer[i]==' ')
						curPos+=1;
					else if(buffer[i]=='\n'){
						V1 = 0;
						V2 = A[0];
						C1 = 0;
						C2 = 0;
						Arrays.sort(A);
						for(int j=0; j<A.length; ++j){
							if(A[j]!=V2){
								if(C2>C1){
									V1=V2;
									C1=C2;
								}
								C2=1;
								V2=A[j];
							}
							else C2+=1;
						}
						readN = true;
						curPos = 0;
						if(C1>=C2) output.append(V1+" "+C1+'\n');
						else output.append(V2+" "+C2+'\n');
					}
					else A[curPos]=A[curPos]*10+buffer[i]-'0';
				}
			}
		}
		System.out.print(output.toString());
	}
}