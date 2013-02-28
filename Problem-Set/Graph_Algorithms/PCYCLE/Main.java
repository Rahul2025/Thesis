import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine());
        String[] s = br.readLine().split(" ");
        int[] a = new int[x];
        for(int k=0;k<x;k++){
            a[k] = Integer.parseInt(s[k]);
        }
        int i=0,j=0,l=0;
        String str = null;
        String res[] = new String[1000];
        while(j<x){
            i = j;
            str = ""+(j+1);
            while(a[i]!=0){
                str = str + " " + a[i];
                int m = a[i]-1;
                a[i] = 0;
                i = m;
            }
            if(str.contains(" ")){
            res[l++] = str;
            }
            j++;
        }
        int count = -1;
        while(res[++count]!=null);
        System.out.println(count-1);
        for(int m=0;m<count-1;m++){
            System.out.println(res[m]);
        }
    }
}