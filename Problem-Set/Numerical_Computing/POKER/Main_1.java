import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_1 {
	final static String[] rank = {"T","J","Q","K","A"};
	final static int SEQ = 0;
	final static int FOUR = 1;
	final static int THREEAND2 = 2;
	final static int THREE = 3;
	final static int TWOANDTWO = 4;
	final static int TWO = 5;
	final static int NONE = 6;
	
	
	static boolean isSameSuit(String[] hands){
		boolean isSame = true;
		int card_indx = 0;
		char prev = ' ';
		while(isSame && card_indx<5){
			if(hands[card_indx].charAt(1)!=prev&&card_indx>0){
				isSame = false;
			}
			prev = hands[card_indx].charAt(1);
			card_indx++;
		}
		return isSame;
	}
	static int checkPattern(int[] sortedHand){
		int prev = -1, cur =-1;
		boolean seqFlag = true;
		ArrayList<Integer> firstList = new ArrayList();
		ArrayList<Integer> secList = new ArrayList();
		Integer curInt = null, prevInt = null;
		for(int i=0;i<sortedHand.length;i++){
			cur = sortedHand[i];
			
			if(cur==prev){
				//System.out.println("prev: "+prev);
				//System.out.println("cur: "+cur);
				curInt = new Integer(cur);
				prevInt = new Integer(prev);
				if(firstList.isEmpty()){
					firstList.add(curInt);
					firstList.add(prevInt);
				}else{
					if(((Integer)firstList.get(0)).equals(curInt)){
						firstList.add(curInt);
					}else{
						if(secList.isEmpty()){
							secList.add(curInt);
							secList.add(prevInt);
						}else{
							secList.add(curInt);
						}
						
					}
				}	
				seqFlag=false;
			}else if ((prev!=-1)&&seqFlag){
			   if(cur-prev!=1){
		    	   seqFlag = false;
		    	   if((i==sortedHand.length-1)&&(prev==5)){
		    		   if(cur==14){
		    			  seqFlag=true; 
		    		   }
		    	   }
		       }else if (cur-prev==1){
		    	   seqFlag = true;
		       }
			}
			prev = cur;
		}
		if(seqFlag){
			return SEQ;
			
		}else{
			if(!firstList.isEmpty()){
				if(firstList.size()==4){
					return FOUR;
				}else if(firstList.size()==3){
					if(secList.isEmpty()){
						return THREE;
					}else{
						return THREEAND2;
					}
				}else if (firstList.size()==2){
					if(secList.isEmpty()){
						return TWO;
					}else{
						if(secList.size()==2){
							return TWOANDTWO;
						}else if(secList.size()==3){
							return THREEAND2;
						}
					}
				}
			}
			return NONE;
		}
	}
	 static int[] sort(String[] hands){
		int index = 0;
		int cur = -1;
		int[] sorted = new int[hands.length];
		String rankStr = "";
		while(index < hands.length){
			rankStr = hands[index].substring(0, 1);
			cur = getRank(rankStr);
			if(cur==-1){
				cur = Integer.parseInt(rankStr);
			}
			sorted[index]=cur;
			index++;
		}
		Arrays.sort(sorted);
		return sorted;
		
	}
	static int getRank(String hand){
		boolean notFound=true;
		int ranking = -1, index =0;
		while(notFound&&index<rank.length){
			if(hand.equals(rank[index])){
				notFound=false;
				ranking = index;
			}
			index++;
		}
		if(notFound){
			return -1;
		}else{
			return ranking+10;
		}
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		java.io.BufferedReader r = new java.io.BufferedReader (new 
				java.io.InputStreamReader (System.in));
		
		String s = r.readLine();
		StringTokenizer st = null;
		String[] hands = new String[5];
		int numOfTests = Integer.valueOf(s);
		int index =-1;
		for(int test=0;test<numOfTests;test++){
			s = r.readLine();
			st = new StringTokenizer(s);
			index = 0;
			while(st.hasMoreTokens()){
				hands[index]=st.nextToken();
				index++;
			}
			int[] sorted = sort(hands);
			int pattern = checkPattern(sorted);
			if(isSameSuit(hands)){
				if(pattern==SEQ){
					if(sorted[hands.length-2]==13){
						System.out.println("royal flush");
					}else{
						System.out.println("straight flush");
					}
				}else{
					System.out.println("flush");
				}
			}else{
				if(pattern==SEQ){
					System.out.println("straight");
				}else if(pattern==FOUR){
					System.out.println("four of a kind");
				}else if(pattern==THREEAND2){
					System.out.println("full house");
				}else if(pattern==THREE){
					System.out.println("three of a kind");
				}else if (pattern==TWOANDTWO){
					System.out.println("two pairs");
				}else if (pattern==TWO){
					System.out.println("pair");
				}else if(pattern==NONE){
					System.out.println("high card");
				}
			}
		}
	}	

}