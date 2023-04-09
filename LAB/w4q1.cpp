#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays
int merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
    int i = left; // Starting index of left subarray
    int j = mid + 1; // Starting index of right subarray
    int k = left; // Starting index of temp array
    int comparisons = 0; // Count for number of comparisons
    int inversions = 0; // Count for number of inversions

    // Merge the left and right subarrays into temp array in sorted order
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); // Counting the inversions
        }
        comparisons++; // Counting the comparisons
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted elements from temp array to original array
    for (int m = left; m <= right; m++) {
        arr[m] = temp[m];
    }

    return comparisons + inversions; // Total comparisons = number of comparisons + number of inversions
}

// Function to perform merge sort on the array
int mergeSort(vector<int>& arr, int left, int right, vector<int>& temp) {
    int comparisons = 0; // Count for number of comparisons
    if (left < right) {
        int mid = left + (right - left) / 2; 
        comparisons += mergeSort(arr, left, mid, temp);
        comparisons += mergeSort(arr, mid + 1, right, temp);
        comparisons += merge(arr, left, mid, right, temp);
    }

    return comparisons;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> temp(n); // Temporary array to store sorted subarrays
        int comparisons = mergeSort(arr, 0, n - 1, temp); // Perform merge sort and count number of comparisons

        // Counting the number of inversions in sorted array
        int inversions = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    inversions++;
                }
            }
        }

        // cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Comparisons: " << comparisons << endl;
        cout << "Inversions: " << inversions << endl;
    }
    return 0;
}
