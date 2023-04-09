#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

int kthSmallest(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n-1;
    while (low <= high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k-1) {
            return arr[pivotIndex];
        } else if (pivotIndex < k-1) {
            low = pivotIndex + 1;
        } else {
            high = pivotIndex - 1;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;
        int kthSmallestElement = kthSmallest(arr, k);
        if (kthSmallestElement == -1) {
            cout << "not present\n";
        } else {
            cout << kthSmallestElement << "\n";
        }
    }
    return 0;
}
