import java. io.*;
import java.util.*;
public class Main_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws IOException {
        BufferedReader in= new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out= new BufferedWriter(new OutputStreamWriter(System.out));
        int n= Integer.parseInt(in.readLine());
        while(n!=0){
         
           int L[]= new int[n];
           StringTokenizer tokenz= new StringTokenizer(in.readLine());
           for(int i=0;i<n;i++){
               L[i]=Integer.parseInt(tokenz.nextToken());
           }
           Arrays.sort(L);
           int count=0;
           for(int i=n-1;i>=2;i--){
               int pivot=L[i];
               int init=0; int fin=i-1;
               while(init!=fin){
                   if(L[init]+L[fin]<pivot){
                       count+=fin-init;
                       init++;
                   }else{
                       fin--;
                   }
               }
           }
           out.append(String.valueOf(count));out.newLine();
           n= Integer.parseInt(in.readLine());
        }
        out.flush();
    }

}