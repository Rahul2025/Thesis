import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());
		int l;
		StringBuilder sb = new StringBuilder();
		for (int t = 0; t < T; t++) {
			l = Integer.parseInt(br.readLine());
			if (l % 2 == 0) {
				sb.append(l);
			} else {
				sb.append(l - 1);
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());

	}

}