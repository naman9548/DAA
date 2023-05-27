#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to perform Depth-First Search (DFS)
bool DFS(vector<vector<int>> graph, int vertices, int source, int destination) {
    stack<int> stk;
    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;
    
    stk.push(source);
    visited[source] = true;
    
    while (!stk.empty()) {
        int currentVertex = stk.top();
        stk.pop();
        
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                stk.push(i);
                visited[i] = true;
                
                if (i == destination)
                    return true;
            }
        }
    }
    
    return false;
}

int main() {
    int vertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices));
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    bool pathExists = DFS(graph, vertices, source, destination);

    if (pathExists)
        cout << "Yes, Path Exists";
    else
        cout << "No, Such Path Exists";


    return 0;
}
