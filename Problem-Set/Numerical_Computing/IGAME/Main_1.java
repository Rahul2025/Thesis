// IGAME

import java.io.*;
import java.util.*;

class Main_1 {
	public static void main (String[] args) throws Exception {
		BufferedReader input = new BufferedReader (new InputStreamReader (System.in));
		PrintWriter output = new PrintWriter(System.out);
		Set loseSet = new LoseSet(1001);

		int t = Integer.parseInt(input.readLine());

		for (int i = 0; i < t; i++) {
			String[] testCase = input.readLine().split(" ");
			int m = Integer.parseInt(testCase[0]);
			int n = Integer.parseInt(testCase[1]);
			int p = Integer.parseInt(testCase[2]);
			int q = Integer.parseInt(testCase[3]);

			if (loseSet.contains(new LoseCoord(m - p, n - q)))
				output.print("Bob\n");
			else
				output.print("Alice\n");
		}
		output.close();
	}

	// set of first move coords relative to the target that lose
	private static class LoseSet extends HashSet<LoseCoord> {
		private int loseX = 0;
		private int loseY = 0;
		private int maxX = 0;

		public LoseSet(int maxX) {
			this.maxX = maxX;
			List<Boolean> a = new ArrayList<Boolean>();
			a.add(false);
			List<Boolean> b = new ArrayList<Boolean>();
			b.add(true);
			loseX = 2;
			loseY = 1;
			add(new LoseCoord(loseX, loseY));
			extendSet(a, b);
		}

		private void extendSet(List<Boolean> a, List<Boolean> b) {
			for (boolean nextLose : b) {
				if (nextLose) {
					loseX += 3;
					loseY += 2;
				}
				else {
					loseX += 2;
					loseY += 1;
				}
				if (loseX > maxX)
					return;			// break out of recursion
				add(new LoseCoord(loseX, loseY));
			}
			a.addAll(b);
			List<Boolean> newb = new ArrayList<Boolean>(a);
			newb.addAll(b);
			extendSet(a, newb);
		}
	}

	// (x,y) and (y,x) are considered equivalent
	private static class LoseCoord {
		private int c1;
		private int c2;

		public LoseCoord(int x, int y) {
			if (x < y) {
				c1 = x;
				c2 = y;
			}
			else {
				c1 = y;
				c2 = x;
			}
		}

		@Override
		public boolean equals(Object o) {
			return o instanceof LoseCoord && ((LoseCoord)o).c1 == c1 &&
				((LoseCoord)o).c2 == c2;
		}

		@Override
		public int hashCode() {
			int result = 17;
			result = 37 * result + c1;
			result = 37 * result + c2;
			return result;
		}
	}
}