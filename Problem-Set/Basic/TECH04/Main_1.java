public class Main_1
{
    public static void main(String args[])throws java.lang.Exception
    {
        java.io.BufferedReader input=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        java.io.PrintWriter out=new java.io.PrintWriter(System.out);
        int t=Integer.parseInt(input.readLine());
        for(int i=0;i<t;i++)
        {
            java.util.StringTokenizer st=new java.util.StringTokenizer(input.readLine()," ");
            boolean found=check(st.nextToken(),st.nextToken());
            if(found)
                out.println("YES");
            else
                out.println("NO");
        }
        out.flush();
    }
    public static boolean check(String a,String b)
    {
        char ch[]=a.toCharArray();
        char ch1[]=b.toCharArray();
        java.util.Arrays.sort(ch);
        java.util.Arrays.sort(ch1);
        int length=ch.length,length1=ch1.length;
        if(length!=length1)
            return false;
        for(int i=0;i<length;i++)
            if(ch[i]!=ch1[i])
                return false;
        return true;
    }
}