// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, 
// Find any Topological Sorting of that Graph.

class Solution
{
    private: 
        void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
            visited[node] = true; 
            
            for(int i: adj[node]) {
                if(!visited[i]) dfs(i, adj, visited, st);
            }
            st.push(node);
        }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V, false); 
	    stack<int> st; 
	    vector<int> ans; 
	    
	    for(int i=0; i < V; i++) {
	        if(!visited[i]) {
	            dfs(i, adj, visited, st);
	        }
	    }
	    
	    
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans; 
	}
};