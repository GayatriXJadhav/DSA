class Solution {
public:
    void PacificDfs(int r,int c,vector<vector<int>>&PacificVis,vector<vector<int>>& heights){
         PacificVis[r][c]=1;
        int n=heights.size();
        int m=heights[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
           
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && heights[nrow][ncol]>=heights[r]     [c] && PacificVis[nrow][ncol]==0){
            PacificDfs(nrow,ncol,PacificVis,heights);
            }
        }

    }
       void AtlanticDfs(int r,int c,vector<vector<int>>&AtlanticVis,vector<vector<int>>& heights){
         AtlanticVis[r][c]=1;
        int n=heights.size();
        int m=heights[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
           
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && heights[nrow][ncol]>=heights[r]     [c] && AtlanticVis[nrow][ncol]==0){
            AtlanticDfs(nrow,ncol,AtlanticVis,heights);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>PacificVis(n,vector<int>(m,0));
        vector<vector<int>>AtlanticVis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if( i==0){
                for(int j=0;j<m;j++){
                    PacificDfs(i,j,PacificVis,heights);
                }
            }
            else {
                 PacificDfs(i,0,PacificVis,heights);
            }
        }
        for(int i=n-1;i>=0;i--){
            if( i==n-1){

             for(int j=m-1;j>=0;j--){
                AtlanticDfs(i,j,AtlanticVis,heights);
              }
            }
            else {
                 AtlanticDfs(i,m-1,AtlanticVis,heights);
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(PacificVis[i][j]==1 && AtlanticVis[i][j]==1) {
                ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};