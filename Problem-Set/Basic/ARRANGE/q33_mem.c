#include<stdio.h>
#include<math.h>

/*
The Chef has prepared the appetizers in the shapes of letters to spell a special message for the guests. There are n appetizers numbered from 0 to n-1 such that if the appetizers are arrayed in this order, they will display the message. The Chef plans to display them in this order on a table that can be viewed by all guests as they enter. The appetizers will only be served once all guests are seated.
The appetizers are not necessarily finished in the same order as they are numbered. So, when an appetizer is finished the Chef will write the number on a piece of paper and place it beside the appetizer on a counter between the kitchen and the restaurant. A server will retrieve this appetizer and place it in the proper location according to the number written beside it.
The Chef has a penchant for binary numbers. The number of appetizers created is a power of 2, say n = 2k. Furthermore, he has written the number of the appetizer in binary with exactly k bits. That is, binary numbers with fewer than k bits are padded on the left with zeros so they are written with exactly k bits.
Unfortunately, this has unforeseen complications. A binary number still "looks" binary when it is written upside down. For example, the binary number "0101" looks like "1010" when read upside down and the binary number "110" looks like "011" (the Chef uses simple vertical lines to denote a 1 bit). The Chef didn't realize that the servers would read the numbers upside down so he doesn't rotate the paper when he places it on the counter. Thus, when the server picks up an appetizer they place it the location indexed by the binary number when it is read upside down.
You are given the message the chef intended to display and you are to display the message that will be displayed after the servers move all appetizers to their locations based on the binary numbers they read.
*/

int bit_reverse(unsigned int n, unsigned int k)
{
	if(k==1)return n;
	unsigned int k1,k2,a,b;
	k1 = k/2;
	k2 = k-k1;
	a = n>>k2;
	b = n - (a<<k2);
	a = bit_reverse(a,k1);
	b = bit_reverse(b,k2);
	return (b<<k1)+a;
}

int bit_reverse1(unsigned int n, unsigned int k)
{
	int ret=0;
	int i;
	for(i=0;i<k;i++)
	{
		ret=(ret<<1) + (n&1);
		n=n>>1;
	}
	return ret;
}

int main()
{	
	unsigned int T,k,i,size,rev;
	char str[(1<<16)+1],ans[(1<<16)+1];
	scanf("%u",&T);
	while(T--)
	{
		scanf("%u %s",&k,str);
		size = (1<<k);
		for(i=0;i<size;i++)
		{
			rev = bit_reverse1(i,k);
			ans[rev] = str[i];
		}
		ans[size]='\0';
		printf("%s\n",ans);
	}	
	return 0;
}