 import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet ;
import java.util.StringTokenizer;
public class Main {

  static  TreeSet <Integer>  list = new TreeSet<Integer>();
    public static void main(String[] args) throws Exception  {
      BufferedReader  reader  = new  BufferedReader
           (   new InputStreamReader ( System.in));
        list.add(2);
        boolean [] array = new boolean [32000] ;
       int i  , p , j ;// counters
       for (  j = 3 ; j < array.length ; j++){
           array[j] = true ;       
       }
       for(  j = 2 ; j < array.length ; j++){
       for(int k = j ; j * k< array.length ; k++)
           array[j*k] = false ;
       }
     for (i = 3 ; i  < array.length ; i+=2){
         if (array[i])
             list.add(i);
        }

      int noOfTc  = Integer.parseInt( reader.readLine());
       for(int t =0 ; t < noOfTc ; t++ ){
            StringTokenizer in = new StringTokenizer(reader.readLine());
        int    number1 =   Integer.parseInt(in.nextToken());
        int   number2 =   Integer.parseInt(in.nextToken());
        boolean first = true ;
     if(  (number2 - number1) <= 100000){
       for( p = number1 ; p <= number2 ; p++){
                if(isPrime(p)){
                    if(first){
                        first = false ;
                        System.out.print(p);
                    }
                    else
                        System.out.print("\n"+p);
                }
     }//end for
     }//end if
     System.out.println(" \n");
 }
	}//end main
     static boolean isPrime(int n){
        if(n<2)
            return false;
       double d = Math.sqrt(n);
        for(Integer x : list){

            if(x>d)
                break;
            if(n%x==0)
                return false;
        }
        return true;
    }
       }
