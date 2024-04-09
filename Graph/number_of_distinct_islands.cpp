// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        set<vector<pair<int,int>>> st;
        
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        
        return st.size();
    }
    
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid,
    vector<pair<int,int>> &vec, int br, int bc) {
        vis[i][j] = true;
        
        vec.push_back({i - br, j - bc});
        
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        
        for(int k=0; k < 4; k++) {
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];
            
            if(nRow >=0 && nRow < grid.size() && nCol >= 0 && 
            nCol < grid[0].size() && !vis[nRow][nCol]
            && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, vis, grid, vec, br, bc);
            }
        }
    }
};