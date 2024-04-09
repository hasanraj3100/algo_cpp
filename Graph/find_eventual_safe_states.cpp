class Solution {
private: 
    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited,
    vector<bool> &pathVisited) {
        visited[node] = true; 
        pathVisited[node] = true; 

        for(int it: graph[node]) {
            if(!visited[it]) {
                if(dfs(it, graph, visited, pathVisited)) return true;
            } else if(pathVisited[it] == true) 
                return true;
        }

        pathVisited[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); 

        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false); 

        for(int i=0; i < n; i++) {
            
            for(int node: graph[i]) {
                pathVisited[i] =dfs(node, graph, visited, pathVisited) || pathVisited[i];
            }
        }

        vector<int> safeNodes; 

        for(int i=0; i < n; i++) {
            if(pathVisited[i] == 0) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};