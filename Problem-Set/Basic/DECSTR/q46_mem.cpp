#include<iostream>
using namespace std;
int main()
{
    int t,k;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cin>>k;
            if(k<=25)
            {
                    for(int j=k;j>=0;j--)
                    {
                            cout<<(char)(97+j);
                    }
            }
            if(k<=50&&k>25)
            {
                           int k1=k-25;
                           for(int j=k1;j>=0;j--)
                           {
                                   cout<<(char)(97+j);
                            }
                            for(int j=25;j>=0;j--)
                            {
                                   cout<<(char)(97+j);
                            }
            }
            if(k>50&&k<=75)
            {
                           
                           int k1=k-50;
                           for(int j=k1;j>=0;j--)
                           {
                                   cout<<(char)(97+j);
                            }
                            for(int j=25;j>=0;j--)
                            {
                                   cout<<(char)(97+j);
                            }
                            for(int j=25;j>=0;j--)
                            {
                                   cout<<(char)(97+j);
                            }
            }
            if(k>75&&k<=100)
            {
                            int k1=k-75;
                           for(int j=k1;j>=0;j--)
                           {
                                   cout<<(char)(97+j);
                            }
                            for(int j=25;j>=0;j--)
                            {
                                   cout<<(char)(97+j);
                            }
                            for(int j=25;j>=0;j--)
                            {
                                   cout<<(char)(97+j);
                            }
                            for(int j=25;j>=0;j--)
                            {
                                   cout<<(char)(97+j);
                            }
            }
                    cout<<"\n";
            }
    return 0;
}