import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static int[] fin = new int[100];
	public static int[] count = new int[100];
	public static int finIndex = 0;
	public static int counter = 0;

	public static void main(String[] args) throws IOException {
		Scanner br = new Scanner(System.in);
		int n = br.nextInt();
		for (int i = 0; i < n; i++) {
			counter = 0;
			palindromeCheck(br.nextInt());
		}
		for (int i = 0; i < n; i++) {
			System.out.println(count[i] + " " + fin[i]);
		}
	}

	private static int palindromeCheck(int i) {
		int temp = i;
		if (temp == reverse(i)) {
			fin[finIndex] = temp;
			count[finIndex] = counter;
			finIndex++;
		} else {
			counter++;
			palindromeConvert(i);
		}
		return 0;
	}

	private static void palindromeConvert(int i) {
		palindromeCheck(i + reverse(i));
	}

	private static int reverse(int i) {
		int reverse = 0;
		while (i != 0) {
			reverse = reverse * 10;
			reverse = reverse + i % 10;
			i = i / 10;
		}
		return reverse;
	}
}