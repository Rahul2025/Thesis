# include <stdio.h>
using namespace std;
int main()
{
	int count,inp; scanf("%d",&count);
	long long int arr[1001];
	arr[1]= 1;
	for(inp = 2;inp<1001; inp++){
		arr[inp]=0;
		for(unsigned int i = 1; i < inp; i += 1)
			arr[inp]+=( arr[i]*arr[inp-i]);
		arr[inp]=arr[inp]%10000;
	}
	while(count){
		scanf("%d",&inp);
		printf("%lld\n",arr[inp]);
		count--;
	}
	return 0;
}