import java.io.BufferedReader;
import java.io.InputStreamReader;

class HolesInTheText {
    public static void main(String ...args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        String str = "";
        for(int i=0; i<t; i++) {
            str = str + getHoles(br.readLine().trim()) + "\n";
        }
        System.out.println(str.trim());
    }

    private static int getHoles(String s) {
        int h = 0;
        for(int i=0; i<s.length(); i++){
            String ss = s.substring(i, i+1);
            if(ss.matches("A|D|O|P|R|Q"))
                h++;
            else if(ss.matches("B"))
                h=h+2;
        }
        return h;
    }
}