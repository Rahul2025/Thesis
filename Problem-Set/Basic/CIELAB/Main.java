/**
 *
 * @author Mohit Sehgal
 */ 
import java.io.*;
class Main {
    public static void main(String ...args) throws IOException
    {
              MyReader mr=new MyReader();
              PrintWriter pw=new PrintWriter(System.out);
              int n=mr.nextInt();int m=mr.nextInt();
              int ans=n-m;
              int l=ans%10;
              if(l<9)
                  pw.println(++ans);
              else
                  pw.println(--ans);
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