import java.io.*;
import java.util.*;
import java.lang.Math.*;
public class Main_1
{
     public static void main(String args[])throws Exception
     {
         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
         PrintWriter pw = new PrintWriter(System.out);
         StringTokenizer st;
         String s=br.readLine();
         st=new StringTokenizer(s);
         int n=Integer.parseInt(st.nextToken());
         int k=Integer.parseInt(st.nextToken());
         int count=0;
         boolean b[]=new boolean[n];
         
         while(k>0)
         {
             k--;
             String str=br.readLine();
             if(str.equals("CLOSEALL"))
             {
                 b=new boolean[n];
                 count=0;
                }
             else
             {
                 int val=Integer.parseInt(str.substring(6));
                 val--;
                 if(b[val])
                 {
                 b[val]=false;
                 count--;
                 }
                 
                 else
                 {
                     b[val]=true;
                     count++;
                    }
             }
             pw.println(count);
            }
            pw.flush();
     }
}