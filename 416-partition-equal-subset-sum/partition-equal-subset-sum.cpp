class Solution {
public:
    // bool subsetSumutil(int n,int target,vector<int>& nums,vector<vector<int>>&dp){
    //     if(target==0) return true;
    //     if(n==target) return nums[0]==target;
    //     if(dp[n][target]!=-1) return dp[n][target];
    //     bool nottaken=subsetSumutil(n-1,target,nums,dp);
    //     bool taken=false;
    //     if(nums[n]<=target) {
    //         taken=subsetSumutil(n-1, target-nums[n],nums,dp);
    //     }
    //     return dp[n][target]= taken | nottaken;
    // }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];

        }
        if(totSum % 2!=0)
            return false;
        int targetSum=totSum / 2;
        vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false));
         for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

       if (nums[0] <= targetSum) {
            dp[0][nums[0]] = true;
        }

        // Step 7: Fill DP table
        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= targetSum; target++) {
                bool notTaken = dp[index - 1][target];
                bool taken = false;
                if (nums[index] <= target) {
                    taken = dp[index - 1][target - nums[index]];
                }
                dp[index][target] = notTaken || taken;
            }
        }

        // Step 8: Return result
        return dp[n - 1][targetSum];

        
    }
};