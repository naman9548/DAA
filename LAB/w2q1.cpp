#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countOccurrences(vector<int>& vec, int key) {
    int n = vec.size();
    int left = 0, right = n - 1;

    // find the leftmost occurrence of key
    int leftmost = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] >= key) {
            right = mid - 1;
            if (vec[mid] == key) leftmost = mid;
        }
        else left = mid + 1;
    }

    // key not found
    if (leftmost == -1) return 0;

    // find the rightmost occurrence of key
    int rightmost = -1;
    left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] <= key) {
            left = mid + 1;
            if (vec[mid] == key) rightmost = mid;
        }
        else right = mid - 1;
    }

    // return the count of occurrences of key
    return rightmost - leftmost + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, key;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        cin >> key;
        int count = countOccurrences(vec, key);
        if (count > 0) {
            cout << key << " - " << count << endl;
        }
        else {
            cout << "Key not present\n";
        }
    }
    return 0;
}
