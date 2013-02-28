import java.io.*;
public class Main_1
{
	public static void main(String args[])throws Exception{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int n=Integer.parseInt(br.readLine());
while(n-->0)
System.out.println(gp(Integer.parseInt(br.readLine())));

}
public static int gp(int l){
int r=0,k=0,k1=l+1;
while(true)
{
k=k1;
r=0;
while(k>0)
{r=r*10+k%10;
k=k/10;
}
if(r==k1)
break;
k1=k1+1;
}

return r;
}}