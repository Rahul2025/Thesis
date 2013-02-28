import java.util.*;
import java.math.*;
import java.io.*;
import java.text.*;
import java.util.regex.*;
import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;

public class Main{

  public int noOnes(int a){

    int ones = 0;
    while(a>0){
      if(a%2==1) ones++;
      a/=2;
    }
    return ones;
  }

  public int maxor(int N, int a, int b){

    int zeros = noOnes(a) + noOnes(b) - N;

    zeros = (zeros>0)?zeros:-zeros;

    int ans = 0;

    for(int i=zeros;i<N;i++)
      ans += Math.pow(2,i);
    return ans;

  }

  public static void main(String[] args){

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    try{

      int cases = Integer.parseInt(br.readLine());
      while(cases>0){
          String[] l = br.readLine().split(" ");
          int N = Integer.parseInt(l[0]);
          int a = Integer.parseInt(l[1]);
          int b = Integer.parseInt(l[2]);
          System.out.println(new Main().maxor(N, a, b));
          cases--;
      }

    }
    catch(Exception ex){}


  }

}