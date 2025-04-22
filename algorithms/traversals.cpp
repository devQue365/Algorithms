#include <iostream>
#include <vector>
#include <queue>
std::vector<int> bfs(std::vector<std::vector<int>> &adj)
{
    // initialize the essentials
    std::vector<int> res;
    std::queue<int> queue;
    int v = adj.size();
    std::vector<bool> visited(v,false);
    
    int source = 0;
    visited[0] = true; // considering that we have visted 0th vertex
    queue.push(source); // push the source vertex into the queue
    // process each vertex(index value) one by one
    while(!queue.empty())
    {
        int curr_vertex = queue.front();
        // pop the vertex
        queue.pop();
        // push it into res vector
        res.push_back(curr_vertex);
        // traverse the adjacent vertices
        for(auto i:adj[curr_vertex])
        {
            if(!visited[i])
            {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    return res;
}

void dfs_traversal(int node, std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::vector<int> &res)
{
    // mark the node as visited
    visited[node] = true;
    // push back the node into res container
    res.push_back(node);
    // check and traverse neighours (if any)
    for(auto &i : adj[node])
    {
        if(!visited[i])
            dfs_traversal(i, adj, visited, res);
    }
}

/* Main DFS wrapper function */
std::vector<int> dfs(std::vector<std::vector<int>> &adj)
{
    int n = adj.size();
    // initialize visited container
    std::vector<bool> visited(n, false);
    // initialize visited container
    std::vector<int> res;
    // calling the main performing function
    dfs_traversal(0,adj,visited,res);
    return res;
}
int main()
{
    std::vector<std::vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    std::vector<int> bfs_order = bfs(adj);
    std::vector<int> dfs_order = dfs(adj);
    for(auto i:bfs_order)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    for(auto i:dfs_order)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    return 0;
}