import java.io.IOException;


public class Main_1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		CustomReader cr = new CustomReader(1000000);
		StringBuilder output = new StringBuilder();
		int N1 = cr.nextInt(), N2 = cr.nextInt(), N3 = cr.nextInt();
		int[] votersIdList1 = new int[N1];
		int[] votersIdList2 = new int[N2];
		int[] votersIdList3 = new int[N3];
		int listIndex1 = 0, listIndex2 = 0, listIndex3 = 0;
		int currId, currIdCount, idCount = 0;
		boolean isCurrIdInList1, isCurrIdInList2; 
		for (int i = 0; i < N1; i++) {
			votersIdList1[i] = cr.nextInt();
		}
		for (int i = 0; i < N2; i++) {
			votersIdList2[i] = cr.nextInt();
		}
		for (int i = 0; i < N3; i++) {
			votersIdList3[i] = cr.nextInt();
		}
		while ((listIndex1 < N1 && listIndex1 < N2)
				|| (listIndex2 < N2 && listIndex3 < N3) 
				|| (listIndex1 < N1 && listIndex3 < N3)) {
			currId = -1;
			currIdCount = 0;
			isCurrIdInList1 = isCurrIdInList2 = false;
			if (listIndex1 < N1) {
				currId = votersIdList1[listIndex1++];
				currIdCount++;
				isCurrIdInList1 = true;
			}
			if (listIndex2 < N2) {
				if (isCurrIdInList1) {
					if (currId == votersIdList2[listIndex2]) {
						currIdCount++;
						listIndex2++;
						isCurrIdInList2 = true;
					}
					else if (currId > votersIdList2[listIndex2]) {
						currId = votersIdList2[listIndex2++];
						isCurrIdInList2 = true;
						isCurrIdInList1 = false;
						listIndex1--;
					}
				}
				else {
					currId = votersIdList2[listIndex2++];
					currIdCount++;
					isCurrIdInList2 = true;
				}
			}
			if (listIndex3 < N3) {
				if (isCurrIdInList1 || isCurrIdInList2) {
					if (currId == votersIdList3[listIndex3]) {
						currIdCount++;
						listIndex3++;
					}
					else if (currId > votersIdList3[listIndex3]) {
						currId = votersIdList3[listIndex3++];
						currIdCount = 1;
						if (isCurrIdInList1) {
							listIndex1--;
						}
						if (isCurrIdInList2) {
							listIndex2--;
						}
					}
				}
			}
			if (currIdCount > 1) {
				idCount++;
				output.append(currId).append("\n");
			}
		}
		output.insert(0, "\n").insert(0, idCount);
		System.out.print(output.toString());
	}

	private static class CustomReader {
		byte[] buffer;
		int currIndex;
		int validBytesInBuffer;
		CustomReader(int buffSize) {
			buffer = new byte[buffSize];
		}
		
		public int nextInt() throws IOException {
			int value;
			byte b;
			while (true) {
				b = getNextByte();
				if (b > 47 && b < 58) {
					break;
				}
			}
			value = b - 48;
			while (true) {
				b = getNextByte();
				if (b > 47 && b < 58) {
					value = (value * 10) + (b - 48);
				}
				else {
					break;
				}
			}
			return value;
		}
		
		private byte getNextByte() throws IOException {
			if (currIndex == buffer.length
					|| currIndex == validBytesInBuffer) {
				validBytesInBuffer = System.in.read(buffer);
				currIndex = 0;	
			}
			return buffer[currIndex++];
		}
	}
}