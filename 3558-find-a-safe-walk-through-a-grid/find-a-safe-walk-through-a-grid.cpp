class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>>q;
       
             int startHealth=health-grid[0][0];
             if(startHealth<1) return false;
             q.push({startHealth,{0,0}}); 
            vis[0][0]=startHealth;

          
        while(!q.empty()){
            int h=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==m-1 && h>=1) return true;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n &&
                ncol>=0 && ncol<m ){
                   int nheight=h-grid[nrow][ncol];
                   if(nheight>=1 && nheight>vis[nrow][ncol])
                   {
                    vis[nrow][ncol]=nheight;
                    q.push({nheight,{nrow,ncol}});
                   }
                }
            }
       
    }
       
        return false;

    }
};