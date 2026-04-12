class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<int>points(maxVal + 1,0);
        for(int num:nums){
            points[num]+=num;
        }
        // vector<int>dp(maxVal+1,0);
        // dp[0]=0; 
       int prev2=0;
        // dp[1]=points[1]; 
       int  prev1=points[0];
       int curr=0;
       
        for(int i=1;i<=maxVal;i++){
         curr=max(prev1,prev2 + points[i]);
            prev2=prev1;
            prev1=curr;
        }
       return curr;
    }
};