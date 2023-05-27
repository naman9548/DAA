#include <iostream>
#include <vector>
using namespace std;

bool hasCycleUtil(vector<vector<int>>& graph, int v, vector<bool>& visited, vector<bool>& recursionStack) {
    visited[v] = true;
    recursionStack[v] = true;

    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1) {
            if (!visited[i]) {
                if (hasCycleUtil(graph, i, visited, recursionStack))
                    return true;
            } else if (recursionStack[i]) {
                return true;
            }
        }
    }

    recursionStack[v] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> recursionStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, i, visited, recursionStack))
                return true;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    bool hasCycleExists = hasCycle(graph);

    if (hasCycleExists) {
        cout << "Yes, Cycle Exists";
    } else {
        cout << "No Cycle Exists";
    }

    return 0;
}
