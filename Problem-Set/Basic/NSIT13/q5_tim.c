#include<stdio.h>

void Merge(int *array,int left,int mid,int right)
{
        int iter,tempArray[5002];
        int pos=0,lpos = left,rpos = mid + 1;
        while(lpos <= mid && rpos <= right)
        {
                if(array[lpos] < array[rpos])
                {
                        tempArray[pos++] = array[lpos++];
                }
                else
                {
                        tempArray[pos++] = array[rpos++];
                }
        }
        while(lpos <= mid)  tempArray[pos++] = array[lpos++];
        while(rpos <= right)tempArray[pos++] = array[rpos++];
        for(iter = 0;iter < pos; iter++)
        {
                array[iter+left] = tempArray[iter];
        }
        return;
}

void Sort(int *array,int left,int right)
{
        int mid = (left+right)/2;
        if(left<right)
        {
                /* Sort the left part */
                Sort(array,left,mid);
                /* Sort the right part */
                Sort(array,mid+1,right);
                /* Merge the two sorted parts */
                Merge(array,left,mid,right);
        }
}


int main()
{
	int arr[11],num,t=10,i,n;
	while(t--)
	{
        i=0;
		for(i=0;i<10;i++)
		{
          scanf("%ld",&num);
		  arr[i]=num%42;
	    }
	    n=0;
		Sort(arr,0,9);
	    for(i=0;i<9;i++)
	    {
		 if(arr[i]!=arr[i+1])
		 n++;
		}
		printf("%d\n",n+1);
    }
return 0;
}
	    
