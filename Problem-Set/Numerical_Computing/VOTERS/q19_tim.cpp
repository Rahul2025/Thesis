#include <iostream>

using namespace std;

const int MAX_SIZE = 20000;
static char input[MAX_SIZE];

struct readInput{
	char* CP;
	readInput(){
		int size = fread(input, 1, MAX_SIZE, stdin);
		CP = input;
	}
	int nextInt(){
		int gap = input + MAX_SIZE - CP;
		if (gap < 100){
			memcpy(input, CP, gap);
			fread(input + gap, 1, MAX_SIZE - gap, stdin);
			CP = input;
		}
		while (*CP < '0') CP++;
		int res = 0;
		while (*CP >= '0'){
			res = res * 10 + (*CP) - '0';
			CP++;
		}
		return res;
	}
};

int n1,n2,n3,i,id1[50001],id2[50001],id3[50001],p1=0,p2=0,p3=0,r[100000],c=0; 

int main(){
	readInput ri;
    //scanf("%i%i%i",&n1,&n2,&n3);
	n1=ri.nextInt();
	n2=ri.nextInt();
	n3=ri.nextInt();

	for(i=0;i<n1;i++)id1[i]=ri.nextInt();//scanf("%i",&id1[i]);
	id1[n1]=2147483647;
	for(i=0;i<n2;i++)id2[i]=ri.nextInt();//scanf("%i",&id2[i]);
	id2[n2]=2147483646;
	for(i=0;i<n3;i++)id3[i]=ri.nextInt();//scanf("%i",&id3[i]);
	id3[n3]=2147483645;
	while(p1<n1||p2<n2||p3<n3){
		if(id1[p1]==id2[p2]&&id1[p1]==id3[p3]){
			r[c]=id1[p1];
			c++;
			p1++;p2++;p3++;
		}
		else if(id1[p1]==id2[p2]){
			r[c]=id1[p1];
			c++;
			p1++;p2++;
		}
		else if(id1[p1]==id3[p3]){
			r[c]=id1[p1];
			c++;
			p1++;p3++;
		}
		else if(id2[p2]==id3[p3]){
			r[c]=id2[p2];
			c++;
			p2++;p3++;
		}
		else{
			if(p1<n1&&id1[p1]<id2[p2]&&id1[p1]<id3[p3])p1++;
			if(p2<n2&&id2[p2]<id1[p1]&&id2[p2]<id3[p3])p2++;
			if(p3<n3&&id3[p3]<id2[p2]&&id3[p3]<id1[p1])p3++;
		}
	}
	printf("%i\n",c);
	for(i=0;i<c;i++)printf("%i\n",r[i]);
}