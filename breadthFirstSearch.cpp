#include <iostream>
#include <vector>
#include <queue>

void bfs(const std::vector<std::vector<int>>& adj, int start)
{
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front(); q.pop();
        std::cout << curr << " ";
        for (int neighbor : adj[curr])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Пример
int main()
{
    // Граф на 7 вершин (0..6), неориентированный
    //
    //        0
    //       / \
    //      1   2
    //     / \   \
    //    3   4   5
    //         \
    //          6
    //
    int n = 7;
    std::vector<std::vector<int>> adj(n);

    auto addEdge = [&](int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Для неориентированного графа
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(4, 6);

    std::cout << "BFS начиная с вершины 0: \n";
    bfs(adj, 0);

    std::cout << "\nBFS начиная с вершины 3: \n";
    bfs(adj, 3);

    // Пример с несвязным графом (есть изолированная вершина)

    std::cout << "\n--- Несвязный граф ---\n";
    std::vector<std::vector<int>> adj2(5);
    adj2[0].push_back(1);
    adj2[1].push_back(0);
    adj2[2].push_back(3);
    adj2[3].push_back(2);
    // Вершина 4 изолирована

    std::cout << "BFS с вершины 0 (компонента {0,1}): ";
    bfs(adj2, 0);

    return 0;
}