class Solution {
  private: 
    bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited) {
        visited[node] = true; 
        pathVisited[node] = true; 
        
        for(int i: adj[node]) {
            if(!visited[i]) {
                if( dfs(i, adj, visited, pathVisited))
                    return true; 
            } else if(pathVisited[i]) return true;
        }
        
        
        pathVisited[node] = false; 
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        
        for(int i=0; i < V; i++) {
            for(int node: adj[i]) {
                if(!visited[node] && dfs(node, adj, visited,pathVisited)) return true;
            }
        }
        
        return  false;
    }
};