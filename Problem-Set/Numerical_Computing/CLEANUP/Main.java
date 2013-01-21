import java.util.Scanner;

/**
 * @author it.pune
 *
 */
class Main{
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int outerCount = Integer.parseInt(input.nextLine());
		String[] firstLvl = new String[outerCount];
		String[] secondLvl = new String[outerCount];
		StringBuffer chefBuff = null;
		StringBuffer assistBuff = null;
		StringBuffer resBuff=new StringBuffer();
		for(int i=0;i<outerCount;i++)
		{
			firstLvl[i] = input.nextLine();
			secondLvl[i] = " "+input.nextLine()+" ";
			chefBuff = new StringBuffer();
			assistBuff = new StringBuffer();
			int index = Integer.parseInt(firstLvl[i].split(" ")[0]);
			for(int k=0,l=1;k<index;k++)
			{
				int tempi = k+1;
				if(secondLvl[i].indexOf(" "+tempi+" ")==-1)
				{
					if(l%2!=0)
					{
					chefBuff.append(k+1+" ");
					}
					else
					{
					assistBuff.append(k+1+" ");
					}
					l++;
				}
			}
			resBuff.append("\n"+chefBuff.toString()+"\n"+assistBuff.toString()+"\n");
		}
		System.out.println(resBuff);
	}
}