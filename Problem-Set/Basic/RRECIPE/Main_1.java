import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main_1 {
	// http://www.codechef.com/COOK26/problems/RRECIPE
	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		// TODO Auto-generated method stub
		BufferedReader Breader = new BufferedReader(new InputStreamReader(
				System.in));
		int i, j, n, flag, ans, len, last, first, limit, mod = 10000009;
		String str;
		n = Integer.parseInt(Breader.readLine());
		for (i = 0; i < n; i++) {
			flag = 0;
			ans = 1;
			str = Breader.readLine();
			len = str.length();
			limit = (len % 2 == 0) ? (len / 2) : (len / 2) + 1;
			if (len == 1)
				limit = 1;
			// System.out.println(len + "-------  " + limit);
			for (j = 0; j < limit; j++) {
				last = str.charAt(len - j - 1);
				first = str.charAt(j);
				if (first != 63 && last != 63 && first != last) {
					flag = 1;
					break;
				}
				if (first == 63) {
					// System.out.println(last + " " + first);
					if (last == 63) {
						ans = (ans * 26) % mod;
					} else
						ans *= 1;
				}
			}
			if (flag == 1)
				System.out.println("0");
			else
				System.out.println(ans % mod);
		}
	}
}