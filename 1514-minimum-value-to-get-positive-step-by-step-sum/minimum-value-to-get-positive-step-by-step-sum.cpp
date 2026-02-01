class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=0, temp=0;
        for(auto i:nums){
            temp+=i;
            ans=min(ans,temp);
        }
        return -ans + 1;
    }
};