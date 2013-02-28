/**
 *
 * @author Mohit Sehgal
 */ 
import java.io.*;
class Main {
    public static void main(String ...args) throws IOException
    {
             // MyReader mr=new MyReader();
              PrintWriter pw=new PrintWriter(System.out);
              BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
              int n=Integer.parseInt(br.readLine());
              int index=0;
              String str;
              while(n--!=0)
              {
                  int p,s;
                  str = br.readLine();
                  index = str.indexOf(" ");
                    p = Integer.parseInt(str.substring(0, index));
                    s = Integer.parseInt(str.substring(index+1));
                  float h=(float) ((p - Math.sqrt(p * p - 24 * s)) / 12);
                  float V=(s/2 - ((p*h)/4) + (h*h) )*h;
                  pw.printf("%.2f", V);
                  pw.println();
              }
              pw.flush();
              pw.close();
    }
   
}
class MyReader
{
    public BufferedInputStream is=new BufferedInputStream(System.in);
    String readNext() throws IOException
    {
        String s=null;
        char c=(char) is.read();
        while(c==' '||c=='\n')
        {
           c=(char) is.read();
        }
        s=Character.toString(c);
        while(c != ' '&&c!='\n')
        {
            c=(char) is.read();
            s=s+Character.toString(c);
        }
            return s.trim();
    }
    int nextInt() throws IOException
    {
       return Integer.parseInt(readNext());
    }
}