#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
void dfs_traversal(int node, std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::stack<int> &stack)
{
    // mark the node as visited
    visited[node] = true;
    // check for the neighours
    for(auto &i : adj[node])
    {
        if(!visited[i])
        {
            dfs_traversal(i, adj, visited, stack);
        }
    }
    // push the node into stack
    stack.push(node);
}

std::vector<std::vector<int>> constructAdjacency(int V, std::vector<std::vector<int>> &edges)
{    
    std::vector<std::vector<int>> adj(V);
    for(auto &i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }
    return adj;
}
std::vector<int> topologicalSort(int V, std::vector<std::vector<int>> &edges)
{
    // initialize the essentials
    std::vector<std::vector<int>> adj = constructAdjacency(V, edges);
    std::vector<bool> visited(V, false);
    std::stack<int> stack;
    std::vector<int> result;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            dfs_traversal(i, adj, visited, stack);
    }
    // reverse the stack/ container to get the topological sort
    while(!stack.empty())
    {
        result.push_back(stack.top());
        stack.pop();
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};
    std::vector<int> result = topologicalSort(6, edges);
    for(auto &i : result)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}