#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<char>& arr, int n)
{
    vector<int> count(26, 0); // array to store count of each alphabet

    // count frequency of each alphabet
    for(int i=0; i<n; i++)
        count[arr[i]-'a']++;

    // update count array to store actual position of each alphabet in sorted array
    for(int i=1; i<26; i++)
        count[i] += count[i-1];

    // create a new array to store sorted order
    vector<char> output(n);
    for(int i=0; i<n; i++)
    {
        output[count[arr[i]-'a']-1] = arr[i];
        count[arr[i]-'a']--;
    }

    // copy sorted array back to original array
    for(int i=0; i<n; i++)
        arr[i] = output[i];
}

int main()
{
    int T;
    // cout<<"Enter number of test cases: ";
    cin>>T;
    while(T--)
    {
        int n;
        // cout<<"Enter size of array: ";
        cin>>n;
        vector<char> arr(n);
        // cout<<"Enter alphabets: ";
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        // sort array using counting sort
        countSort(arr, n);

        // find alphabet with maximum frequency
        int max_freq = 0;
        char max_ch = arr[0];
        for(int i=1, count=1; i<n; i++)
        {
            if(arr[i] == arr[i-1])
                count++;
            else
                count = 1;
            if(count > max_freq)
            {
                max_freq = count;
                max_ch = arr[i];
            }
        }

        if(max_freq > 1)
            cout<<max_ch<<"-"<<max_freq<<endl;
        else
            cout<<"No Duplicates Present"<<endl;
    }
    return 0;
}
