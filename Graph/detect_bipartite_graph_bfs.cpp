class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 

        vector<int> color(n, -1);

        for(int i=0; i < n; i++) {
            if(color[i] == -1) {
                color[i] = 0; 
                queue<int> q; 
                q.push(i);

                while(!q.empty()) {
                    int node = q.front(); 
                    q.pop(); 

                    for(auto item: graph[node]) {
                        if(color[item] == -1) {
                            color[item] = !color[node];
                            q.push(item);
                        } else if(color[item] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};