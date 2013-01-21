import java.io.*;

class Main
{
public static void main(String args[]) throws IOException
    {
    BufferedReader r=new BufferedReader( new InputStreamReader(System.in));
    int n=Integer.parseInt(r.readLine());
    for(int q=0;q<n;q++)
    {
        int v=1;        //initial value
        String str=r.readLine();
        //boolean touched=false;
        int s=0,e=str.length()-1;  //start and end

        while(true)
        {

        if(str.charAt(s)=='?' && str.charAt(e)=='?')
        {
            v=(v*26)%10000009;
           // touched=true;
        }

        else
        if((s!=e) && ((str.charAt(s)=='?') || (str.charAt(e)=='?')))
        {
        v=v*1%10000009;
        //touched=true;
        }

        if((str.charAt(s)!='?') && (str.charAt(e)!='?') && (str.charAt(s)!=str.charAt(e) ))
        {
            System.out.println(0);
            break;
        }

        if((s==e) && (str.length()%2!=0))   //odd length
        {
            //if(touched==true)
            
                System.out.println(v);
           // else
           //     System.out.println(1);
            break;
        }

        if((e-s)==1 && (str.length()%2==0))   //even length
        {
            //if(touched==true)
            
                System.out.println(v);
            //else
            //    System.out.println(1);
            break;
        }
        s++;
        e--;
        continue;
        }
    }
    }
}