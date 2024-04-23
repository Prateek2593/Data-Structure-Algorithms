/*
310. Minimum Height Trees
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        vector<int> indegree(n);
        if(n == 1) return {0};
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            indegree[u]++; 
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        queue<int>que;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(indegree[i] == 1) que.push(i);
        }
        while(n>2){
            int size = que.size();
            n -= size;
            while(size--){
                int u = que.front();
                que.pop();
                for(int v : adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1){
                        que.push(v);
                    }
                }
            }
        }
        while(!que.empty()){
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};
