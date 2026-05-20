class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& a,int n,int m,vector<vector<int>>&dp){
        if(i>n-1 || j>m-1) return 1e9;
        if(i==n-1 && j==m-1) return max(1,1-a[i][j]);
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i+1,j,a,n,m,dp);
        int left=solve(i,j+1,a,n,m,dp);
        int need=min(up,left)-a[i][j];
        return dp[i][j]= max(1,need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(0,0,dungeon,n,m,dp);
    }
};