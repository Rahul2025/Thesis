import java.io.DataInputStream;
import java.io.InputStream;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args) throws Exception 
    {
        Parser p1=new Parser(System.in);
        PrintWriter p=new PrintWriter(System.out,true);
        int x=0;
        while((x=p1.nextInt())!=0)
        {
            int c=0;
            int n[]=new int[x];
            for(int i=0;i<x;i++)
            {
                n[i]=p1.nextInt();
            }
            java.util.Arrays.sort(n);
            for(int i=0;i<n.length-2;i++)
            {
                for(int j=i+1;j<n.length-1;j++)
                {
                    if(n[i]+n[j]<n[n.length-1])
                    {
                        int t=0;
                        if((t=isTriangle(n,n[i]+n[j],j+1,n.length-1))!=-1)
                        c+=(n.length-t);
                    }
                }
            }
            p.println(c);
        }
        p.flush();
        p.close();
    }
    public static int isTriangle(int l[],int b, int i, int j)
    {
        if (j < i)
            return -1;
        int mid = (int)(j + i)/2;
        if (l[mid-1] > b)
            return isTriangle(l, b, i, mid-1);
        else if (l[mid] <= b)
            return isTriangle(l, b, mid+1,j);
        else
            return mid;
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