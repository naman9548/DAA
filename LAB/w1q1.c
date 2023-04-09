#include <stdio.h> 
int main()
{
    int n,i,arr[50],key,f=0,t; 
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n); 
        for(i=0;i<n;i++) 
        {
            scanf("%d",&arr[i]);
        }
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
            printf("Present "); 
        else 
            printf("Not present "); 
        printf("%d",i+1);
        t--;
    }
     
    return 0;
}
