/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Saransh
 */
import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;
public class Main_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try
        {
          Parserdoubt p=new Parserdoubt(System.in);
          int t=p.nextInt();
          StringBuffer sb=new StringBuffer();
          while(t-->0)
          {
              int a=p.nextInt();
              int b=p.nextInt();
              int c=p.nextInt();
              sb.append(find(a,b,c)+"\n");
          }
          System.out.print(sb.toString());
        }
        catch(Exception e)
        {}
    }
    public static int find(int a,int b,int c)
    {
        if(c>a&&c>b)
            return -1;
        if(c==0)
            return 0;
        if(c==a||c==b)
            return 1;
        if(c%gcd(a,b)!=0)
            return -1;
        int a1=find1(a,b,c);
        int b1=find1(b,a,c);
        if(a1<b1)
            return a1;
        return b1;
    }
    public static int gcd(int a,int b)
    {
        if(a%b==0)
            return b;
         return gcd(b,a%b);
    }
    public static int find1(int a,int b,int c)
    {
        int move=1;
        int counta=a;
        int countb=0;
        boolean flag=false;
        while(true)
        {
            if(countb==c||counta==c)
                break;
            move++;
            if(counta==0)
                counta=a;
            else if(countb==b)
                countb=0;
            else if(counta>b-countb)
            {
                    counta-=b-countb;
                    countb=b;
            }
            else if(counta<=b-countb)
            {
                    countb+=counta;
                    counta=0;

            }
            else
            {
                if(counta==0&&countb==0)
                {
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)
            return move;
        return -1;
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