        #include<stdio.h>
     //   #include<conio.h>
        void quicksrt(int *arr,int start ,int end)
        {
             if(start >= end)
                      return;
        	int i, j,key;
        	key = arr[(start + end)/2];
       /* 	int temp2 = arr[key];
        	arr[key] = arr[end];
        	arr[end] = temp2;  */
        	i = start;
        	j = end;
        	while(1)
        	{
        	while( arr[i] < key )
        		i++;
        	while(arr[j] > key)
        		j--;
        	//swap the two pos
        	if(i<=j){
        	int temp = arr[i];
        	arr[i] = arr[j];
        	arr[j] = temp;
        	i++;
        	j--;
        	}
        	if ( i > j)
        	   break;
        		}
        	//swap ith and last element
       /* 	int temp = arr[i];
        	arr[i] = arr[end];
        	arr[end] = temp; */
        	//calling func again
        	
        	quicksrt(arr,start,j);
         
        	quicksrt(arr,i,end);
        }
        
        int main()
        {
            int arr[2000] = {0};
        	while(1)
        	{
        	int cases,i;
        	scanf("%d",&cases);
        	if(cases == 0)
        	{
        		break;
        	}
        	
        	for(i=0;i<cases;i++)
        	{
        		scanf("%d",&arr[i]);
        	}
        	quicksrt(arr,0,cases-1);
      //  	for(i=0;i<cases;i++)
       // 		printf("%d\n",arr[i]);
        	int count = 0;
        	for(i = cases-1;i >= 2;i--)
        	{
        		int l = 0;
        		int r = i - 1;
        		while(l<r)
        		{
        			if(arr[l] + arr[r] < arr[i])
        			{
        				count += r-l;
        				l++;
        			}
        			else
        				r--;
        		}
        
        	}
        	printf("%d\n",count);
         //                        getch();
        	}
        	return 0;
        }