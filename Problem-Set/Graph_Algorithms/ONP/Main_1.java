import java.io.IOException;

/**
 * <b>Description</b>
 * The purpose of this problem is to verify whether the method you are using to
 * read input data is sufficiently fast to handle problems branded with the
 * enormous Input/Output warning. You are expected to be able to process at
 * least 2.5MB of input data per second at runtime.
 * <p>
 * <b>Input</b>
 * The input begins with two positive integers n k (n, k<=107). The
 * next n lines of input contain one positive integer ti, not greater than 109,
 * each.
 * <p>
 * <b>Output</b>
 * Write a single integer to output, denoting how many integers ti
 * are divisible by k.
 * 
 * @author Arnauld Van Muysewinkel
 */
public class Main_1 { // MainOnp

  private static final char NL = '\n';
  private static final char OPEN = '(';
  private static final char CLOSE = ')';
  private static final String OPERATORS = "+-*/^";
  private static final int EOF = -1;


  /**
   * @param args
   * @throws IOException
   * @throws NumberFormatException
   */
  public static void main(String[] args)
      throws NumberFormatException, IOException {
    int num = readInt();
    char[] operators = new char[80];
    for (int idx = 0; idx < num; idx++) {
      int depth = 0;
      parse: while (true) {
        int token = readToken();
        if ((EOF==token) || (NL==token)) break parse;
        if (OPEN==token) {
          depth++;
        } else if (token==CLOSE) {
          System.out.write(operators[depth--]);
        } else if (0<=OPERATORS.indexOf(token)) {
          operators[depth] = (char) token;
        } else {
          System.out.write((char) token);
        }
      }
      System.out.write(NL);
    }
  }

  static byte[] buffer = new byte[102400];
  static int curIdx = -1;
  static int len = -1;
  private static int readToken() throws IOException {
    while (true) {
      // getchar
      if (curIdx>=len) {
        len = System.in.read(buffer);
        if (len<0) return EOF; // EOF
        curIdx = 0;
      }
      int chr = (int) buffer[curIdx++];

      if ((chr == OPEN) || (chr == CLOSE) || (chr == NL) || (0<=OPERATORS.indexOf(chr))) return chr;
      if ((chr >= 'a') && (chr <='z')) return chr;
      // Ignore unsupported characters
    }
  }
  private static int readInt() throws IOException {
    int result = EOF;
    while (true) {
      // getchar
      if (curIdx>=len) {
        len = System.in.read(buffer);
        if (len<0) return result; // EOF
        curIdx = 0;
      }
      int chr = (int) buffer[curIdx++];

      if (chr == NL) return result;
      // Assume input is correct => we got only figures
      if (EOF==result) result = (chr - '0');
        else result = result * 10 + (chr - '0');
    }
  }

}