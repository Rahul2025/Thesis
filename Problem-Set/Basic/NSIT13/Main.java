import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

public class Main{
    private final InputStream inputStream;
    private final int MOD_VALUE = 42;
    private final int BUCKET_COUNT = 10;


    public Main(InputStream inputStream) {
        this.inputStream = inputStream;
    }

    public void run() throws Exception {
        Collection<Integer> bucket = new ArrayList<Integer>(BUCKET_COUNT);
        String line;
        // note - don't close reader, because it causes the online judge to produce a NZEC error
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        PrintWriter writer = new PrintWriter(System.out);
        
        while ((line = reader.readLine()) != null ){
            int testCase = Integer.parseInt(line);
            bucket.add(testCase);
            if (bucket.size() == BUCKET_COUNT){
                writer.println( getUniqueModCount(bucket) );
                bucket.clear();
            }
        }

        // flush and write results to standard out
        writer.close();
    }


    private int getUniqueModCount(Collection<Integer> bucket){
        Set<Integer> uniqueMods = new HashSet<Integer>();
        for(Integer testCase : bucket){
            uniqueMods.add( testCase % MOD_VALUE  );
        }               
        return uniqueMods.size();
    }
    
    
    /*
     * allow exception to be thrown to VM - so online judge will display a NZEC error
     */
    public static void main(String[] args) throws Exception {
        // the default input stream is "system.in", but can replace this during testing
        InputStream inputStream = System.in;

/*        
        StringBuilder sb = new StringBuilder();
        sb.append("39\n");
        sb.append("40\n");
        sb.append("41\n");
        sb.append("42\n");
        sb.append("43\n");
        sb.append("44\n");
        sb.append("82\n");
        sb.append("83\n");
        sb.append("84\n");
        sb.append("85\n");
        
      inputStream = new java.io.ByteArrayInputStream(sb.toString().getBytes("UTF-8"));
*/

        Main exercise = new Main(inputStream);
        exercise.run();
    }
}