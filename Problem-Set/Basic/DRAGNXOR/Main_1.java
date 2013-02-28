// DRAGNXOR

import java.io.*;

class Main_1 {
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader (new InputStreamReader (System.in));
		int t = Integer.parseInt(input.readLine());
 
		for (int i = 0; i < t; i++) {
			String[] testCase = input.readLine().split(" ");
			int n = Integer.parseInt(testCase[0]);
			int a = Integer.parseInt(testCase[1]);
			int b = Integer.parseInt(testCase[2]);
			int maxXor = 0;
			int bitVal = 1 << (n - 1);

			// Fill starting from most significant bit
			while (a != 0) {
				if (a % 2 == 1) {
					maxXor |= bitVal;
					bitVal /= 2;
				}
				a /= 2;
			}

			while (b != 0 && bitVal != 0) {
				if (b % 2 == 1) {
					maxXor |= bitVal;
					bitVal /= 2;
				}
				b /= 2;
			}

			// Remove starting from least significant bit
			bitVal = 1;
			while (b != 0) {
				if (b % 2 == 1) {
					maxXor ^= bitVal;
					bitVal *= 2;
				}
				b /= 2;
			}

			System.out.println(maxXor);
		}
	}
}