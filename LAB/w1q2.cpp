#include <iostream>
#include <vector>
using namespace std;

bool binary_search(const vector<int>& arr, int key, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        comparisons++;
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n,t;
    cin>>t;
    while(t>0){
        cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int comparisons = 0;
    bool found = binary_search(arr, key, comparisons);
    if (found) {
        cout << "Key element found\n" << "comparisons: " << comparisons<< endl;
    } else {
        cout << "Key element not found\n"<< "comparisons: " << comparisons<< endl;
    }
        t--;
    }
    
    return 0;
}
