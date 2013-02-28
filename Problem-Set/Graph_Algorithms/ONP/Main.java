import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		int xCase = Integer.parseInt(in.readLine());
		for (int i=0;i<xCase;i++)
		{
			String strEx = in.readLine();
			ArrayList<Integer> arrOpen = new ArrayList<Integer>();
			ArrayList<Integer> arrClose = new ArrayList<Integer>();
			for (int a=0;a<strEx.length();a++)
			{
				if (strEx.charAt(a) == '(') 
				{
					arrOpen.add(a);
				} else if (strEx.charAt(a) == ')')
				{
					arrClose.add(a);
				}
			}
			String[] arrEx = new String[arrOpen.size()];
			for (int a=arrOpen.size()-1;a>=0;a--)
			{
				arrEx[a] = "";
				int xStartPar = arrOpen.get(a)+1;
				int xEndPar = 0;
				for (int b=0;b<arrClose.size();b++)
				{
					if (xStartPar < arrClose.get(b))
					{
						xEndPar = arrClose.get(b);
						arrClose.remove(b);
						break;
					}
				}
				String strSubEx = strEx.substring(xStartPar,xEndPar);
				char chOp = '+';
				int xLoop = 0;
				int xCountPar = 1;
				while (xLoop < strSubEx.length())
				{
					int xChar = strSubEx.charAt(xLoop) - 97;
					if ((xChar >= 0) && (xChar <= 26))
					{
						arrEx[a] += strSubEx.charAt(xLoop);
						xLoop++;
					} else if (xChar == -57)
					{
						arrEx[a] += arrEx[a+xCountPar];
						xCountPar++;
						int xCountOpen = 0;
						for (int b=xLoop+1;b<strSubEx.length();b++)
						{
							if (strSubEx.charAt(b) == 40)
							{
								xCountOpen++;
								xCountPar++;
							} else if (strSubEx.charAt(b) == 41)
							{
								if (xCountOpen == 0)
								{
									xLoop = b + 1;
									break;
								}
								xCountOpen--;
							}
						}
					} else
					{
						chOp = strSubEx.charAt(xLoop);
						xLoop++;
					}
				}
				arrEx[a] += chOp;
			}
			out.write(arrEx[0]);
			out.write('\n');
			out.flush();
		}
	}

}