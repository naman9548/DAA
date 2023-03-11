#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findseq(vector<int>vec,int size){
    int i,j,k,t=0;
    vector<int> ret;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            for(k=j+1;k<size;k++){
                if(vec[i]+vec[j]==vec[k]){
                    ret.push_back(i);
                    ret.push_back(j);
                    ret.push_back(k);
                    t++;
                }
            }
        }
    }
    if(t==0)
        cout<<"No sequence found";
    else{
        for(i=0;i<ret.size();i++){
            cout<<ret[i]<<" ";
            if((i+1)%3==0)
                cout<<endl;
        }
    }
}
int main()
{
    int t;
    cin>>t; // Input the number of test cases
    while (t--)
    {
        int n;
        cin>>n; // Input the size of the array
        vector<int> vec(n);
        for (int i=0; i<n;i++)
        {
            cin>>vec[i];
        }
        findseq(vec,n);
    }
    return 0;
}