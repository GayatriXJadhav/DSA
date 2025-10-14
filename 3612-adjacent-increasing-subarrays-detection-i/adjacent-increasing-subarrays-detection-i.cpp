class Solution {
public:
    bool isStrictlyincreasing(vector<int>& nums, int start,int k){
        for(int i=start;i<start+k-1;i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<=nums.size()-2*k;i++){
            if(isStrictlyincreasing(nums,i,k) && isStrictlyincreasing(nums,i+k,k)){
                return true;
            }
        }
        return false;
    }
};