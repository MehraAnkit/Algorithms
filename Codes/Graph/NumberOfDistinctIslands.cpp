class Solution {
    private:
        void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &vis
        ,vector<pair<int, int>> &temp, int row, int col, int ii, int ij){
            vis[i][j]=1;
            temp.push_back({i-ii, j-ij});
            int dr[]={0, 1, 0, -1};
            int dc[]={1, 0, -1, 0};
            for(int move=0;move<4;move++){
                int nr=i+dr[move];
                int nc=j+dc[move];
                if(nr>=0 && nr<row && nc>=0 && nc<col && vis[nr][nc]==0 && grid[nr][nc]==1){
                    dfs(nr,nc, grid, vis,temp, row, col, ii, ij);
                }
            }
            
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row=grid.size();
        int col=grid[0].size();
        set<vector<pair<int, int>>> s;
        vector<vector<int>> vis(row, vector<int> (col, 0));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vector<pair<int, int>> temp;
                    dfs(i,j, grid, vis,temp, row, col, i, j);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};
