import java.io.*;
import java.math.*;
/**
 *
 * @author Saransh
 */
public class Main_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try
        {
          ParserLose p=new ParserLose(System.in);
          //StringBuffer sb=new StringBuffer(6000000);
          int t=p.nextInt();
          int l=0;
          boolean once=false;
          int winner=0;
          int tlg=0;
          while(t-->0)
          {
            l+=p.nextInt()-p.nextInt();
            if(!once)
            {
                once=true;
                if(l>0)
                {
                    tlg=l;
                    winner=1;
                }
                else if(l<0)
                {
                    tlg=-l;
                    winner=2;
                }

            }
            else
            {
                if(l>0)
                {
                    if(l>tlg)
                    {
                        tlg=l;
                        winner=1;
                    }
                }
                else if(l<0)
                {
                    if(-l>tlg)
                    {
                        tlg=-l;
                        winner=2;
                    }
                }
            }
          }
          System.out.println(winner+" "+tlg);
          
        }
        catch(Exception e)
        {}
    }
    public static boolean isprime1(int i)
    {
        String str=i+"";
        BigInteger b=new BigInteger(str);
        return b.isProbablePrime(1);
    }
    static int t=0;
    public static void find(int m)
    {
        
        if(m==1||isprime(m))
        {
            t++;
            return;
        }
        for(int i=2;i<=Math.sqrt(m);i++)
            if(m%i==0)
                find(m/i);

    }
    public static boolean isprime(int a)
    {
        if(a<3)
            return a==2;
        for(int i=2;i<=Math.sqrt(a);i++)
            if(a%i==0)
                return false;
        return true;
    }
    public static int rev(int a)
    {
        String str=a+"";
        String tmp="";
        for(int i=str.length()-1;i>=0;i--)
            tmp+=str.charAt(i);
        return Integer.parseInt(tmp);
    }

}
class ParserLose
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer,bytesRead;
    public ParserLose(InputStream in)
    {
        din=new DataInputStream (in);
        buffer=new byte[BUFFER_SIZE];
        bufferPointer=bytesRead=0;
    }
    public String nextString() throws Exception
	   {
		   StringBuffer sb=new StringBuffer("");
		   byte c = read();
		   while (c <= ' ') c = read();
		   do
		   {
			   sb.append((char)c);
			   c=read();
		   }while(c>' ');
		   return sb.toString();
	   }
    public int nextInt() throws Exception
    {
        int ret=0;
        byte c =read();
        while(c<=' ')c=read();
        do{
            ret=ret*10+(c-'0');
            c=read();
        }while(c>' ');

        return ret;
    }
    private byte read() throws Exception
    {
        if(bufferPointer==bytesRead)fillBuffer();
        return buffer[bufferPointer++];
    }
    private void fillBuffer() throws Exception
    {
        bytesRead=din.read(buffer,bufferPointer=0,BUFFER_SIZE);
        if(bytesRead==-1)buffer[0]=-1;
    }
    public char nextChar() throws Exception
    {
        byte c=read();
        while(c<=' ') c= read();
            return (char)c;
    }
}