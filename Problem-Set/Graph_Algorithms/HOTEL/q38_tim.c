#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int iNumOfCases, iNumOfVisitors, iMaxNumOfVisitors, iNumOfVisitorsAtGivenTime, i, j;
  int iEntries[100], iExits[100], iNumOfVisitorsPerHour[1001];
  scanf("%d", &iNumOfCases);
  while(iNumOfCases--)
    {
      memset(iNumOfVisitorsPerHour, 0, 1001*sizeof(int));
      /*
      for(i = 0; i < 1001; i++)
	{
	  printf("%d\n", iNumOfVisitorsPerHour[i]);
	}
      */
      iMaxNumOfVisitors = iNumOfVisitorsAtGivenTime = 0;
      scanf("%d", &iNumOfVisitors);
      for(i = 0; i < iNumOfVisitors; i++)
	{
	  scanf("%d", &iEntries[i]);
	}
      for(i = 0; i < iNumOfVisitors; i++)
	{
	  scanf("%d", &iExits[i]);
	}
      for(i = 0; i < iNumOfVisitors; i++)
	{
	  iNumOfVisitorsPerHour[iEntries[i]]++;
	  iNumOfVisitorsPerHour[iExits[i]]--;
	}
      for(i = 0; i < 1001; i++)
	{
	  iNumOfVisitorsAtGivenTime += iNumOfVisitorsPerHour[i];
	  if(iMaxNumOfVisitors < iNumOfVisitorsAtGivenTime)
	    {
	      iMaxNumOfVisitors = iNumOfVisitorsAtGivenTime;
	    }
	}
      printf("%d\n", iMaxNumOfVisitors);
    }
  return 0;
}