#include <iostream>
#include <vector>
using namespace std;

vector<int> common(vector<int> vec1, vector<int> vec2){
    vector<int> ret;
    int m = vec1.size();
    int n = vec2.size();
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (vec1[i] == vec2[j]) {
            ret.push_back(vec1[i]);
            i++;
            j++;
        } else if (vec1[i] < vec2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ret;
}

int main() {
    int m, n;
    cin >> m;
    vector<int> vec1(m);
    for (int i = 0; i < m; i++) {
        cin >> vec1[i];
    }
    cin >> n;
    vector<int> vec2(n);
    for (int i = 0; i < n; i++) {
        cin >> vec2[i];
    }
    vector<int> ret = common(vec1, vec2);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    return 0;
}
