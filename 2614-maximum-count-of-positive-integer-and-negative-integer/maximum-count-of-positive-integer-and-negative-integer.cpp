class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int pos=0;
        int neg=0;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low + high)/2;
             if(nums[mid]>0){
                high=mid-1;
             }
             else{
                low=mid+1;
             }
        }
        pos=n-low;
         low=0;
        high=n-1;
        while(low<=high){
            int mid=(low + high)/2;
            if(nums[mid]<0){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        neg=high + 1;
        return max(pos,neg);
    }
};