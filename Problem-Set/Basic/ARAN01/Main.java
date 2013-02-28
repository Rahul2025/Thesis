import java.io.*;
 
public class Main
{
    public static void main(String[] args) throws IOException
    {
        DataInputStream baca = new DataInputStream(System.in);
        BufferedWriter cetak = new BufferedWriter(new OutputStreamWriter(System.out));
        int cases = Integer.parseInt(baca.readLine());
        int k = 0;
        while(k < cases) {
            String str = baca.readLine();
            int hasil = (int) str.charAt(0);
            for(int i = 1 ; i < str.length(); i++) {
                hasil += str.charAt(i);
            }
            cetak.write((char) (hasil/str.length()) + "\n");
            k++;
        }   
        cetak.flush();
    }
}
 