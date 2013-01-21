import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main implements Runnable{
        
    public static void main(String args[]){
       new Main().run();
    }
    
     public static final String INPUT_FILE = "input.in";
     public static final String OUTPUT_FILE = "output.out";
  
    @Override
    public void run(){
        try{
//        in = new BufferedReader(new FileReader(INPUT_FILE));
//        out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FILE)));
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            tok = null;
            solve();
            in.close();
            out.close();
            
        }
        catch(IOException e){
            e.printStackTrace();
            System.exit(0);
        }
    }
    
    int nextInt()throws IOException{
        return Integer.parseInt(nextToken());
    } 
    
    double nextDouble()throws IOException{
        return Double.parseDouble(nextToken());
    }
    
    long nextLong() throws IOException{
        return Long.parseLong(nextToken());
    }
    
    String nextToken()throws IOException{
        while(tok == null || !tok.hasMoreTokens()){
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }
    
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok;
    //////////////////////////////////////////////////////////////////
    

    private void solve()throws IOException{
        int T = nextInt();
        while(T-- > 0) System.out.println(solve2());
    }
    
   private String solve2() throws IOException{
       int r = nextInt();
       int[] x = new int[3];
       int[] y = new int[3];
       for(int i = 0; i < 3; i++) {
           x[i] = nextInt();
           y[i] = nextInt();
       }
       
       int count = 0;
       for(int i = 0; i < 3; i++)
            for(int j = i + 1; j < 3; j++){
                int now = ((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j]));
                if(now <= r * r)count++;
            }
            
        if(count >= 2) return "yes";
        else return "no";
    }
    
    
    
}