#include <stdio.h>
#include <math.h>
int main()
{
    int l,key,i,f=0,n,comparision=1;
    printf("Enter size of array:");
    scanf("%d",&n);
    int start=0,end=sqrt(n);
    int a[n];
    printf("Enter elements of array in ascending order:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to search:");
    scanf("%d",&key);
    while(a[end]<key&&start<n)
    {
        start=end;
        end=end+sqrt(n);
        if(end>n-1)
            end=n-1;
        comparision++;
    }
    for(i=start;i<=end;i++)
    {
        
        if(a[i]==key){
            comparision++;
            f=1;
            break;
        }
        
    }
    if(f==1)
        printf("Element found at index %d",i);
    else
        printf("Element not found.");
    printf("\nTotal comparision made = %d",comparision);
}
