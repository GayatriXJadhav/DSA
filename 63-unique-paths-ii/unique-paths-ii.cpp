class Solution {
public:
    // int MOD=(int)(1e9+7);
    int func(int n,int m, vector<vector<int>>&grid){
        vector<int>prev(m,0),curr(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {curr[j]=0;continue;}
                if(i==0 && j==0) {curr[j]=1;continue;}
                
                    int up=0;
                    int left=0;
                    if(i>0)
                        up= prev[j];
                    if(j>0) 
                        left=curr[j-1];
                    curr[j]= up + left;
                }
              prev=curr;
        }
        return prev[m-1] ;
    }
                    
                
            
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

    //    vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n,m,grid);
       
    }
};