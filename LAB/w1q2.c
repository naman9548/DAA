#include <stdio.h>
int main()
{
    int array[6]={3,5,9,13,16,19},low=0,high=5,i=1;
    int x=16;
    while (low <= high) 
    {
        int mid=low+(high-low)/2;
        if (array[mid] == x)
            printf("Element found at index %d\nComparision= %d",mid,i);
        if (array[mid] < x)
        {
            low = mid + 1;
            i++;
        }
        else
        {
            high = mid - 1;
            i++;
        }
    }
    return 0;
}

