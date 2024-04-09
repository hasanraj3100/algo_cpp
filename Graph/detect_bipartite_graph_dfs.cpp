class Solution {
private: 
    bool dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, int color[], bool cl) {
        color[node] = cl; 
        visited[node] = true;
        for(auto it: graph[node]) {
            if(!visited[it]) {
                if(dfs(graph, it, visited, color, !cl)== false) return false;
            } else if(color[it] == cl)  return false;         
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 

        int color[n]; 
        for(int i=0; i < n; i++) color[i] = -1; 
        vector<bool> visited(n, false);

        for(int i=0; i < n; i++) {
            for(auto it: graph[i]) {
                if(!visited[it]) {
                    if(dfs(graph, it, visited, color, 0) == false) return false;
                }
            }
        }


        return true;
    }
};