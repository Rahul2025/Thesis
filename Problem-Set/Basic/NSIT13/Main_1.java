import java.io.*;
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

          for(int i=0;i<10;i++)
          {
              boolean chk[]=new boolean[42];
              for(int j=0;j<10;j++)
              {
                chk[p.nextInt()%42]=true;
              }
              int tmp=0;
              for(int j=0;j<42;j++)
                  if(chk[j])tmp++;
              System.out.println(tmp);

          }
          
        }
        catch(Exception e)
        {}
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