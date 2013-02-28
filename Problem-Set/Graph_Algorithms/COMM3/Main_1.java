import java.io.*;
import java.util.*;
public class Main_1
{
    public static void main(String args[])throws Exception
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(in.readLine());
        StringBuffer out=new StringBuffer("");
        StringTokenizer s1,s2,s3;
        for(int i=1;i<=t;i++)
        {
            int R=Integer.parseInt(in.readLine());
            s1=new StringTokenizer(in.readLine());
            s2=new StringTokenizer(in.readLine());
            s3=new StringTokenizer(in.readLine());
            int ar[][]=new int[3][2];
            ar[0][0]=Integer.parseInt(s1.nextToken());
            ar[0][1]=Integer.parseInt(s1.nextToken());
            ar[1][0]=Integer.parseInt(s2.nextToken());
            ar[1][1]=Integer.parseInt(s2.nextToken());
            ar[2][0]=Integer.parseInt(s3.nextToken());
            ar[2][1]=Integer.parseInt(s3.nextToken());
            double d1=Math.sqrt((ar[1][0]-ar[0][0])*(ar[1][0]-ar[0][0])+(ar[1][1]-ar[0][1])*(ar[1][1]-ar[0][1]));
            double d2=Math.sqrt((ar[2][0]-ar[0][0])*(ar[2][0]-ar[0][0])+(ar[2][1]-ar[0][1])*(ar[2][1]-ar[0][1]));
            double d3=Math.sqrt((ar[2][0]-ar[1][0])*(ar[2][0]-ar[1][0])+(ar[2][1]-ar[1][1])*(ar[2][1]-ar[1][1]));
            if((d1<=R && d2<=R)||(d2<=R && d3<=R)||(d1<=R && d3<=R))
            out.append("yes\n");
            else
            out.append("no\n");
        }
        System.out.println(out);
    }
}
 