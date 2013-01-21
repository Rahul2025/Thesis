import java.io.DataInputStream;
import java.io.InputStream;

public class Main_1
{
	public static void main(String args[]) throws Exception
	{
		Parser23490 p=new Parser23490(System.in);
		int t=p.nextInt();
		nexttest:
		while(--t>=0)
		{
			int leaves=1;
			int k=p.nextInt();
			int a[]=new int[k];
			for(int i=0;i<k;i++)
				a[i]=p.nextInt();
			for(int i=0;i<k;i++)
			{
				int x=a[i];
				if(x==leaves)
				{
					if(i!=(k-1))
					{
						System.out.println("No");
						continue nexttest;
					}
					else if(i==(k-1))
					{
						System.out.println("Yes");
						continue nexttest;
					}
				}
				else if(x>leaves)
				{
					System.out.println("No");
					continue nexttest;
				}
				leaves=(leaves-x)*2;
			}
				System.out.println("No");
		}
	}
}
class Parser23490
{
   final private int BUFFER_SIZE = 1 << 16;

   private DataInputStream din;
   private byte[] buffer;
   private int bufferPointer, bytesRead;
   
   public Parser23490(InputStream in)
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