import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Main_1 {
 //private static InputReader ir;
 private static PrintWriter pw;
 
public static void main(String[] args) throws IOException {
//ir = new InputReader();
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(System.out, true);

int []freq = new int[10];
int a,b,c,d,i,j,div;
int sum;
BigInteger MOD = BigInteger.valueOf(1000000007);
int []used = new int[10];
BigInteger temp;
BigInteger op;
int t = Integer.parseInt(br.readLine());
String num;

while(t>0){
t--;
num = br.readLine();
Arrays.fill(freq,0);

for(i=0;i<num.length();i++){
    freq[(num.charAt(i)-'0')]++;
}

op = BigInteger.valueOf(0);

for(a=0;a<11;a++){
    for(b=a;b<11;b++){
        for(c=b;c<11;c++){
            for(d=c;d<11;d++){
                sum = 0;
                Arrays.fill(used,0);
                if(a<10){
                sum += a;
                used[a]++;
                }
                if(b<10){
                sum += b;
                used[b]++;
                }
                if(c<10){
                sum += c;
                used[c]++;
                }
                if(d<10){
                sum += d;
                used[d]++;
                }
                if((sum==0)||((sum%9)!=0))
                    continue;
//                pw.println(a + " " + b + " " + c + " " + d);
                temp = BigInteger.valueOf(1);
                for( i=0;i<10;i++){
                    for(j=0;j<used[i];j++){
//                        pw.println(used[1] + " " + used[8]);
                        temp = temp.multiply(BigInteger.valueOf(freq[i]-j));
//                        pw.println(temp);
                        temp = temp.divide(BigInteger.valueOf(j+1));
//                        pw.println();
                    }
                }
                op = (op.add(temp));                
            }
        }
    }
}

pw.println(op.remainder(MOD));
}
  pw.flush();
  pw.close();
 }
}