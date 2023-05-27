#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> color(n, -1);  // -1 represents unvisited, 0 and 1 represents two different colors

    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];  // Assign a different color than the current vertex
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;  // If adjacent vertices have the same color, graph is not bipartite
            }
        }
    }

    return true;
}

bool isBipartiteGraph(vector<vector<int>>& graph) {
    int n = graph.size();

    for (int i = 0; i < n; i++) {
        if (!isBipartite(graph, i)) {
            return false;  // If any component of the graph is not bipartite, the whole graph is not bipartite
        }
    }

    return true;
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

    bool isBipartite = isBipartiteGraph(graph);

    if (isBipartite) {
        cout << "Yes, Bipartite";
    } else {
        cout << "Not Bipartite";
    }

    return 0;
}
