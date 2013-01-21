#include <stdio.h>   /* puts() */

#define MIN_MERGESORT_LIST_SIZE    32


#define BUF 4096

char ibuf[BUF];
int ipt = BUF;

int readInt() {
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}



int mergesort_array(int a[], int size, int temp[]) {
    int i1, i2, tempi;

    int ret = 0;

    if (size < MIN_MERGESORT_LIST_SIZE) {
        /* Use insertion sort */
        int i;
        for (i=0; i < size; i++) {
            int j, v = a[i];
            for (j = i - 1; j >= 0; j--) {
               if (a[j] <= v) break;
                a[j + 1] = a[j];
		ret++;
            }
            a[j + 1] = v;
        }
        return ret;
    }

    ret += mergesort_array(a, size/2, temp);
    ret += mergesort_array(a + size/2, size - size/2, temp);
    i1 = 0;
    i2 = size/2;
    tempi = 0;
    while (i1 < size/2 && i2 < size) {
        if (a[i1] < a[i2]) {
            temp[tempi] = a[i1];
            i1++;
        } else {
            temp[tempi] = a[i2];
	    ret += (size/2 - i1);
            i2++;
        }
        tempi++;
    }

    while (i1 < size/2) {
        temp[tempi] = a[i1];
        i1++;
        tempi++;
    }
    while (i2 < size) {
        temp[tempi] = a[i2];
        i2++;
        tempi++;
    }

    memcpy(a, temp, size*sizeof(int));
	return ret;

}


int main(int argc, char* argv[]) {
    int a[100005]; 
    int temp[100005];
    int i;

    int n=readInt();

    for(i=0; i<n; i++) {
       a[i] = readInt();
    }

    int ret = mergesort_array(a, n, temp);
  
    printf("%d",ret);
    return 0;
}
