class Solution {
public:
    int findX(vector<int>&nums, int mid){
      auto it=lower_bound(nums.begin(),nums.end(),mid);
      int x=nums.end()-it;
      return x;
    }
    int specialArray(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int low=1;
      int high=nums.size();
      while(low<=high){
        int mid=(low + high)/2;
        int ans=findX(nums,mid);
         if(mid==ans){
            return mid;
         }
         else if(mid<ans){
            low=mid+1;
         }
         else{
            high=mid-1;
         }
      }  
      return -1;

    }
};