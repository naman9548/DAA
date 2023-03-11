#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findpair(vector<int>vec,int size, int k){
    int i,j,t=0;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(abs(vec[i]-vec[j])==k){
                t++;
            }
        }
    }
    if(t==0)
        cout<<"No pair found";
    else{
        cout<<t<<endl;
    }
}
int main()
{
    int t;
    cin>>t; // Input the number of test cases
    while (t--)
    {
        int n,key;
        cin>>n; // Input the size of the array
        vector<int> vec(n);
        for (int i=0; i<n;i++)
        {
            cin>>vec[i];
        }
        cin>>key; 
        findpair(vec,n,key);
    }
    return 0;
}