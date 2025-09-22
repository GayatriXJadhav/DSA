class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int sum=0;
        int maxi=0;
        for(int i=0;i<freq.size();i++){
            maxi=max(maxi,freq[i]);

        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==maxi){
                sum+=freq[i];
            }
        }
        return sum;
    }
};