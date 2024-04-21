1971. Find if Path Exists in Graph
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex source to vertex destination.
Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 
/* DFS Approach */
class Solution {
public:
    bool check(unordered_map<int, vector<int>> adj, int S, int D, vector<bool>&visited){
        if(S == D) return true;
        if(visited[S] == true) return false;

        visited[S] = true;
        for(auto &it : adj[S]){
            if(check(adj, it, D, visited) == true) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(vector<int>&edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return check(adj, source, destination, visited);
    }
};


/* BFS Approach */ 
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(vector<int>&edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        queue<int>que;
        que.push(source);
        visited[source] = true;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            if(node == destination) return true;
            for(auto &it : adj[node]){
                if(!visited[it]){
                    que.push(it);
                    visited[it] = true;
                }
            }
        }
        return false;
    }
};
