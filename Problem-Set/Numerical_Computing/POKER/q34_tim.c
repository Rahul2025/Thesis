#include<stdio.h>

int checkStraight(int *t, int n){
	
	int c, i;
	
	for(i = 2; i < 14 && t[i] == 0; i++)
		;
	if((i == 2 || i == 10) && t[0])
		c = 4;
	else
		c = 5;
	while((--c) && t[i+c])
		;
	if(c == 0){
		if(i == 10)
			return 1;
		else
			return 2;
	}
	else 
		return 0;

}

void printPokerInHand(char *str){

	int temp[14] = {0};
	int count[5] = {0};
	int i, v, c;
	int fc, cnt ;
	
	fc = str[1]; 
	cnt = 0;
	for(i = 0; i < 15; i += 3){	
		c = str[i];
		if(isdigit(c))
			temp[c-'0']++;
		else if(c == 'A')
			temp[0]++;
		else if(c == 'T')
			temp[10]++;
		else if(c == 'J')
			temp[11]++;
		else if(c == 'Q')
			temp[12]++;
		else 
			temp[13]++;
			
		if(str[i+1] == fc)
			cnt++;	
	}
	if(cnt == 5){
		 v = checkStraight(temp, 14);
		 if(v == 1)
	 		puts("royal flush");
		 else if(v == 2)
		 	puts("straight flush");
	 	 else
	 	 	puts("flush");
	}else{
		for(i = 0 ; i < 14 ; i++)
			count[temp[i]]++;
		if(count[4] == 1)
			puts("four of a kind");
		else if(count[3] == 1){
			if(count[2] == 1)
				puts("full house");
			else
				puts("three of a kind");
		}
		else if(count[2] == 2)
			puts("two pairs");
		else if(count[2] == 1)
			puts("pair");
		else{
			v = checkStraight(temp, 14);
			if(v)
				puts("straight");
			else
				puts("high card");	
		}
	}

}

int main()
{
	
	char Line[20];
	int T;
	int c, i;
	
	scanf("%d",&T);
	getchar(); // read extra line
	while(T--){
		//read a line
		for(i = 0; (c = getchar()) != '\n'; i++)
			Line[i] = c;
		Line[i] = 0;
		printPokerInHand(Line);
	}
	return 0;
}