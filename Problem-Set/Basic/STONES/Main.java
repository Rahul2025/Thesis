import java.io.*;
import java.util.*;
class Main {
 
    public static void main(String[] args)  throws IOException
    { 
        new Main().solve();
    }
    void solve() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps = new PrintStream(System.out,true);
        StringTokenizer st;
        StringBuilder ans = new StringBuilder("");
        String J,S;
        char[] charactersInJ,charactersInS;
        boolean v[];
        int t = Integer.parseInt(br.readLine()),lengthOfJ,lengthOfS,count;
        while(t-->0)
        {
            v = new boolean[52];
            J = br.readLine();
            charactersInJ = J.toCharArray();
            lengthOfJ = J.length();
            for(int i=0;i<lengthOfJ;i++){
                if(charactersInJ[i]>='a')
                    v[charactersInJ[i]-'a'] = true;
                else 
                    v[26+charactersInJ[i]-'A'] = true;
            }                
            S = br.readLine();
            charactersInS = S.toCharArray();
            count=0;
            lengthOfS = S.length();
            for(int i=0;i<lengthOfS;i++){
                if(charactersInS[i]>='a'){
                    if(v[charactersInS[i]-'a'])
                        ++count;
                }
                else {
                    if(v[26+charactersInS[i]-'A'])
                        ++count;
                }
            }
            ans.append(count).append("\n");
        }
        ps.println(ans);
    }
}
 