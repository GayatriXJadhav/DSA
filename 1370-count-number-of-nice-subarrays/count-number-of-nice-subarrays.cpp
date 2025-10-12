class Solution {
public:
 int atmost(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        for (r = 0; r < nums.size(); r++) {

            sum += (nums[r] % 2);
            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }
            cnt = cnt + (r - l + 1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};