import java.io.*;
public class Main_1
{
    public static void main(String[] args)
    {
        try
        {
            ParserLose p=new ParserLose(System.in);
            int t=p.nextInt();
            while(t-->0)
            {
                int k=p.nextInt();
                int m=p.nextInt();
                if(k==m)
                    System.out.println(1);
                else
                    find(k-m,m);
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    public static void find(int n,int r)
    {
        long top=n+r-1;
        long bottom=r-1;
        if(bottom>(top-bottom))
            bottom=top-bottom;
        long ans=1;
        for(long i=1;i<=bottom;i++)
            ans=(ans*top--)/i;
        System.out.println(ans);
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