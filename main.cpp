#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // no. of vertices
    list<int>* array; // pointer to array
    void depth_first_search_util(int v, bool visited[]); // recursive function used by DFS
public:
    Graph(int v); // constructor

    void add_edge(int v, int w); // add an edge to graph

    void depth_first_search(int v); // DFS traversal of the vertices reachable from V
};

Graph::Graph(int v) {
    this->V = v;
    array = new list<int>[v];
}

void Graph::add_edge(int v, int w) {
    array[v].push_back(w);
}

void Graph::depth_first_search_util(int v, bool *visited) {
    // current node as visited
    visited[v] = true;
    cout << v << " ";

    // recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = array[v].begin(); i != array[v].end(); ++i) {
        if (!visited[*i]) {
            depth_first_search_util(*i, visited);
        }
    }
}

void Graph::depth_first_search(int v) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    depth_first_search_util(v, visited);
}

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "Following is Depth First Traversal"
         << " (starting from vertex 2) \n";

    g.depth_first_search(2);

    return 0;
}
