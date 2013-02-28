#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int lengthOfPermutation;
	int input[1001];
	int output[2002];
	int setCount = 0 ; 
	
	
	scanf("%d",&lengthOfPermutation);
	for(int i = 1 ; i<= lengthOfPermutation; i++)
	{
		scanf("%d",&input[i]);
	}
	
	
	
	int visitCount = 0;
	
	
	
	int j = 1; // output position
	output[0] = 0;
	output[1] = 1;
	int setBeginPos = 1;
	
	int currentPosition = 1;
	
	
	
	while(visitCount != lengthOfPermutation )
	{
			while(input[currentPosition] != setBeginPos)
			{
				
				
				output[++j] = input[currentPosition];
				
				int x = currentPosition;
				currentPosition = input[currentPosition];
				
				input[x] = 0;
				visitCount++;
			}
			
			// append setBeginPos at end
			input[currentPosition] = 0;
			output[++j] = setBeginPos;
			output[++j] = 0; //\n
			
			visitCount++;
			setCount++;
			
			//search for new setbeginPos
			
			if(visitCount != lengthOfPermutation)
			{
				while(input[++setBeginPos] == 0)
				{
					// searchin new set begin pos
				}
				
				
				currentPosition = setBeginPos;
				//currentPosition = input[setBeginPos];
				output[++j] = setBeginPos;	
			}
	}
	
	
	printf("%d\n",setCount);
	for(int i = 1; i <= j ; i++)
	{
		if(output[i])
		{
			printf("%d ",output[i]);
		}
		else
		{
			printf("\n");
		}
	}
	
	return 0;
	
}