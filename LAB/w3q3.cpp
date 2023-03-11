#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string checkDuplicates(vector<int> vec)
{
    sort(vec.begin(), vec.end()); // Sort the array in ascending order and have the time complexity of O(n log n)
    int n =vec.size();
    for (int i=0;i<n-1;i++)
    {
        if(vec[i]==vec[i+1])
        { 
            return "YES";
        }
    }
    return "NO";
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
        string ans = checkDuplicates(vec); // Check for duplicates
        cout<<ans<<endl;
    }
    return 0;
}
