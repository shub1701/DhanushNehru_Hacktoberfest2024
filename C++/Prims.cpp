#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V;
    vector<pii>* adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pii>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primMST() {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;
        for (auto& [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.primMST();
    return 0;
}
