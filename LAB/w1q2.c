#include <stdio.h>
int main()
{
    int array[50],low=0,high,c=1,x;
    printf("Enter size of array:"); 
    scanf("%d",&high); 
    printf("Enter elements of array:"); 
    for(int i=0;i<high;i++) 
    {
        scanf("%d",&array[i]);
    }
    printf("Enter any element to be searched:"); 
    scanf("%d",&x); 
    high=high-1;
    while (low <= high) 
    {
        int mid=low+(high-low)/2;
        if (array[mid] == x)
            printf("Element found at index %d\nComparision= %d",mid,c);
        if (array[mid] < x)
        {
            low = mid + 1;
            c++;
        }
        else
        {
            high = mid - 1;
            c++;
        }
    }
    return 0;
}


