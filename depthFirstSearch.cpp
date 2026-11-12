#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& adj, int u, std::vector<bool>& visited)
{
    visited[u] = true;
    std::cout << u << " ";
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(adj, v, visited);
        }
    }
}

// Обертка для запуска
void runDFS(const std::vector<std::vector<int>>& adj, int start)
{
    std::vector<bool> visited(adj.size(), false);
    dfs(adj, start, visited);
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
        adj[v].push_back(u);    // для неориентированного графа
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(4, 6);

    std::cout << "DFS начиная с вершины 0: \n";
    runDFS(adj, 0);

    std::cout << "\nDFS начиная с вершины 3: \n";
    runDFS(adj, 3);

    // Пример с ориентированным графом (дерево)
    //
    //        0
    //       / \
    //      1   2
    //     /   / \
    //    3   4   5
    //
    std::cout << "\n--- Ориентированный граф---\n";
    std::vector<std::vector<int>> dag(6);
    dag[0] = {1, 2};
    dag[1] = {3};
    dag[2] = {3, 4};

    std::cout << "DFS с вершины 0: ";
    runDFS(dag, 0);

    // Пример обхода ВСЕХ компонент связности
    std::cout << "\n--- Несвязный граф (обход всех компонент)---\n";
    std::vector<std::vector<int>> adj2(6);
    adj2[0] = {1};
    adj2[1] = {0};
    adj2[2] = {3};
    adj2[3] = {2};
    adj2[4] = {5};
    adj2[5] = {4};

    std::vector<bool> visited(adj2.size(), false);
    for (int i = 0; i < (int)adj2.size(); i++)
    {
        if (!visited[i])
        {
            std::cout << "Компонента с вершины " << i << ":";
            dfs(adj2, i, visited);
            std::cout << "\n";
        }
    }

    return 0;
}