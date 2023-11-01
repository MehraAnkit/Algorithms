class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int vis[r][c];
        queue<pair<pair<int,int>,int>>q;
        int cntFres=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    cntFres++;
                }
            }
        }
        
        int time=0,cnt=0;
        int dirx[]={-1, 1, 0,0};
        int diry[]={0,0, -1, 1};
        while(!q.empty()){
                int m=q.front().first.first;
                int n=q.front().first.second;
                int t = q.front().second;
                time= max(time, t);
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=m+dirx[k];
                    int nc=n+diry[k];
                    if(nr>=0 && nr<r && nc>=0 && nc<c && grid[nr][nc]==1 && vis[nr][nc]!=2){
                        q.push({{nr,nc},t+1});
                        vis[nr][nc] = 2;
                        cnt++;
                    }
                
                }
            }
        
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(vis[i][j]!=2 && grid[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }
        
        if(cnt!=cntFres){
            return -1;
        }
        return time;
        
    }
};
