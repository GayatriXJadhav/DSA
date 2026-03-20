class Solution {
public:
    void dfs(int row, int col,vector<vector<int>>&vis,vector<vector<char>>& grid,int delrow[],int delcol[],int n,int m){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                dfs(nrow,ncol,vis,grid,delrow,delcol,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    dfs(i,j,vis,grid,delrow,delcol,n,m);
                }
            }
        }
        return cnt;
    }
};