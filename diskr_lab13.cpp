#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class GraphColoring {
private:
    int V;
    std::vector<std::list<int>> adj;

public:
    GraphColoring(int v) : V(v), adj(v) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void greedyColoring() {
        std::vector<int> result(V, -1);
        result[0] = 0;

        std::vector<bool> available(V, true);

        for (int u = 1; u < V; u++) {
            for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
                int i = *it;
                if (result[i] != -1)
                    available[result[i]] = false;
            }

            int cr;
            for (cr = 0; cr < V; cr++) {
                if (available[cr])
                    break;
            }

            result[u] = cr;

            std::fill(available.begin(), available.end(), true);
        }

        for (int u = 0; u < V; u++)
            std::cout << "Vertex " << u << " --->  Color " << result[u] << std::endl;
    }
};

int main() {
    GraphColoring g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    std::cout << "Coloring of graph 1" << std::endl;
    g1.greedyColoring();

    return 0;
}
