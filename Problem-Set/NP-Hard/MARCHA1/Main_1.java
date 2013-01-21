import java.io.*;
public class Main_1
{
    static boolean marked[];
    static boolean dict[];
    public static void main(String[] args)
    {


        try
        {
            Parserdoubt p=new Parserdoubt(System.in);
            long c=p.nextInt();
            double log2=Math.log(2);
            StringBuffer sb=new StringBuffer(600000);
            while(c-->0)
            {
                boolean f=false;
                long t=p.nextInt();
                long k=p.nextInt();
                //System.out.println(t+" "+k);
                long arr[]=new long[(int)t];
                if(k<=0||k>20000)
                {
                    f=true;
                    sb.append("No\n");
                }
                int m=0;
                while(t-->0)
                {
                    arr[m++]=p.nextInt();
                }
                if(!f)
                    sb.append(find(k,arr)+"\n");
            }
            System.out.print(sb.toString());
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    public static String find(long a,long p[])
    {
        if(a>20000)
            return ("No");
        dict=new boolean[(int)a+1];
        marked=new boolean[(int)a+1];
        check((int)a,p);
        if(dict[(int)a])
            return ("Yes");
        return
            ("No");
    }
    public static boolean check(long a,long p[])
    {
        if(a<0)
            return false;
        if(a==0)
        {
            return true;
        }
        if(marked[(int)a])
            return dict[(int)a];
        boolean result=false;
        for(int i=0;i<p.length;i++)
        {
            long tmp[]=new long[p.length-1];
            int k=0;
            for(int j=0;j<p.length;j++)
            {
                if(i!=j)
                    tmp[k++]=p[j];
            }
            result=result||check(a-p[i],tmp);
        }
        marked[(int)a]=true;
        dict[(int)a]=result;
        return result;

    }
}
class Parserdoubt
	{
	   final private int BUFFER_SIZE = 1 << 17;

	   private DataInputStream din;
	   private byte[] buffer;
	   private int bufferPointer, bytesRead;

	   public Parserdoubt(InputStream in)
	   {
	      din = new DataInputStream(in);
	      buffer = new byte[BUFFER_SIZE];
	      bufferPointer = bytesRead = 0;
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
	   public char nextChar() throws Exception
	   {
		   byte c=read();
		   while(c<=' ') c= read();
		   return (char)c;
	   }
	   public long nextInt() throws Exception
	   {
	      long ret = 0;
	      byte c = read();
	      while (c <= ' ') c = read();
	      boolean neg = c == '-';
	      if (neg) c = read();
	      do
	      {
	    	  ret = ret * 10 + c - '0';
	         c = read();
	      } while (c > ' ');
	      if (neg) return -ret;
	      return ret;
	   }


	   private void fillBuffer() throws Exception
	   {
	      bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	      if (bytesRead == -1) buffer[0] = -1;
	   }

	   private byte read() throws Exception
	   {
	      if (bufferPointer == bytesRead) fillBuffer();
	      return buffer[bufferPointer++];
	   }
	}
