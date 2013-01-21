#include <stdio.h>

#include <vector>

using namespace std;



typedef vector<int> vi;
    vector<int> ans(100005);
int merge(vi& array, int start1, int end1, int start2, int end2) 
{


    ans.push_back(1);
    int count = 0, tstart1 = start1;
    int index = 1;
     while(start1 <= end1 && start2 <= end2){
                 if( array[start1] < array[start2])
                 {
                  ans[index++] = (array[start1++]);
                 }   
                 else
                 {
                  ans[index++] = (array[start2++]);
                  count += (end1 - start1 + 1);
                 }
    }
    if( start2 <= end2)
    {
        while(start2 <= end2)
                     ans[index++]= (array[start2++]);
    }
    if (start1 <= end1){
       while(start1 <= end1)
                    ans[index++] = (array[start1++]);
    
    }
    index = 1;
    for(int i = tstart1; i<= end2; i++){
            
            array[i]  = ans[index++];
 
            }
    return count;
    
    
}

int countin (vi& array, int start, int end)
{
 
    int count = 0;
    if(end == start) return 0;
    if((end - start) == 1){
            if(array[start] > array[end]){
                int temp = array[start];
                array[start] = array[end];
                array[end] = temp;
               return 1;
               }
               return 0;
}
    int mid = start + (end-start)/2;
    int a = countin(array, start, mid);
    int b = countin(array, mid+1, end);
    
    return a + b + merge(array, start, mid, mid+1 ,end);
    
    
    
}
int find(vi &array, int size)
{

    
    return countin(array, 0 ,  size-1);
    
}

int main()
{
    int T,num;
    
    
    scanf("%d\n",&T);
    vector<int> array(100003);

    int total = T;
    //array[0] = 0;
    int index = 0;
    while(T--)
    {
         scanf("%d",&num);
         array[index++] = (num);
    }
     printf("%ld",find(array, total));
  //  for(int i = 0; i< total; i++)
  //          printf("%ld ", array[i]);

    
       
      
}
