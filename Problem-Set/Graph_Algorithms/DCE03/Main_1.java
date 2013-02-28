public class Main_1 {
    static int MOD = 10000 ;
    static long [] T = new long [1001] ;
    static long mod (long num) {
        return num - num / MOD * MOD ;
    }
    static long comp (int N) {
        if (N == 1 || N == 2)
            return 1 ;
        long sum = 0 ;
        if ((N & 1) == 0){//N is even
            for (int i = 2 ; i <= (N - 2) / 2 ; i++)
                sum += (T[i] * T[N - i]) ;
            sum = sum * 2 + T[N / 2] * T[N / 2] ;
        }else {
            for (int i = 2 ; i <= N / 2 ; i++)
                sum += (T[i] * T[N - i]) ;
            sum *= 2 ;
        }
        return T[N] = mod(sum + 2 * T[N - 1]) ;
    }
    public static void main (String args []) throws java.io.IOException {
        java.io.BufferedReader read = new java.io.BufferedReader(new java.io.InputStreamReader(System.in)) ;
        java.io.PrintWriter out = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out),true) ;
        T[1] = T[2] = 1 ;
	for (int i = 3 ; i < 1001 ; i++)
	comp(i) ;
	int testCase = Integer.parseInt(read.readLine()) ;
	while (testCase-- != 0) {
	out.println(T[Integer.parseInt(read.readLine())]) ;
	}
        out.close() ;
    }
}