/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Saransh
 */
import java.io.*;
import java.util.*;

class Point implements Comparable<Point>
{
    int x,y;
    public Point(int x,int y)
    {
        this.x=x;
        this.y=y;
    }
    public int compareTo(Point t)
    {
        if(t.x>x)
            return 1;
        if(t.x<x)
            return -1;
        if(t.y<y)
            return 1;
        return -1;
    }
    public double distance(Point p)
    {
        double dist=(p.x-x)*(p.x-x)+(p.y-y)*(p.y-y);
        return Math.sqrt(dist);
    }
}
public class Main_1 {

   
    public static void main(String[] args) {
        // TODO code application logic here
        try
        {
            Parserdoubt pd=new Parserdoubt(System.in);
            int t=pd.nextInt();
            while(t-->0)
            {
                int p=pd.nextInt();
                Point points[]=new Point[p];
                for(int i=0;i<p;i++)
                    points[i]=new Point(pd.nextInt(),pd.nextInt());
                Arrays.sort(points);
                int s=0;
                double dist=0;
                for(int i=1;i<p;i++)
                {
                    dist+=points[i].distance(points[s]);
                    s=i;
                }
                System.out.printf("%.2f\n",dist);
            }
        }
        catch(Exception e)
        {}

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
	   public long nextLong() throws Exception
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