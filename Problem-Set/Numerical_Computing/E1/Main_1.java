import java.io.*;

/**
 * Created by IntelliJ IDEA.
 * User: jlu
 * Date: 1/18/11
 * Time: 8:03 AM
 * To change this template use File | Settings | File Templates.
 */
public class Main_1 {
    public static int fourMax(int num1, int num2, int num3, int num4) {
        return Math.max(num1, Math.max(num2, Math.max(num3, num4)));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintStream w = new PrintStream(new BufferedOutputStream(System.out));
        System.setOut(w);

        int numTrials = Integer.parseInt(r.readLine());
        int size;
        String sboard;
        int[][] board;
        int start;
        int max;

        while (numTrials-- > 0) {
            size = Integer.parseInt(r.readLine());
            board = new int[size][size+1];
            start = 0;
            max = 0;

            for (int iii = 0; iii < size; iii++) {
                sboard = r.readLine();
                for (int jjj = 1; jjj <= size; jjj++) {
                    if (sboard.charAt(jjj-1) == 'K') {
                        board[iii][jjj] = 1000;
                        start = jjj;
                    } else if (sboard.charAt(jjj-1) == 'P') {
                        board[iii][jjj] = 1;
                    }
                }
            }

            for (int kkk = start + 1; kkk <= size; kkk++) {
                for (int lll = 0; lll < size; lll++) {
                    if (lll == 0) {
                        board[lll][kkk] += fourMax(board[lll + 2][kkk-1], board[lll + 1][kkk- 2], 0, 0);
                    } else if (lll == 1) {
                        board[lll][kkk] += fourMax(board[lll + 2][kkk-1], board[lll + 1][kkk - 2], 0, board[lll - 1][kkk - 2]);
                    } else if (lll == (size - 2)) {
                        board[lll][kkk] += fourMax(0, board[lll + 1][kkk - 2], board[lll - 2][kkk-1], board[lll - 1][kkk - 2]);
                    } else if (lll == (size-1)) {
                        board[lll][kkk] += fourMax(0, 0, board[lll - 2][kkk -1], board[lll - 1][kkk - 2]);
                    } else {
                        board[lll][kkk] += fourMax(board[lll + 2][kkk-1], board[lll + 1][kkk - 2], board[lll - 2][kkk-1], board[lll - 1][kkk - 2]);
                    }
                    if (kkk == (size)) {
                        max = Math.max(max, board[lll][kkk]);
                    }
                }


            }
            System.out.println(max-1000);

        }
        w.close();
    }
}