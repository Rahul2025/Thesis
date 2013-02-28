#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
bool comp(const vector<int>&v1,const vector<int>&v2)
{	if(v1.size()!=v2.size())
		return v1.size()<v2.size();
	for(int i=0;i<v1.size();i++)
		if(v1[i]!=v2[i])
			return (v1[i]<v2[i]);
	return false;
}

int main()
{	int t,p1,p2,i,j;
	int c;
	vector<int> a,b;
	cin>>t;
	c=getchar();	
	while(t--)
	{	
			
			while((c=getchar())!='\n')
			{	a.push_back(c-'0');
		//		b.push_back(c-'0');
			}
		b=a;	
			
		
		if(a.size()%2)
			p1=p2=(a.size())/2;
		else
		{	p1=(a.size())/2-1;
			p2=(a.size())/2;
		}
		i=p1;j=p2;
		for(;i>=0;i--)
			a[j++]=a[i];
		//palin(a,p1,p2);
		if(comp(b,a))
			{for(int i=0;i<a.size();i++)
				cout<<a[i];
			}
		else
		{	//palin(a,p1,p2);
	for(int flag=1;flag;)
	{	if(p1<0)
		{	a[a.size()-1]=1;
			a.insert(a.begin(),1);
		
		flag=0;
		}
		else if(a[p1]<9)
		{	a[p2]=a[p1]=a[p1]+1;
			flag=0;
		}
		else
		{	a[p2]=a[p1]=0;
			p2++;
			p1--;
			//palin(a,p1,p2);
			//flag=0;
		}
	}

			for(int i=0;i<a.size();i++)
				cout<<a[i];
		}			
		cout<<"\n";
		a.clear();
		b.clear();
	
	}
	return 0;
}