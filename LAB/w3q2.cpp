#include <iostream>
using namespace std;
void selectionSort(int arr[], int n, int& cmp, int& swaps) {
    int i,min,j;
    for (i=0;i<n-1;i++) {
        min=i;
        for (j=i+1;j<n;j++) {
            cmp++;
            if (arr[j]<arr[min]) {
                min=j;
            }
        }
        // if (minIndex != i) {
            swaps++;
            swap(arr[i], arr[min]);
        // }
    }
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int cmp=0, swaps=0;
        selectionSort(arr, n, cmp, swaps);
        cout<<"Sorted array: ";
        for (int i=0;i<n;i++) {
            cout <<arr[i]<< " ";
        }
        cout<<"\nComparisons: " <<cmp<<endl;
        cout<<"Swaps: "<<swaps<<endl;
    }
    return 0;
}
