class Solution {
public:
    bool miniSize(vector<int>& nums, int maxOperations,int mid){
        long long splits=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid){
                splits+=(long long)ceil((double)nums[i]/mid) -1;
            }
            else{
                splits+=0;
            }
        }
        if(splits>maxOperations)return false;
        else return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=(low  + high)/2;
            if(miniSize(nums,maxOperations,mid)==true){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};