#include <stdio.h> 
int main()
{
    int n,i,arr[50],key,f=0; 
    printf("Enter size of array:"); 
    scanf("%d",&n); 
    printf("Enter elements of array:"); 
    for(i=0;i<n;i++) 
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter any element to be searched:"); 
    scanf("%d",&key); 
    for(i=0;i<n;i++) 
    {
        if(key== arr[i]) 
        {
        f=1; 
        break;
        }
    }
    if(f==1)
        printf("Present\n"); 
    else 
        printf("Not present\n"); 
    printf("%d",i+1); 
    return 0;
}
