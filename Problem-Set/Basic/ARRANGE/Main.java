import java.io.DataInputStream;
import java.io.InputStream;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args) throws Exception 
    {
        Parser p1=new Parser(System.in);
        PrintWriter p2=new PrintWriter(System.out,true);
        int x=p1.nextInt();
        while(x-->0)
        {
            int n=p1.nextInt();
            String a=p1.nextString();
            char ans[]=new char[a.length()];
            
            for(int i=0;i<a.length();i++)
            {
                char c=a.charAt(i);
                String temp=Integer.toBinaryString(i);
                while(temp.length()<n)
                    temp="0"+temp;
                temp=new StringBuffer(temp).reverse()+"";
                int j=(Integer.parseInt(temp+"", 2));
                ans[j]=c;
            }
            p2.println(new String(ans));
        }
        p2.flush();
        p2.close();
    }
}
class Parser
{ 
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead; 
    public Parser(InputStream in)
    {
        din = new DataInputStream(in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
    public int nextInt() throws Exception
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = c == '-';
        if (neg) c = read();
        do
        {
            ret = ret * 10 + c - '0';
            c = read();
        } while (c > ' ');
        if (neg) 
            return -ret;
        return ret;
    }
    private void fillBuffer() throws Exception
    {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) 
            buffer[0] = -1;
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
    private byte read() throws Exception
    {   
        if (bufferPointer == bytesRead) 
            fillBuffer();
        return buffer[bufferPointer++];
    }
} 