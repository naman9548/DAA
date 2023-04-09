#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sumkey(vector<int> vec1, int key){
    vector<int> ret;
    int m=vec1.size();
    sort(vec1.begin(),vec1.end());
    if(key<vec1[0])
        return {0};
    for(int i=0;i<m;i++){
        int low=i,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(vec1[i]+vec1[mid]==key)
                return {vec1[i],vec1[mid]};
            else if(vec1[i]+vec1[mid]<key)
                low=mid+1;
            else 
                high=mid-1;
        }
    }
    return{0};
}
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        vector <int> vec1(n);
        for(int j=0;j<n;j++)
        {
            int temp;
            cin>>temp;
            vec1[j]=temp;
        }
        int key;
        cin>>key;
        vector<int> ret=sumkey(vec1,key);
        if(ret.size()<2)
            cout<<"No Such Elements Exist";
        else{
            for(int i=0;i<2;i++){
                cout<<ret[i]<<" ";
            }
        }
    }
    
    return 0;
}
