class Solution {
public:
  
    int binarySearch(vector<int>&nums){
        long long n=nums.size();
        long long  low=1,high=n/2;
        long long  ans=0;
        vector<int>inc(n,1);
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                inc[i]=inc[i+1] + 1;

            }
            else{
                inc[i]=1;
            }
        }
     


        while(low<=high){
            long long mid=(low + high)/2;
            bool found=false;
            for(int i=0;i<=n-2*mid;i++){
                if(inc[i]>=mid && inc[i + mid]>=mid){ 

                    found=true;
                    break;
                }
               
            }
            if(found){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        long long ans=binarySearch(nums);
        return ans;
    }
};