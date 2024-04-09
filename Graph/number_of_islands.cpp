class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> visited(m*n, false);
        int ans = 0;
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                if(!visited[i*n+j] && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, m, n, visited);
                }
            }
        }

        return ans;

    }

    void dfs(vector< vector<char> >& grid, int i, int j, int m, int n, vector<bool>&visited) {
        if(i >= m || j >=n) return;
        if( i < 0 || j <0) return;
        if(grid[i][j] == '0') return;
        if(visited[i*n + j]) return;
        
        visited[i*n+j] = true;

        dfs(grid, i+1, j, m, n, visited);
        dfs(grid, i-1, j, m, n, visited);
        dfs(grid, i, j+1, m, n, visited);
        dfs(grid, i, j-1, m, n, visited);
    }
};