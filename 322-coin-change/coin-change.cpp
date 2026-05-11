class Solution {
public:
    // int f(int ind, int T, vector<int>&a,vector<vector<int>>&dp){
        
    //     if(ind==0){
    //         if(T % a[ind]==0) return T/a[0];
    //         else return 1e9;
    //     }
        
        
    // }
    int coinChange(vector<int>& a, int T) {
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(T + 1,-1));
        for(int t=0;t<=T;t++){
            dp[0][t]= (t % a[0] == 0) ? t / a[0] : 1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=T;j++){
                if(dp[i][j] !=-1) return dp[i][j];
                int nottake= 0 + dp[i-1][j];
                int take=INT_MAX;
                if(a[i]<=j) 
                    take = 1 + dp[i][ j-a[i]];
        
                dp[i][j]= min(take,nottake);
            }
        }
        int ans=dp[n-1][T];
        if(ans >=1e9) return -1;
        return ans;
    }
};