import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 *
 * @author Abhishek Banerjee
 */
public class Main {
    public static void main(String args[]) throws IOException{
     
     int n=0,k,y,j,yu;
     ArrayList a=new ArrayList(1000);
     BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out=new PrintWriter(System.out);
     n=Integer.parseInt(br.readLine());
     while(n-->0)
     {
     k=Integer.parseInt(br.readLine());
     for( y=0;y<k*2;y++){
     br.readLine();
     }
     for(y=0;y<k;y++){
     a.add(""+(y+1));
     }
     yu=k-1;
     for(int i=0;i<k;i++){
         
int ri=    (int) (Math.random() * yu);
out.print((String)a.get(ri)+" ");
a.remove(ri);yu--;
}
     out.println();
     for(y=0;y<k;y++){
     a.add(""+(y+1));
     }
     yu=k-1;
     for(int i=0;i<k;i++){
         
int ri=    (int) (Math.random() * yu);
out.print((String)a.get(ri)+" ");
a.remove(ri);yu--;
} out.println();
     }
     out.close();
    }
}