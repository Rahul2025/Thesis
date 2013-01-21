import java.io.*;
class Main_1
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        double p,s,a,b,v;
        String in[];
        while(t>0)
        {
            in=br.readLine().split(" ");
            p=Double.parseDouble(in[0]);
            s=Double.parseDouble(in[1]);
            b=solveQuadratic(-6,p,-s);
            a=(p-8*b)/4;
            v=a*b*b;
            System.out.printf("%.2f%n",(double)Math.round(v*100)/100);
            t--;
        }


    }
    public static double solveQuadratic(double a,double b,double c)
    {   double root=0;
        double D=b*b-4*a*c;
        if(D==0)
            root= (-b/2*a);
        else if(D>0)
            root= ((-b+Math.sqrt(D))/(2*a));
        return root;
    }
}