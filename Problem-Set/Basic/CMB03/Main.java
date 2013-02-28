import java.util.Scanner;
class Main
{
    public static void main(String args[])throws Exception
    {
        Scanner in=new Scanner(System.in);
        int t,i,j;
        t=in.nextInt();
        String str,sub;
        while(t-->0)
        {
            str=in.next();
            sub=in.next();
            j=0;
            for(i=0;i<(str.length()-sub.length());i++)
            {
               // j=0;
                if(str.substring(i,(i+sub.length())).equalsIgnoreCase(sub))
                {
                    j=1;
                    break;
                }
            }
            if(j==1)
                System.out.println("1");
            else 
                System.out.println("0");
        }
    }
    
}