/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Saransh
 */
import java.io.*;
import java.math.*;

public class Main_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        StringBuffer sb=new StringBuffer();
        try
        {
            //StringBuffer sb=new StringBuffer();
            Parserdoubt p=new Parserdoubt(System.in);
            int m=p.nextInt();
            int arr[]=new int[m];
            boolean marked[]=new boolean[m];
            for(int i=0;i<arr.length;i++)
                arr[i]=p.nextInt();
            int t=0;
            for(int k=0;k<arr.length;k++)
            {
                if(marked[k])continue;
                marked[k]=true;
                int chk=k;
                while(true)
                {

                  sb.append((chk+1)+" ");
                    marked[chk]=true;
                    chk=arr[chk]-1;
                    if(marked[chk])
                    {
                        t++;
                        sb.append((chk+1)+"\n");
                        break;
                    }
                }

            }
            System.out.println(t);
            System.out.print(sb.toString());
        }catch(Exception e){}

    }

}


class Parserdoubt
	{
	   final private int BUFFER_SIZE = 1 << 16;

	   private DataInputStream din;
	   private byte[] buffer;
	   private int bufferPointer, bytesRead;

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
	   public Parserdoubt(InputStream in)
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
	      if (neg) return -ret;
	      return ret;
	   }private void fillBuffer() throws Exception
	   {bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);if (bytesRead == -1) buffer[0] = -1;
	   }private byte read() throws Exception
	   {
	      if (bufferPointer == bytesRead) fillBuffer();
	      return buffer[bufferPointer++];
	   }}