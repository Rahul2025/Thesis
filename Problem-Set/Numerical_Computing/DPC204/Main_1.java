import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main_1{
   
   public static BigInteger fib(BigInteger n1,BigInteger n2,BigInteger prev,BigInteger prevprev,BigInteger no){
      BigInteger curr=prev.add(prevprev);
      if(curr.compareTo(n1)<0) return fib(n1,n2,curr,prev,no);
      if(prev.add(curr).compareTo(n2)==1) return no.add(BigInteger.ONE);
      if(prev.add(curr).compareTo(n1.multiply(BigInteger.valueOf(2)))==1) return fib(n1.multiply(BigInteger.valueOf(2)),n2,curr,prev,no.add(BigInteger.ONE));
      else return fib(n1.multiply(BigInteger.valueOf(2)),n2,curr,prev,no.add(BigInteger.valueOf(2)));
   }

   public static void main(String [] args) throws IOException{
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       String t1;
       String t2;
       while(true){
           String tmp=br.readLine();
           StringTokenizer st=new StringTokenizer(tmp);
           t1=st.nextToken();
           t2=st.nextToken();
           if(t1.equals("0") && t2.equals("0")) break;
           BigInteger bi1=new BigInteger(t1);
           BigInteger bi2=new BigInteger(t2);
           System.out.println(fib(bi1,bi2,BigInteger.valueOf(1),BigInteger.valueOf(1),BigInteger.valueOf(0)));
       }
   }
}